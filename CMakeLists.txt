cmake_minimum_required(VERSION 3.26)
project(homework)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(ReportPrinterFactory)
add_subdirectory(Utilities)

add_executable(homework main.cpp)



# Find Boost
find_package(Boost REQUIRED COMPONENTS filesystem)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(homework
                        PUBLIC ${Boost_LIBRARIES}
                        PRIVATE ReportPrinterFactory
                        PRIVATE DirectoryFilesInfoFetcher)