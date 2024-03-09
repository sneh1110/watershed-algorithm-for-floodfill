
# Modified Flood Fill Algorithm to process DEM raster image used in GIS (shows the flow of water).

I've developed a specialized flood-fill algorithm tailored for raster images of elevation cells. The algorithm serves a dual purpose: first, it scales the input dark image of elevation cells to generate a grayscale representation. This scaling is crucial for obtaining a clearer picture of the terrain. The subsequent stage of the algorithm refines this grayscale image, honing in on the identification of water flow patterns.

Usage:

![App Screenshot](https://raw.githubusercontent.com/RinkeshKumarSinha/watershed-algo/main/ConsoleApplication1/test%20results%20packed/Results.gif)

The flood-fill approach is particularly effective in this context, as it systematically analyzes each pixel's elevation values in relation to its neighbors. By traversing the image and adjusting pixel values based on elevation disparities, the algorithm creates a more accurate depiction of the terrain's topography. This not only aids in visualizing elevation differences but also lays the foundation for identifying potential paths of water flow.
## Screenshots

![App Screenshot](https://raw.githubusercontent.com/RinkeshKumarSinha/watershed-algo/main/ConsoleApplication1/test%20results%20packed/inputImage.PNG)

 GrayScaled Output

![App Screenshot](https://raw.githubusercontent.com/RinkeshKumarSinha/watershed-algo/main/ConsoleApplication1/test%20results%20packed/grayScaled.PNG)

Coloured Output

![App Screenshot](https://raw.githubusercontent.com/RinkeshKumarSinha/watershed-algo/main/ConsoleApplication1/test%20results%20packed/Coloured.PNG)

Algorithmic Approach
The grayscale output of the algorithm provides a detailed representation of elevation variations, where lighter shades signify higher elevations and darker shades correspond to lower elevations. The refined image is not only visually informative but also serves as a basis for subsequent analysis.

![App Screenshot](https://raw.githubusercontent.com/RinkeshKumarSinha/watershed-algo/main/ConsoleApplication1/test%20results%20packed/input2.PNG)

To enhance the interpretability of the results, the algorithm produces both grayscale and colorized representations of the processed image. The grayscale version maintains a nuanced portrayal of elevation differences, while the colorized version employs a gradient mapping technique.
 
![App Screenshot](https://raw.githubusercontent.com/RinkeshKumarSinha/watershed-algo/main/ConsoleApplication1/test%20results%20packed/op2%20coloured.PNG)

The inner grid is having elevation of 255 which is a pit 
the outer grid is having elevation of 240 then 200 then 150 and 100.
so the pits are bordered and the colours dipict the 8 different directions.

This mapping assigns distinct colors to specific elevation ranges, aiding in the quick and intuitive identification of elevation levels.

This innovative flood-fill algorithm is a valuable tool for terrain analysis, hydrology, and related fields. Its ability to transform raw elevation data into visually compelling representations facilitates a deeper understanding of the landscape and supports the identification of potential water flow paths. The algorithm's versatility makes it suitable for a wide range of applications, from environmental monitoring to landscape modeling and beyond.

