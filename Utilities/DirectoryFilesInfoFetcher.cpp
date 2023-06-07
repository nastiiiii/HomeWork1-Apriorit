#include "DirectoryFilesInfoFetcher.h"
#include "FileProperties.h"
#include <ctime>
#include <iostream>

namespace fs = boost::filesystem;

namespace {

    std::string formatWithoutNewLine(std::time_t &time) {
        char timeLength[100];
        std::strftime(timeLength, sizeof(timeLength), "%c", std::localtime(&time));
        return std::move(timeLength);
    }

    void collectFolderContentsInternal(const boost::filesystem::path &folderPath, std::vector<FileProperties> &res) {
        if (fs::exists(folderPath) && fs::is_directory(folderPath)) {
            for (const auto &file: fs::directory_iterator(folderPath)) {
                FileProperties item;
                std::cout << (file.path()) << std::endl;
                item.properties[static_cast<size_t>(FileProperty::NAME)] = file.path().filename().string();

                item.properties[static_cast<size_t>(FileProperty::TYPE)] = fs::is_directory(file) ? "Folder" : "File";

                item.properties[static_cast<size_t>(FileProperty::SIZE)] = fs::is_directory(file) ? "<DIR>" : std::to_string(fs::file_size(file));

                std::time_t ctime = fs::creation_time(file);
                item.properties[static_cast<size_t>(FileProperty::CREATION_TIME)] = formatWithoutNewLine(ctime);

                std::time_t mtime = fs::last_write_time(file);
                item.properties[static_cast<size_t>(FileProperty::MODIFICATION_TIME)] = formatWithoutNewLine(mtime);

                const bool readOnly = (fs::status(file.path()).permissions() & fs::perms::owner_write) == fs::perms::no_perms;
                item.properties[static_cast<size_t>(FileProperty::PERMISSION)] = readOnly ? "Read-Only" : "Not Read-Only";

                item.properties[static_cast<size_t>(FileProperty::EXTENSION)] = file.path().extension().string();

                res.push_back(std::move(item));

                if (fs::is_directory(file)) {
                    collectFolderContentsInternal(file.path(), res);
                }
            }
        }
    }
}// namespace

std::vector<FileProperties> utils::collectFolderContents(const boost::filesystem::path &folderPath) {
    std::vector<FileProperties> res;

    if (!fs::exists(folderPath)) {
        throw std::runtime_error("Folder path does not exist " + folderPath.string());
    }
    if (!fs::is_directory(folderPath)) {
        throw std::runtime_error("Folder path is not a directory " + folderPath.string());
    }
    collectFolderContentsInternal(folderPath, res);
    std::cout << res.size() << std::endl;
    return res;
}