// ExcelCell.cpp
#include "ExcelCell.h"

ExcelCell::ExcelCell(std::string c, bool ar) : content(c), arthematicOperation(ar) {}

std::string ExcelCell::getContent() const {
    return content;
}

void ExcelCell::setContent(const std::string& c) {
    content = c;
}

double ExcelCell::getContentDouble() const {
    if (arthematicOperation) {
        return std::stod(content);
    } else {
        return 0.0; // Return 0.0 if not an arithmetic operation
    }
}

void ExcelCell::display() const {
    if (!content.empty()) {
        std::cout << "Content: " << content << std::endl;
    }
    std::cout << "Arithmetic Operation: " << arthematicOperation << std::endl;
}

bool ExcelCell::isDouble(const std::string& str) {
    std::stringstream ss(str);
    double d;
    return (ss >> d) && ss.eof();
}

std::string concatenateDoubleAndString(double num, const std::string& st) {
    std::ostringstream oss;
    oss << std::fixed << num;
    return oss.str() + st;
}
