#include "pch.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    /////////////////// SHOW IMAGE ///////////////////
    
    Mat image1, image2;
    // Read the file
    image1 = imread("cat.jpg"); 
    image1.resize(300, 300);
    image2 = imread("demo.jpg");
    image2.resize(500, 500);
    // Check for invalid input
    if (!image1.data)
    {
        cout << "Could not open/find \"cat\"" << std::endl;
        return -1;
    }
    else cout << "Image dimensions: " << image1.rows << " x " << image1.cols << std::endl;

    if (!image2.data)
    {
        cout << "Could not open/find \"Meme Lord\"" << std::endl;
        return -1;
    }
    else cout << "Image dimensions: " << image2.rows << " x " << image2.cols << std::endl;

    imshow("Cat", image1);               // Show our image inside it.
    imshow("Meme Lord", image2);         // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;


    /////////////////// SHOW VIDEO ///////////////////
    /*
    string path = "Encoder.mp4";
    VideoCapture cap(path);
    Mat img;

    while (true) {
        cap.read(img);
        imshow("Encoder", img);
        waitKey(50);
    }
    */
}

