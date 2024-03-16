# CMake版本要求
cmake_minimum_required(VERSION 3.5)

# 工程名字
project(QA.run)

#OpenCV
find_package(OpenCV REQUIRED)    
include_directories( ${OpenCV_INCLUDE_DIRS} )

#引入头文件
include_directories(./include)  # 第三方库头文件
include_directories(./src/include)  # 工程头文件

#编译时所需源文件
add_executable(${PROJECT_NAME}  ./src/src/demo.cpp
                                ./src/lib/libcamera.cpp
                                ./src/lib/libcontrol.cpp
                                ./src/lib/libimage.cpp
                                ./src/lib/libmodel.cpp
                                ./src/lib/libuart.cpp)

#OpenCV与工程链接
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})
