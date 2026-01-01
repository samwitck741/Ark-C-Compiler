
---

### 📄 `object_detection.cpp`
```cpp
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./object_detection <image_path>" << std::endl;
        return -1;
    }

    // Load image
    cv::Mat img = cv::imread(argv[1]);
    if (img.empty()) {
        std::cerr << "Could not read the image!" << std::endl;
        return -1;
    }

    // Convert to grayscale
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    // Edge detection
    cv::Mat edges;
    cv::Canny(gray, edges, 100, 200);

    // Find contours
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Draw bounding boxes
    for (size_t i = 0; i < contours.size(); i++) {
        cv::Rect box = cv::boundingRect(contours[i]);
        cv::rectangle(img, box, cv::Scalar(0, 255, 0), 2);
        cv::putText(img, "Object", box.tl(), cv::FONT_HERSHEY_SIMPLEX, 0.5,
                    cv::Scalar(255, 0, 0), 1);
    }

    // Show result
    cv::imshow("Detected Objects", img);
    cv::waitKey(0);

    return 0;
}
