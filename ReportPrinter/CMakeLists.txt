cmake_minimum_required(VERSION 3.26)
project(ReportPrinter)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(Printers/CsvReportPrinter)
add_subdirectory(Printers/TextReportPrinter)
add_subdirectory(Printers/VirtualReportPrinter)
add_subdirectory(Printers/XmlReportPrinter)

add_library(ReportPrinter INTERFACE)
target_sources(ReportPrinter INTERFACE Factory/ReportPrinterFactory.cpp)

target_include_directories(ReportPrinter INTERFACE Factory)
target_link_libraries(ReportPrinter INTERFACE
        CsvReportPrinter
        TextReportPrinter
        VirtualReportPrinter
        XmlReportPrinter)
