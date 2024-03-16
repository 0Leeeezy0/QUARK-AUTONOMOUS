#include "common.h"

using namespace std;
using namespace cv;
using namespace QA;

int main()
{
    // 类定义
    Mat Img;
    QA_Camera QA_Camera;
    QA_Image QA_Image;
    QA_Control QA_Control;
    QA_UartT QA_Uart;

    VideoCapture Camera =  QA_Camera.CameraInit("/dev/video0");

    Mat T_R,T_G,T_B;
    Mat A;

    while(true)
    {
        Img = QA_Camera.CameraImg_Get(Camera);

        // QA_Image.ImgGray(Img);
        // QA_Image.ImgMono(Img);
        // QA_Image.ImgSobel(Img);

        T_R = QA_Image.ImgChannel(Img,QA_Image.R_Channel);
        T_G = QA_Image.ImgChannel(Img,QA_Image.G_Channel);
        T_B = QA_Image.ImgChannel(Img,QA_Image.B_Channel);

        QA_Image.ImgGray(T_R);
        QA_Image.ImgGray(T_G);
        QA_Image.ImgGray(T_B);

        QA_Image.ImgMono(T_R);
        QA_Image.ImgMono(T_G);
        QA_Image.ImgMono(T_B);

        merge(T_R,A);

        imshow("as",T_R);

        // imshow("demo",Img);

        // QA_Control.Move_Control_p -> Move_Forward = 100;
        // QA_Control.Move_Control_p -> Move_Back = 0;
        // QA_Control.Move_Control_p -> Move_Left = 100;
        // QA_Control.Move_Control_p -> Move_Right = 0;
        // QA_Control.Move_Control_p -> Rotate_Left = 100;
        // QA_Control.Move_Control_p -> Move_Right = 0;
        // QA_Control.Move_Control_p -> Move_Up = 10;
        // QA_Control.Move_Control_p -> Move_Down = 0;

        // QA_Uart.UartSend(QA_Control.Move_Control_p,"/dev/ttyFIQ0");    // ttyFIQ0为泰山派的调试串口

        waitKey(1);
    }

    return 0;
}