
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
    cv::Mat img = cv::imread("your_image_path");

    if (img.empty())
    {
        std::cerr << "Image Not Find!" << std::endl;
        return -1;
    }

    // Renkli görüntüyü göster
    cv::namedWindow("Raw");
    cv::imshow("Raw", img);

    // Görüntüyü gri tonlamaya çevir
    cv::Mat imgGrayScale;
    cv::cvtColor(img, imgGrayScale, cv::COLOR_BGR2GRAY);

    // Gri tonlamalı görüntüyü göster
    cv::namedWindow("Gray");
    cv::imshow("Gray", imgGrayScale);

    // Gri tonlamalı görüntü üzerinde eşikleme yap
    cv::threshold(imgGrayScale, imgGrayScale, 128, 255, cv::THRESH_BINARY);

    // Renkli görüntü üzerinde konturları bul
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(imgGrayScale, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);

    // Renkli görüntü üzerinde konturları çiz
    for (size_t i = 0; i < contours.size(); ++i)
    {
        cv::drawContours(img, contours, static_cast<int>(i), cv::Scalar(0, 255, 0), 2);
    }

    // Çevrelenmiş renkli görüntüyü göster
    cv::namedWindow("Tracked");
    cv::imshow("Tracked", img);

    cv::waitKey(0); // Bir tuşa basılmasını bekle

    cv::destroyAllWindows(); // Pencereleri kapat

    return 0;
}

