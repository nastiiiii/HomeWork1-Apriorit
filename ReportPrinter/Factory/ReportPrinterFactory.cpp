#include "ReportPrinterFactory.h"
#include "CsvReportPrinter.h"
#include "TextReportPrinter.h"
#include "XmlReportPrinter.h"
#include <functional>
#include <unordered_map>

namespace {
    using ReportPrinterCreator = std::function<std::unique_ptr<ReportPrinter>()>;

    const std::unordered_map<ReportPrinterType, ReportPrinterCreator> creatorsMapping{
            {ReportPrinterType::CSV, +[] { return std::unique_ptr<CsvReportPrinter>(new CsvReportPrinter); }},
            {ReportPrinterType::TXT, +[] { return std::unique_ptr<TextReportPrinter>(new TextReportPrinter); }},
            {ReportPrinterType::XML, +[] { return std::unique_ptr<XmlReportPrinter>(new XmlReportPrinter); }}};
}

std::unique_ptr<ReportPrinter> ReportPrinterFactory::create(ReportPrinterType type) {
    const auto neededCreator = creatorsMapping.find(type);
    if (neededCreator == creatorsMapping.end()) {
        throw std::runtime_error("Report type is not supported by the factory");
    }
    return neededCreator->second();
}
