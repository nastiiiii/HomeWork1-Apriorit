#include "VirtualReportPrinter.h"
#include <fstream>

std::ofstream ReportPrinter::createFile(std::string &&reportName) const {
    return std::ofstream(std::move(reportName) + "." + fileExtension());
}