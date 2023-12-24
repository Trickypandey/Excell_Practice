#pragma once
#include "ExcelCell.h"
class Spreadsheet {
private:
    ExcelCell** cells;  // 2D array of ExcelCell objects
    int numRows;
    int numCols;

public:
    Spreadsheet(int rows = 10, int cols = 10);
    ~Spreadsheet();

    void addCell(int row, int col, const ExcelCell& cell);
    void addCellFromUserInput();
    void displayAllCells() const;
    int getRowCount() const;
    int getColCount() const;
    void updateCell(); 
};

