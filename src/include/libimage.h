#include "common.h"

#ifndef _IMAGE_H_
#define _IMAGE_H_

namespace QA   // QUARK-AUTONOMOUS
{
    class QA_Image
    {
        public:
            typedef enum ImgFormat
            {
                JPG = 0,
                JPEG = 1,
                PNG = 2
            }ImgFormat;

            typedef enum RGB_Channel
            {
                R_Channel = 0, // R通道
                G_Channel = 1,  // G通道
                B_Channel = 2   // B通道
            }RGB_Channel;

            // 彩色图像灰度化
            void ImgGray(cv::Mat& Img);

            // 灰度图像二值化
            void ImgMono(cv::Mat& Img);

            // 图像通道提取
            cv::Mat ImgChannel(cv::Mat Img,RGB_Channel RGB_Channel);

            // SOBEL算子边缘检测
            void ImgSobel(cv::Mat& Img);

            // SCHARR算子边缘检测
            void ImgScharr(cv::Mat& Img);

            // 图像锐化
            void ImgSharpen(cv::Mat &Img,int blursize);

            // 透视变换
            cv::Mat ImgUnpivot(cv::Mat Img,cv::Mat& Img_Unpivot,cv::Point2f *SrcPoints,cv::Point2f *DstPoints);

            // 图像存储
            void ImgSave(cv::Mat Img,const char* ImgSave_Path,int ImgNum,ImgFormat ImgFormat);
            
        private:
    };
};

#endif