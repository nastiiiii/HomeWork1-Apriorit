#include "TextReportPrinter.h"

void TextReportPrinter::printReport(std::string &&reportName, const std::vector<FileProperties> &items) const {
    auto file = createFile(std::move(reportName));
    if (file.is_open()) {
        for (const auto &item: items) {
            for (int i = 0; i < static_cast<size_t>(FileProperty::NN); ++i) {
                FileProperty fp = static_cast<FileProperty>(i);
                file << filePropertyToString(fp) << ": " << item.properties[i] << std::endl;
            }
            file << std::endl
                 << "--------------------" << std::endl;
        }
        return;
    }
    throw std::runtime_error("Could not open file");
}


std::string TextReportPrinter::fileExtension() const noexcept {
    return "txt";
}
