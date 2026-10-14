#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    try {
        // Load the image from file
        Mat image = imread("pngtree-colorful-flowers-corner-decorative-png-clipart-image-png-image_11596999.png");

        if (image.empty()) {
            cerr << "Could not open the PNG image. Make sure it is in the program's working directory."
                 << endl;
            return 1;
        }

        // Convert the image to grayscale
        Mat gray_image;
        cvtColor(image, gray_image, COLOR_BGR2GRAY);

        // Apply Gaussian blur to the image
        Mat blurred_image;
        GaussianBlur(gray_image, blurred_image, Size(5, 5), 0);

        // Apply Canny edge detection to the image
        Mat edges;
        Canny(blurred_image, edges, 50, 150);

        // Save the output image
        if (!imwrite("output.jpg", edges)) {
            cerr << "Could not save output.jpg." << endl;
            return 1;
        }

        // Display the input and output images
        imshow("Input Image", image);
        imshow("Output Image", edges);
        waitKey(0);
    } catch (const Exception& error) {
        cerr << "OpenCV error: " << error.what() << endl;
        return 1;
    }

    return 0;
}