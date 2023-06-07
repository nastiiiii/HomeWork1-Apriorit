#pragma once
#include "VirtualReportPrinter.h"

struct FileProperties;

class TextReportPrinter : public ReportPrinter {
public:
    void printReport(std::string &&reportName, const std::vector<FileProperties> &items) const final;
    std::string fileExtension() const noexcept final;
};


