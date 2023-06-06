cmake_minimum_required(VERSION 3.26)
project(ReportPrinterFactory)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(Printers/CsvReportPrinter)
add_subdirectory(Printers/TextReportPrinter)
add_subdirectory(Printers/VirtualReportPrinter)
add_subdirectory(Printers/XmlReportPrinter)

add_library(ReportPrinterFactory INTERFACE)
target_sources(ReportPrinterFactory INTERFACE ReportPrinterFactory.cpp)

target_include_directories(ReportPrinterFactory INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ReportPrinterFactory INTERFACE CsvReportPrinter
        TextReportPrinter
        VirtualReportPrinter
        XmlReportPrinter)
