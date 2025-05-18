cmake_minimum_required(VERSION 3.29)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SRC_LIST cpu.cpp disk.cpp gpu.cpp kbd.cpp ram.cpp main.cpp)

add_executable(computer ${SRC_LIST} ${INCLUDE_DIR})
target_include_directories(computer PUBLIC ${INCLUDE_DIR})