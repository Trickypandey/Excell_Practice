// File: Spreadsheet.cpp
#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(int rows, int cols) : numRows(rows), numCols(cols) {
    // Allocate memory for the 2D array
    cells = new ExcelCell*[numRows];
    for (int i = 0; i < numRows; ++i) {
        cells[i] = new ExcelCell[numCols];
    }
}

Spreadsheet::~Spreadsheet() {
    // Deallocate memory for the 2D array
    for (int i = 0; i < numRows; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}

void Spreadsheet::addCell(int row, int col, const ExcelCell& cell) {
    // Check if row and col are within bounds
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
        cells[row][col] = cell;
    } else {
        std::cerr << "Invalid row or column index." << std::endl;
    }
}

void Spreadsheet::addCellFromUserInput() {
    std::string content;
    bool isArithmetic;
    int row, col;

    std::cout << "Enter cell content: ";
    std::cin >> content;
    isArithmetic = ExcelCell::isDouble(content);

    std::cout << "Enter row index: ";
    std::cin >> row;

    std::cout << "Enter column index: ";
    std::cin >> col;

    addCell(row, col, ExcelCell(content, isArithmetic));
}

void Spreadsheet::updateCell() {
        int rowToUpdate, colToUpdate;
        bool isArithmetic;
        std::string newContent = "";  
        std::cout << "Enter row index to update: ";
        std::cin >> rowToUpdate;

        std::cout << "Enter column index to update: ";
        std::cin >> colToUpdate;

        std::cout << "Enter new content: ";
        std::cin >> newContent;

        isArithmetic = ExcelCell::isDouble(newContent);
    if (rowToUpdate >= 0 && rowToUpdate < numRows && colToUpdate >= 0 && colToUpdate < numCols) {

        /*
        
            remember to ask when you where passing string(new content) instead of  Excell class it was updating 
            data automaticaly

        */

        // addCell(rowToUpdate,colToUpdate,newContent);
        addCell(rowToUpdate,colToUpdate,ExcelCell(newContent,isArithmetic));
    } else {
        std::cerr << "Invalid row or column index." << std::endl;
    }
}

void Spreadsheet::displayAllCells() const {
    std::cout << "All Cells:\n";
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << "Cell [" << i << "][" << j << "]:\n";
            cells[i][j].display();
            std::cout << std::endl;
        }
    }
}

int Spreadsheet::getRowCount() const {
    return numRows;
}

int Spreadsheet::getColCount() const {
    return numCols;
}
