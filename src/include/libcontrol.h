#ifndef _CONTROL_H_
#define _CONTROL_H_

namespace QA   // QUARK-AUTONOMOUS
{
    class QA_Control
    {
        public:
            // 务必放在最上方，否则编译时会有未声明报错
            // 运动控制信息
            typedef struct Move_Control
            {
                int Move_Forward; // 前进率
                int Move_Back;    // 后退率
                int Move_Left;    // 左飞率
                int Move_Right;   // 右飞率
                int Rotate_Left;  //左旋转率
                int Rotate_Right; // 右旋转率
                int Move_Up;  // 上升率
                int Move_Down;    // 下降率
            }Move_Control;

            Move_Control Move_Control_c;
            Move_Control* Move_Control_p = &Move_Control_c;

        private:
    };
}

// using Move_Control = QA::Control::Move_Control;  // 使其他地方的非Control类也可以使用Move_Control结构体

#endif