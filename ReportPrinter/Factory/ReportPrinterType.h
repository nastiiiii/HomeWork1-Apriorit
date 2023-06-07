#pragma once

#include <string>
#include <unordered_map>

enum class ReportPrinterType {
    TXT,
    CSV,
    XML
};

static const std::unordered_map<std::string, ReportPrinterType> stringToReportPrinterType{
        {"txt", ReportPrinterType::TXT},
        {"csv", ReportPrinterType::CSV},
        {"xml", ReportPrinterType::XML},

};