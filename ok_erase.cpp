#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

int main()
{
    cv::Mat mat(100, 100, CV_32FC1);
    int x;
    int y;
    for (y = 0; y < mat.rows; y += 1)
    {
        for (x = 0; x < mat.cols; x += 1)
        {
            mat.at<float>(x, y) = 0.5005;
        }
    }

    return 0;
}