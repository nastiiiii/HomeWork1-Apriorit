#pragma once

#include <functional>
#include <memory>
#include <unordered_map>

#include "../ReportPrinterType.h"

class ReportPrinter;

class ReportPrinterFactory {
public:
    using ReportPrinterCreator = std::function<std::unique_ptr<ReportPrinter>()>;

private:
    static const std::unordered_map<ReportPrinterType, ReportPrinterCreator> mapping;

public:
    static std::unique_ptr<ReportPrinter> create(ReportPrinterType type);
};
