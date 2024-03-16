#include "common.h"

using namespace std;
using namespace cv;
using namespace QA;

// 摄像头初始化
VideoCapture QA_Camera::CameraInit(const char* CameraPath)
{
    VideoCapture Camera;
    Camera.open(CameraPath);
    // if(!Camera.isOpened())
    return Camera;
}


// 摄像头图像获取
Mat QA_Camera::CameraImg_Get(VideoCapture Camera)
{
    Mat Img;
    Camera >> Img;   // 将视频流转为图像流
    return Img;
}


