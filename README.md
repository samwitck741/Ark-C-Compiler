# Object Detection in C++ (OpenCV Demo)

This project demonstrates a simple object detection pipeline using **OpenCV** in C++.  
It loads an image, applies edge detection, finds contours, and draws bounding boxes around detected shapes.

## 🚀 Features
- Written in C++17
- Uses OpenCV 4.x
- Detects contours and draws bounding boxes
- Easy to extend with real object detection models (YOLO, SSD, etc.)

## 📦 Build
```bash
g++ object_detection.cpp -o object_detection `pkg-config --cflags --libs opencv4`
