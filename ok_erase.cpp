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

void make_heatmap(
    cv::Mat img,
    cv::Mat heatmap)
{
    float value;
    int pix_value;
    double maxVal;
    cv::minMaxLoc(img, NULL, maxVal, NULL, NULL);
    float cof = 255 / maxVal;
    for (int y = 0; y < img.rows; y += 1)
    {
        for (int x = 0; x < img.cols; x += 1)
        {
            if (x != 0 && y != 0 && x != img.rows && y != img.cols)
            {
                value = img.at<float>(x, y);
                pix_value = (int)(cof * value);
            }
            else
            {
                pix_value = 125;
            }

            heatmap.at<unsigned char>(x, y)[0] = pix_value;
            heatmap.at<unsigned char>(x, y)[1] = pix_value;
            heatmap.at<unsigned char>(x, y)[2] = pix_value;
        }
    }
}