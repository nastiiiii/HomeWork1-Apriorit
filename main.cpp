#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <ctime>
#include <vector>
#include <memory>

namespace fs = boost::filesystem;

struct ItemProperties {
    std::string name;
    std::string type;
    std::string size;
    std::string creationTime;
    std::string modificationTime;
    std::string lastAccessTime;
};

class ReportPrinter {
public:
    virtual void printReport(const std::vector<ItemProperties>& items) = 0;
    virtual ~ReportPrinter() {}
};

class TextReportPrinter : public ReportPrinter {
public:
    void printReport(const std::vector<ItemProperties>& items) override {
        std::ofstream file("report.txt");
        if (file.is_open()) {
            for (const auto& item : items) {
                file << "Name: " << item.name << std::endl;
                file << "Type: " << item.type << std::endl;
                file << "Size: " << item.size << std::endl;
                file << "Creation Time: " << item.creationTime << std::endl;
                file << "Modification Time: " << item.modificationTime << std::endl;
                file << "Last Access Time: " << item.lastAccessTime << std::endl;
                file << "----------------------------------" << std::endl;
            }
            file.close();
            std::cout << "Text report generated successfully." << std::endl;
        }
        else {
            std::cout << "Error opening file for writing." << std::endl;
        }
    }
};


class CsvReportPrinter : public ReportPrinter {
public:
    void printReport(const std::vector<ItemProperties>& items) override {
        std::ofstream file("report.csv");
        if (file.is_open()) {
            file << "Name,Type,Size,Creation Time,Modification Time,Last Access Time" << std::endl;
            for (const auto& item : items) {
                file << item.name << ",";
                file << item.type << ",";
                file << item.size << ",";
                file << item.creationTime << ",";
                file << item.modificationTime << ",";
                file << item.lastAccessTime << std::endl;
            }
            file.close();
            std::cout << "CSV report generated successfully." << std::endl;
        }
        else {
            std::cout << "Error opening file for writing." << std::endl;
        }
    }
};

class XmlReportPrinter : public ReportPrinter {
public:
    void printReport(const std::vector<ItemProperties>& items) override {
        std::ofstream file("report.xml");
        if (file.is_open()) {
            file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
            file << "<Report>" << std::endl;
            for (const auto& item : items) {
                file << "  <Item>" << std::endl;
                file << "    <Name>" << item.name << "</Name>" << std::endl;
                file << "    <Type>" << item.type << "</Type>" << std::endl;
                file << "    <Size>" << item.size << "</Size>" << std::endl;
                file << "    <CreationTime>" << item.creationTime << "</CreationTime>" << std::endl;
                file << "    <ModificationTime>" << item.modificationTime << "</ModificationTime>" << std::endl;
                file << "    <LastAccessTime>" << item.lastAccessTime << "</LastAccessTime>" << std::endl;
                file << "  </Item>" << std::endl;
            }
            file << "</Report>" << std::endl;
            file.close();
            std::cout << "XML report generated successfully." << std::endl;
        }
        else {
            std::cout << "Error opening file for writing." << std::endl;
        }
    }
};

std::unique_ptr<ReportPrinter> createReportPrinter(const std::string& format) {
    if (format == "txt") {
        return std::unique_ptr<TextReportPrinter>();
    }
    else if (format == "csv") {
        return std::unique_ptr<CsvReportPrinter>();
    }
    else if (format == "xml") {
        return std::unique_ptr<XmlReportPrinter>();
    }
    else {
        return nullptr;
    }
}

void collectFolderContents(const fs::path& folderPath, std::vector<ItemProperties>& items) {
    if (fs::exists(folderPath) && fs::is_directory(folderPath)) {
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            ItemProperties item;
            item.name = entry.path().filename().string();
            item.type = fs::is_directory(entry) ? "Folder" : "File";
            item.size = fs::is_directory(entry) ? "<DIR>" : std::to_string(fs::file_size(entry));

            std::time_t ctime = fs::last_write_time(entry);
            item.creationTime = std::asctime(std::localtime(&ctime));

            std::time_t mtime = fs::last_write_time(entry);
            item.modificationTime = std::asctime(std::localtime(&mtime));

            std::time_t atime = fs::last_write_time(entry);
            item.lastAccessTime = std::asctime(std::localtime(&atime));

            items.push_back(item);

            if (fs::is_directory(entry)) {
                collectFolderContents(entry.path(), items);
            }
        }
    }
}

int main() {
    int s;
    std::string folderPath;
    std::cout << "Enter the full path to the folder: ";
    std::getline(std::cin, folderPath);

    std::vector<ItemProperties> items;
    collectFolderContents(fs::path(folderPath), items);

    std::string format1, format2;
    std::cout << "Enter the first report format (txt, csv, xml): ";
    std::cin >> format1;
    std::cout << "Enter the second report format (txt, csv, xml): ";
    std::cin >> format2;

    std::unique_ptr<ReportPrinter> reportPrinter1 = createReportPrinter(format1);
    std::unique_ptr<ReportPrinter> reportPrinter2 = createReportPrinter(format2);

    if (reportPrinter1 && reportPrinter2) {
        reportPrinter1->printReport(items);
        reportPrinter2->printReport(items);
    }
    else {
        std::cout << "Invalid report format(s) provided." << std::endl;
    }

    return 0;
}