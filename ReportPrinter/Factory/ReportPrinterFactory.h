#pragma once
#include "ReportPrinterType.h"
#include <memory>

class ReportPrinter;

class ReportPrinterFactory {
public:
    static std::unique_ptr<ReportPrinter> create(ReportPrinterType type);
};
