cmake_minimum_required(VERSION 3.26)
project(homework)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(ReportPrinter)
add_subdirectory(Utilities)

add_executable(homework main.cpp)

# Find Boost
find_package(Boost REQUIRED COMPONENTS filesystem)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(homework
                        PUBLIC ${Boost_LIBRARIES}
                        PRIVATE ReportPrinter
                        PRIVATE DirectoryFilesInfoFetcher)

target_include_directories(homework INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})