cmake_minimum_required(VERSION 3.26)
project(XmlReportPrinter)

set(CMAKE_CXX_STANDARD 11)

add_library(XmlReportPrinter INTERFACE)
target_sources(XmlReportPrinter INTERFACE XmlReportPrinter.cpp)

target_include_directories(XmlReportPrinter INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})