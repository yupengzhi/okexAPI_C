project(okexCurl)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -w -std=c++11  -fpermissive ")
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

link_directories(/usr/lib/x86_64-linux-gnu)

add_library(okexCurl ${DIR_SRCS})
TARGET_LINK_LIBRARIES(okexAPI libcurl.so libcrypto.so)
