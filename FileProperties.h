#pragma once
#include <array>
#include <string>

enum class FileProperty : size_t {
    NAME,
    TYPE,
    SIZE,
    CREATION_TIME,
    MODIFICATION_TIME,
    PERMISSION,
    EXTENSION,
    NN
};


struct FileProperties {
    std::array<std::string, static_cast<size_t>(FileProperty::NN)> properties;
};

inline std::string filePropertyToString(FileProperty fileProperty) {
    switch (fileProperty) {
        case FileProperty::NAME:
            return "Name";
        case FileProperty::TYPE:
            return "Type";
        case FileProperty::SIZE:
            return "Size";
        case FileProperty::CREATION_TIME:
            return "Creation time";
        case FileProperty::MODIFICATION_TIME:
            return "Modification time";
        case FileProperty::PERMISSION:
            return "Permission";
        case FileProperty::EXTENSION:
            return "Extension";
    }
    throw std::runtime_error("Unexpected file property");
}
