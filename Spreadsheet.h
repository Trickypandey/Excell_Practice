#pragma once
#include "ExcelCell.h"
class Spreadsheet {
private:
    ExcelCell* cells;
    int capacity;
    int cellCount;

public:
    Spreadsheet(int initialCapacity = 10);
    ~Spreadsheet();

    void addCell(const ExcelCell& cell);
    
    void addCellFromUserInput();
    
    void displayAllCells() const;

    int getCellCount() const;
};


