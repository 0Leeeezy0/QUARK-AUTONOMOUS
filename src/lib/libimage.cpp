#include "common.h"

using namespace std;
using namespace cv;
using namespace QA;

// 彩色图像灰度化
void QA_Image::ImgGray(Mat& Img)
{
	cvtColor(Img , Img , COLOR_BGR2GRAY);  //彩色图像灰度化
}


// 灰度图像二值化
void QA_Image::ImgMono(Mat& Img)
{
	threshold(Img , Img , 0 , 255 , THRESH_BINARY | THRESH_OTSU);   //灰度图像二值化
}


// 图像通道提取
Mat QA_Image::ImgChannel(Mat Img,RGB_Channel RGB_Channel)
{
	vector<Mat> Channel;
	Mat RGB_Img;
	split(Img,Channel);
	switch(RGB_Channel)
	{
		case R_Channel:{ Channel[0] = Scalar(0); Channel[1] = Scalar(0); break;}
		case G_Channel:{ Channel[0] = Scalar(0); Channel[2] = Scalar(0); break;}
		case B_Channel:{ Channel[1] = Scalar(0); Channel[2] = Scalar(0); break;}
	}

	merge(Channel,RGB_Img);
	return RGB_Img;
}

// SOBEL算子边缘检测
void QA_Image::ImgSobel(Mat& Img)
{
	Mat ImgX;
	Mat ImgY;

	//对X方向微分
    Sobel(Img,ImgX,CV_16S,1,0,5); 	//x方向差分阶数 y方向差分阶数 核大小  
    convertScaleAbs(ImgX,ImgX);     //可将任意类型的数据转化为CV_8UC1
	//对Y方向微分
	Sobel(Img,ImgY,CV_16S,0,1,5); 	//x方向差分阶数 y方向差分阶数 核大小  
    convertScaleAbs(ImgY,ImgY);     //将任意类型的图像转化为CV_8UC1

    addWeighted(ImgX,0.5,ImgY,0.5,0,Img);	//图像的线性混合
}


// SCHARR算子边缘检测
void QA_Image::ImgScharr(Mat& Img)
{
	Mat ImgX;
	Mat ImgY;

	//对X方向微分
    Scharr(Img,ImgX,CV_16S,1,0,3); 	//x方向差分阶数 y方向差分阶数 核大小  
    convertScaleAbs(ImgX,ImgX);     //可将任意类型的数据转化为CV_8UC1
	//对Y方向微分
	Scharr(Img,ImgY,CV_16S,1,0,3); 	//x方向差分阶数 y方向差分阶数 核大小  
    convertScaleAbs(ImgY,ImgY);     //将任意类型的图像转化为CV_8UC1

    addWeighted(ImgX,0.5,ImgY,0.5,0,Img);	//图像的线性混合
}


// 图像锐化
void QA_Image::ImgSharpen(Mat &Img,int blursize = 5)
{
	Mat Img_Gauss;
	GaussianBlur(Img,Img_Gauss,Size(blursize,blursize),3,3);
	addWeighted(Img,2,Img_Gauss,-1,0,Img);
}


// 透视变换
Mat QA_Image::ImgUnpivot(Mat Img,Mat& Img_Unpivot,Point2f *SrcPoints,Point2f *DstPoints)
{
    // 示例
    // Point2f SrcPoints[] = { 
	// 	Point2f(0,240),
	// 	Point2f(320,240),
	// 	Point2f(115,25),
	// 	Point2f(205,25) };
 
	// Point2f DstPoints[] = {
	// 	Point2f(80,240),
	// 	Point2f(240,240),
	// 	Point2f(80,0),
	// 	Point2f(240,0) };
 
	Mat UnpivotMat = getPerspectiveTransform(SrcPoints , DstPoints);

    warpPerspective(Img,Img_Unpivot,UnpivotMat,Size(320,240),INTER_LINEAR);
    return Img_Unpivot;
}


// 图像存储
void QA_Image::ImgSave(Mat Img,const char* ImgSave_Path,int ImgNum,ImgFormat ImgFormat)
{
    string ImgSavePath;
    switch(ImgFormat)
    {
        case JPG:{ ImgSavePath = ImgSave_Path + to_string(ImgNum) + ".jpg"; break; }
        case JPEG:{ ImgSavePath = ImgSave_Path + to_string(ImgNum) + ".jpeg"; break; }
        case PNG:{ ImgSavePath = ImgSave_Path + to_string(ImgNum) + ".png"; break; }
    }
	//建立一个字符串用于存储图片存储路径
	//使用字符串定义图片存储路径
	//必须要加后缀 否则编译会报错

	imwrite(ImgSavePath , Img);
	//存储图片流
}


// 图像压缩
// Mat libImage::ImgCompress(Mat& Img)
// {
// 	Mat ImgCompress;
//     Size size = Size(320,240);
//     resize(Img,ImgCompress,size,0,0,INTER_AREA);
//     //将图像压缩为320*240大小
//     Img = ImgCompress;
// }

