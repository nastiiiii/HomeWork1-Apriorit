#pragma once
#include <boost/filesystem.hpp>
#include <vector>
struct FileProperties;

namespace utils {
    std::vector<FileProperties> collectFolderContents(const boost::filesystem::path &folderPath);
}