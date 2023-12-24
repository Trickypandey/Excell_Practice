
#pragma once
#include <iostream>
#include <string>
#include <sstream>

class ExcelCell {
public:
    std::string content;
    bool arthematicOperation;

    ExcelCell(std::string c = "", bool ar = false);

    // Getter for content
    std::string getContent() const;

    // Setter for content
    void setContent(const std::string& c);

    // Function to convert content to double if arthematicOperation is true
    double getContentDouble() const;

    static bool isDouble(const std::string& str);

    void display() const;
};


std::string concatenateDoubleAndString(double num, const std::string& st);

