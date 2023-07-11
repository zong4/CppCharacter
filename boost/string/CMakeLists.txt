cmake_minimum_required(VERSION 3.20)
project(geometry)

set(CMAKE_CXX_STANDARD 20)

# 设置输出路径，dll和exe必须在同一目录，否则运行时无法继续执行
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

file(GLOB SRC
       ${PROJECT_SOURCE_DIR}/*.cpp)

message(">>> SRC=${SRC}")

add_executable(${PROJECT_NAME} ${SRC})

#add_subdirectory(test)

# boost
set(Boost_INCLUDE_DIR "C:\\Boost\\boost_1_81_0")
set(Boost_LIBRARY_DIRS "C:\\Boost\\boost_1_81_0\\libs")
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

