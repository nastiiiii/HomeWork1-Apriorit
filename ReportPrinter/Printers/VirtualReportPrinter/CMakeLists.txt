cmake_minimum_required(VERSION 3.26)
project(VirtualReportPrinter)

set(CMAKE_CXX_STANDARD 11)

add_library(VirtualReportPrinter INTERFACE)
target_sources(VirtualReportPrinter INTERFACE VirtualReportPrinter.cpp)

target_include_directories(VirtualReportPrinter PUBLIC INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})