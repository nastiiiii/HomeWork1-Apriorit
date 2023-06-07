cmake_minimum_required(VERSION 3.26)
project(CsvReportPrinter)

set(CMAKE_CXX_STANDARD 11)

add_library(CsvReportPrinter INTERFACE)
target_sources(CsvReportPrinter INTERFACE CsvReportPrinter.cpp)

target_include_directories(CsvReportPrinter INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../)