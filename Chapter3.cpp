#include "pch.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    /////////////////// Basic functions ///////////////////

    Mat image1;                 // Input image
    image1 = imread("cat.jpg");
    image1.resize(389, 389);

    // CONVERT COLOR
    /*
    Mat imgGray;                // Output image
    cvtColor(image1, imgGray, COLOR_BGR2GRAY);    // convert to grayscale image
    imshow("Cat gray", imgGray);
    */

    // BLUR IMAGE

    Mat imgBlur, imgCanny1, imgCanny2, imgDilation, imgErosion;
    GaussianBlur(image1, imgBlur, Size(3, 3), 3, 0);
    Canny(imgBlur, imgCanny1, 25, 100);
    Canny(imgBlur, imgCanny2, 10, 200);
    imshow("Cat blur", imgBlur);
    imshow("Cat canny it", imgCanny1);
    imshow("Cat canny nhieu", imgCanny2);

    // THICKNESS 

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny1, imgDilation, kernel);
    imshow("Cat dilation", imgDilation);
    erode(imgDilation, imgErosion, kernel);
    imshow("Cat erosion", imgErosion);
    imshow("Cat", image1);

    waitKey(0); // Wait for a keystroke in the window
    return 0;
}
