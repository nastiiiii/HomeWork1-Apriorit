#include "XmlReportPrinter.h"
#include <iostream>
#include "../../FileProperties.h"

namespace {
    using Tag = std::string;
    struct TagWrapper {
        Tag _tag;
        std::ofstream &stream;
        TagWrapper(std::ofstream &ofstream, Tag tag) : stream(ofstream), _tag(std::move(tag)) {
            stream << "<" + _tag + ">";
        }

        ~TagWrapper() {
            stream << "</" + _tag + ">";
        }
    };
}// namespace


void XmlReportPrinter::printReport(std::string &&reportName, const std::vector<FileProperties> &items) const {

    auto file = createFile(std::move(reportName));
    static constexpr auto META_INFO = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    if (file.is_open()) {
        file << META_INFO << std::endl;
        const auto reportWrapper = TagWrapper(file, "Report");
        file << std::endl;
        for (const auto &item: items) {
            {
                const auto itemWrapper = TagWrapper(file, "Item");
                file << std::endl;

                for (int i = 0; i < static_cast<size_t>(FileProperty::NN); ++i) {
                    FileProperty fp = static_cast<FileProperty>(i);
                    {
                        const auto tagWrapper = TagWrapper(file, filePropertyToString(fp));
                        file << item.properties[i];
                    }
                    file << std::endl;
                }
            }
            file << std::endl;
        }
        file.close();
        return;
    }
    throw std::runtime_error("Could not open file");
}
std::string XmlReportPrinter::fileExtension() const noexcept {
    return "xml";
}
