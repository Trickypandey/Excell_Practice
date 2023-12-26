#pragma once

#include <vector>
#include "Spreadsheet.h"

class SpreadsheetsManager {
private:
    std::vector<Spreadsheet> spreadsheets;
    int currentSpreadsheetIndex;  // Index of the currently selected spreadsheet

public:
    SpreadsheetsManager();

    void addSpreadsheet(const Spreadsheet& spreadsheet);
    void displayAllSpreadsheets() const;
    void selectSpreadsheet();
    void displayCurrentSpreadsheet() const;
    int getCurrentSpreadsheetIndex();
    Spreadsheet& getCurrentSpreadsheet();
};


