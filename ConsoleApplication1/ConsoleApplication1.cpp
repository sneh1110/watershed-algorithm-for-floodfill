//backup

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;



#include <iostream>
//#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
#include <unordered_map>
#include <deque>
#include <list>
#include <map>

struct load {
	int x;
	int y;
	int ele;
	load(int x, int y, int ele) {
		this->x = x;
		this->y = y;
		this->ele = ele;
	}
};

struct myCmp {
	bool operator()(load* it1, load* it2) {
		return it1->ele < it2->ele;
	}
};


		


void findSteepest(int r, int c, int nrow, int ncol, vector<vector<int>>& grid, int& dir, pair<pair<double, int>, pair<int, int>>& pr) {
	double prev = pr.first.first;
	if (grid[nrow][ncol] <= grid[r][c]) {
		double num = grid[r][c] - grid[nrow][ncol];
		double dem = 1.00;
		if ((dir == 0) || (dir == 2) || (dir == 4) || (dir == 6)) {
			dem = 1.00;
		}
		else dem = 1.41;
		double temp = num / dem;
		if ((temp) > prev)pr = { {temp, dir}, {nrow, ncol} };
	}
	return;
}

bool isValid(int nrow, int ncol, int m, int n) {
	return (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n);
}


void checkResult() {
	
	// Read the image file with IMREAD_ANYDEPTH flag
	Mat image = cv::imread("C:/Users/KIIT/source/repos/ConsoleApplication1/ConsoleApplication1/test1.tif", cv::IMREAD_ANYDEPTH);

	if (image.empty()) // Check for failure
	{
		cout << "Could not open or find the image" << endl;
		system("pause"); // Wait for any key press
		return;
	}

	int rows = image.rows;
	int cols = image.cols;
	cout << "Rows and cols:" << endl;
	cout << rows << " " << cols << endl;
	cout << endl;

	vector<vector<int>> inputImage;

	// Access and print pixel values
	int mini = +1e9;
	int maxi = -1e9;
	//  r1 = 3000
	   //   c1 = 0
		 // r2 = 5999
		  //c2 = 2999
	//400-800
	for (int i = 0; i < rows; ++i) {
		vector<int> temp;
		for (int j = 0; j < cols; ++j) {
			int pixel_value = static_cast<int>(image.at<ushort>(i, j)); // Use ushort for 16-bit TIFF
			//if (pixel_value <= 100)temp.push_back(100);
			//else if (pixel_value >= 400)temp.push_back(400);
			//else temp.push_back(pixel_value);
			temp.push_back(pixel_value);

		}
		inputImage.push_back(temp);
	}

	for (int i = 0;i < inputImage.size();++i) {
		for (int j = 0;j < inputImage[0].size();++j) {
			mini = min(mini, inputImage[i][j]);
			maxi = max(maxi, inputImage[i][j]);
		}
	}
	cout << mini << " " << maxi << endl;



	cout << "Min and Max values: " << mini << " " << maxi << endl;
	cout << endl;

	vector<vector<int>> vec(rows, vector<int>(cols, 0));

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			//vec[i][j] = ((inputImage[i][j] - mini) / static_cast<double>(maxi - mini)) * 255;
			vec[i][j] = inputImage[i][j];
		}
	}

	cv::Mat imageMat(vec.size(), vec[0].size(), CV_8UC1);

	for (int i = 0; i < imageMat.rows; ++i) {
		for (int j = 0; j < imageMat.cols; ++j) {
			imageMat.at<uchar>(i, j) = static_cast<uchar>(vec[i][j]);
		}
	}

	cv::imshow("Image", imageMat);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return;
}

