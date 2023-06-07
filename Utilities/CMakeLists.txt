cmake_minimum_required(VERSION 3.26)
project(DirectoryFilesInfoFetcher)

set(CMAKE_CXX_STANDARD 11)

add_library(DirectoryFilesInfoFetcher INTERFACE)
target_sources(DirectoryFilesInfoFetcher INTERFACE DirectoryFilesInfoFetcher.cpp)

target_include_directories(DirectoryFilesInfoFetcher INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../)