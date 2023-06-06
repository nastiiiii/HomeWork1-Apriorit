#pragma once
#include <fstream>
#include <iostream>

#include "../../../FileProperties.h"
#include "../VirtualReportPrinter/VirtualReportPrinter.h"

class XmlReportPrinter : public ReportPrinter {
public:
    void printReport(std::string &&reportName, const std::vector<FileProperties> &items) const final;
    std::string fileExtension() const noexcept final;
};
