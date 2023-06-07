cmake_minimum_required(VERSION 3.26)
project(TextReportPrinter)

set(CMAKE_CXX_STANDARD 11)

add_library(TextReportPrinter INTERFACE)
target_sources(TextReportPrinter INTERFACE TextReportPrinter.cpp)

target_include_directories(TextReportPrinter INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../)