void showGrayScale(vector<vector<int>>&fill,int m,int n,int mini,int maxi) {
	vector<vector<int>> vec(m, vector<int>(n, 0));

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			vec[i][j] = ((fill[i][j] - mini) / static_cast<double>(maxi - mini)) * 255;
			
		}
	}

	cv::Mat imageMat(vec.size(), vec[0].size(), CV_8UC1);

	for (int i = 0; i < imageMat.rows; ++i) {
		for (int j = 0; j < imageMat.cols; ++j) {
			imageMat.at<uchar>(i, j) = static_cast<uchar>(vec[i][j]);
		}
	}

	cv::imshow("Image", imageMat);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return;
}
void algorithm(vector<vector<int>>& grid, int m, int n) {
	vector<vector<int>>vis(m, vector<int>(n, 0));

	priority_queue<load*, vector<load*>, myCmp>pq;


	int left, right, top, bottom;
	left = top = 0;
	right = m - 1;
	bottom = n - 1;
	//int k = 1;
	
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			load* edges = new load(i, j, grid[i][j]);
			pq.push(edges);
		}
	}







	int delrow[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int delcol[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	vector<vector<int>>fill(m, vector<int>(n, -1));

	while (!pq.empty()) {
		
		auto node = pq.top();
		pq.pop();
	

		int ele = node->ele;
		int r = node->x;
		int c = node->y;
		pair<pair<double, int>, pair<int, int>>pr = { {0.00, -1}, { -1, -1} };
		int dir = -1;
		for (int i = 0; i < 8; i++) {
			int nrow = r + delrow[i];
			int ncol = c + delcol[i];
			if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n) {
				findSteepest(r, c, nrow, ncol, grid, i, pr);
			}
		}
		if (pr.second.first != -1 && pr.second.second != -1) {
			fill[r][c] = pow(2, pr.first.second);
		}
	}

	int mini = +1e9;
	int maxi = -1e9;

	//cout << fill[0][2];
	for (int i = 0;i < fill.size();++i) {
		for (int j = 0;j < fill[0].size();++j) {
			mini = min(mini, fill[i][j]);
			maxi = max(maxi, fill[i][j]);
		}
	}
	cout << mini << " " << maxi << endl;
	for (int i = 0;i < 10;++i) {
		for (int j = 0;j < 10;++j) {
			cout << fill[i][j] << " ";
		}
		cout << endl;
	}

	//complete->dfs(fill);
	
	

	int rows = fill.size();
	int cols = fill[0].size();
	cv::Mat image(rows, cols, CV_8UC3);


	
	showGrayScale(fill, m, n, mini, maxi);
	// Assign colors based on values
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			int value = fill[i][j];
			if (value == -1)        image.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 0, 0);       // Black
			else if (value == 1)    image.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 0, 255);     // Red
			else if (value == 2)    image.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 255, 0);     // Green
			else if (value == 4)    image.at<cv::Vec3b>(i, j) = cv::Vec3b(255, 0, 0);     // Blue
			else if (value == 8)    image.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 255, 255);   // Yellow
			else if (value == 16)   image.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 128, 255);   // Orange
			else if (value == 32)   image.at<cv::Vec3b>(i, j) = cv::Vec3b(255, 0, 255);   // Purple
			else if (value == 64)   image.at<cv::Vec3b>(i, j) = cv::Vec3b(255, 128, 0);   // Pink
			else if (value == 128)  image.at<cv::Vec3b>(i, j) = cv::Vec3b(255, 255, 255); // White
		}
	}

	// Display the image
	cv::imshow("Colored Image", image);
	cv::waitKey(0);

	

	

	return;
}


int main(int argc, char** argv)
{
	// Read the image file with IMREAD_ANYDEPTH flag
	Mat image = cv::imread("C:/Users/KIIT/source/repos/ConsoleApplication1/ConsoleApplication1/test1.tif", cv::IMREAD_ANYDEPTH);

	if (image.empty()) // Check for failure
	{
		cout << "Could not open or find the image" << endl;
		system("pause"); // Wait for any key press
		return -1;
	}

	int rows = image.rows;
	int cols = image.cols;
	cout << "Rows and cols:" << endl;
	cout << rows << " " << cols << endl;
	cout << endl;


	vector<vector<int>>temp;
	for (int i = 0; i < rows; ++i) {
		vector<int> temp1;
		for (int j = 0; j < cols; ++j) {
			int pixel_value = static_cast<int>(image.at<ushort>(i, j)); // Use ushort for 16-bit TIFF
			temp1.push_back(pixel_value);


		}
		temp.push_back(temp1);
	}
	cout << "Few Entries of the raster image: "<<endl;
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


	cout << "Press 1 to see the processed Raster image's Grayscaled view: " << endl;
	cout << "Press 2 to see the modified Flood Fill algo on the Raster image: " << endl;
	
	int n;
	cin >> n;
	if (n == 1) {
		checkResult();
	}

	else if (n == 2) {
		cout << "Wait this will take a few minutes.The Results will be available soon have patience." << endl;
		algorithm(temp, temp.size(), temp[0].size());
	}

	else cout << "run the program again ! wrong key pressed." << endl;





















	return 0;
}



