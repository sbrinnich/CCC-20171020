cmake_minimum_required(VERSION 3.8)
project(20171020)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Account.cpp Account.h Transaction.cpp Transaction.h InputElement.cpp InputElement.h OutputElement.cpp OutputElement.h)
add_executable(20171020 ${SOURCE_FILES})