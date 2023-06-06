#pragma once

#include <string>
#include <vector>

struct FileProperties;

class ReportPrinter {
public:
    virtual void printReport(std::string &&reportName, const std::vector<FileProperties> &items) const = 0;
    virtual ~ReportPrinter() = default;

protected:
    virtual std::string fileExtension() const noexcept = 0;
    std::ofstream createFile(std::string &&reportName) const;
};