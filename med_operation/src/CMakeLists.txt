cmake_minimum_required(VERSION 3.29)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(med_operation main.cpp ${INCLUDE_DIR}/instruments.h)
target_include_directories(med_operation PUBLIC ${INCLUDE_DIR})