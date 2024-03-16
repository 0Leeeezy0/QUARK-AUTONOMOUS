#include "common.h"

#ifndef _UART_H_
#define _UART_H_

namespace QA   // QUARK-AUTONOMOUS
{
    class QA_UartT
    {
        public:
            void UartSend(QA_Control::Move_Control *Move_Control_p,const char* UartPath);

        private:   
            // 务必放在最上方，否则编译时会有未声明报错
            // 串口发送协议
            typedef struct UART_Send_Protocol
            {
                unsigned char Head_1 = 0xA0;
                unsigned char Head_2 = 0xA3;
                unsigned char Data_1;
                unsigned char Data_2;
                unsigned char Data_3;
                unsigned char Data_4;
                unsigned char Data_5;
                unsigned char Data_6;
                unsigned char Data_7;
                unsigned char Data_8;
                unsigned char CRC16 = 0xB4;
            }UART_Send_Protocol;
            // 串口接收协议
            typedef struct UART_Receive_Protocol
            {
                unsigned char Head_1 = 0xA0;
                unsigned char Head_3 = 0xA0;
                unsigned char Data_1;
                unsigned char Data_2;
                unsigned char Data_3;
                unsigned char Data_4;
                unsigned char Data_5;
                unsigned char Data_6;
                unsigned char Data_7;
                unsigned char Data_8;
                unsigned char CRC16 = 0xB4;
            }UART_Receive_Protocol;

            // 串口发送信息同步
            void UartSend_SYNC(UART_Send_Protocol *UART_Send_Protocol_p,QA_Control::Move_Control *Move_Control_p);
    };
}


class WzSerialPort
{
public:
    WzSerialPort();
    ~WzSerialPort();

    // 打开串口,成功返回true，失败返回false
    // portname(串口名): 在Windows下是"COM1""COM2"等，在Linux下是"/dev/ttyS1"等
    // baudrate(波特率): 9600、19200、38400、43000、56000、57600、115200 
    // parity(校验位): 0为无校验，1为奇校验，2为偶校验，3为标记校验（仅适用于windows)
    // databit(数据位): 4-8(windows),5-8(linux)，通常为8位
    // stopbit(停止位): 1为1位停止位，2为2位停止位,3为1.5位停止位
    // loaclmode(模式): 1为规范输入模式，2为原始输入模式
    // synchronizeflag(同步、异步,仅适用与windows): 0为异步，1为同步
    bool open(const char* portname, int baudrate, char parity, char databit, char stopbit, char loaclmode, char synchronizeflag=1);


    //关闭串口，参数待定
    void close();

    //发送数据或写数据，成功返回发送数据长度，失败返回0
    int send(const void *buf,int len);

    //接受数据或读数据，成功返回读取实际数据的长度，失败返回0
    int receive(void *buf,int maxlen);

private:
    int pHandle[16];
    char synchronizeflag;
};

#endif