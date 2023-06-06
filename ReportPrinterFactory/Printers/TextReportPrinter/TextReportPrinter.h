#pragma once
#include "../../../FileProperties.h"
#include "../VirtualReportPrinter/VirtualReportPrinter.h"
#include <fstream>
#include <iostream>

class TextReportPrinter : public ReportPrinter {
public:
    void printReport(std::string &&reportName, const std::vector<FileProperties> &items) const final;
    std::string fileExtension() const noexcept final;
};
