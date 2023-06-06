#include "ReportPrinterFactory.h"
#include "Printers/CsvReportPrinter/CsvReportPrinter.h"
#include "Printers/TextReportPrinter/TextReportPrinter.h"
#include "Printers/XmlReportPrinter/XmlReportPrinter.h"
#include <string>

const std::unordered_map<ReportPrinterType, ReportPrinterFactory::ReportPrinterCreator> ReportPrinterFactory::mapping{
        {ReportPrinterType::CSV, +[] { return std::unique_ptr<CsvReportPrinter>(new CsvReportPrinter); }},
        {ReportPrinterType::TXT, +[] { return std::unique_ptr<TextReportPrinter>(new TextReportPrinter); }},
        {ReportPrinterType::XML, +[] { return std::unique_ptr<XmlReportPrinter>(new XmlReportPrinter); }}};


std::unique_ptr<ReportPrinter> ReportPrinterFactory::create(ReportPrinterType type) {
    const auto neededCreator = mapping.find(type);
    if (neededCreator == mapping.end()) {
        throw std::runtime_error("Report type is not supported by the factory");
    }

    return neededCreator->second();
}
