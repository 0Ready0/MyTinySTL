cmake_minimum_required(VERSION 3.10)    
# 声明此项目所需的 CMake 最低版本。如果当前 CMake 版本低于 3.10，会发出警告并尝试兼容模式运行

project(MYTINSTL)
# 设置项目名称，并定义一系列变量：
# PROJECT_SOURCE_DIR 项目的源目录
# PROJECT_BINARY_DIR 项目的二进制目录
# CMAKE_PROJECT_NAME 项目的名称
# CMAKE_CXX_COMPILER C++ 编译器
# CMAKE_CXX_FLAGS C++ 编译选项
# CMAKE_CXX_FLAGS_DEBUG C++ 调试编译选项
# CMAKE_CXX_FLAGS_RELEASE C++ 发布编译选项

# 注意：项目名称通常建议使用驼峰命名或小写，但大小写不影响功能。

file(GLOB SRC_FILES 
    "${PROJECT_SOURCE_DIR}/include/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.cpp")

# 作用：使用 GLOB 将匹配通配符的文件列表收集到变量 SRC_FILES 中。
# 参数：
# GLOB 匹配模式
# ${PROJECT_SOURCE_DIR}/src/*.h 匹配项目源目录下的所有 .h 文件
# ${PROJECT_SOURCE_DIR}/src/*.cpp 匹配项目源目录下的所有 .cpp 文件

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})
# 创建可执行文件目标，目标名是 CMAKE_PROJECT_NAME 的值（即 MYTINSTL）
# 参数：
# ${CMAKE_PROJECT_NAME} 目标名
# ${SRC_FILES} 源文件列表

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)
# 添加头文件目录，将 include 目录添加到 MYTINSTL 目标的私有头文件目录中。
