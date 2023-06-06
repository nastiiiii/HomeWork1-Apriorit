#pragma once
#include <fstream>
#include <iostream>
#include <string>

#include "../../../FileProperties.h"
#include "../VirtualReportPrinter/VirtualReportPrinter.h"
class CsvReportPrinter : public ReportPrinter {
public:
    void printReport(std::string &&reportName, const std::vector<FileProperties> &items) const final;
    std::string fileExtension() const noexcept final;
};
