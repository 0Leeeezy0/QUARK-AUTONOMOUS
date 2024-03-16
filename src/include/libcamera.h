#include "common.h"

#ifndef _CAMERA_H_
#define _CAMERA_H_

namespace QA   // QUARK-AUTONOMOUS
{
    class QA_Camera
    {
        public:
            // 摄像头初始化
            cv::VideoCapture CameraInit(const char* CameraPath);

            // 摄像头图像获取
            cv::Mat CameraImg_Get(cv::VideoCapture Camera);

        private:

    };
}

#endif