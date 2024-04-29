cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
# 设置项目名称
project(multithreading)

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_library(ThreadPool SHARED ThreadPool.cpp ThreadPool.h)
add_executable(multithreading main.cpp)
target_link_libraries(multithreading ThreadPool)
# add_executable(main1 main.cpp ThreadPool.cpp ThreadPool.h)
# add_executable(main2 main2.cpp)
# 对Windows进行特定配置
if(WIN32)
  # 定义宏，通常用于导出DLL符号
  target_compile_definitions(ThreadPool PRIVATE THREADPOOL_EXPORTS)
endif()

# 添加依赖库