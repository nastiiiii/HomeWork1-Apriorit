#include "CsvReportPrinter.h"
#include <iomanip>

void CsvReportPrinter::printReport(std::string &&reportName, const std::vector<FileProperties> &items) const {
    auto file = createFile(std::move(reportName));
    if (file.is_open()) {

        for (int i = 0; i < static_cast<size_t>(FileProperty::NN); ++i) {
            FileProperty fp = static_cast<FileProperty>(i);
            file << filePropertyToString(fp) << ";";
        }

        file << std::endl;

        for (const auto &item: items) {
            for (int i = 0; i < static_cast<size_t>(FileProperty::NN); ++i) {
                file << item.properties[i] << ";";
            }
            file << std::endl;
        }
        file.close();
        return;
    }
    throw std::runtime_error("Error opening file for writing.");
}
std::string CsvReportPrinter::fileExtension() const noexcept {
    return "csv";
}
