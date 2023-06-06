#include <iostream>

#include <memory>
#include <vector>

#include "FileProperties.h"
#include "ReportPrinterFactory/Printers/VirtualReportPrinter/VirtualReportPrinter.h"
#include "ReportPrinterFactory/ReportPrinterFactory.h"
#include "Utilities/DirectoryFilesInfoFetcher.h"


int main() {
    std::string folderPath;
    std::cout << "Enter the full path to the folder: \n";
    std::getline(std::cin, folderPath);


    std::string format;
    std::cout << "Enter the report format (txt, csv, xml): ";
    std::cin >> format;
    std::string reportName;
    std::cout << "Enter the report name: ";
    std::cin >> reportName;

    const auto printerTypeFindRes = stringToReportPrinterType.find(format);
    if (printerTypeFindRes == stringToReportPrinterType.end()) {
        throw std::invalid_argument("The format is invalid");
    }

    const auto filesProperties = utils::collectFolderContents(boost::filesystem::path(folderPath));

    std::unique_ptr<ReportPrinter> reportPrinter = ReportPrinterFactory::create(printerTypeFindRes->second);
    reportPrinter->printReport(std::move(reportName), filesProperties);


    return 0;
}