    // File: Spreadsheet.cpp

    #include "Spreadsheet.h"

    Spreadsheet::Spreadsheet(int initialCapacity) : capacity(initialCapacity), cellCount(0) {
        cells = new ExcelCell[capacity];
    }

    Spreadsheet::~Spreadsheet() {
        delete[] cells;
    }

    void Spreadsheet::addCell(const ExcelCell& cell) {
        if (cellCount == capacity) {
            // Resize the array if necessary
            capacity *= 2;
            ExcelCell* newCells = new ExcelCell[capacity];
            for (int i = 0; i < cellCount; ++i) {
                newCells[i] = cells[i];
            }
            delete[] cells;
            cells = newCells;
        }

        cells[cellCount++] = cell;
    }

    void Spreadsheet::addCellFromUserInput() {
        std::string content;
        bool isArithmetic;

        std::cout << "Enter cell content: ";
        std::cin >> content;

        isArithmetic = ExcelCell::isDouble(content);

        ExcelCell cell(content, isArithmetic);
        addCell(cell);
    }

    void Spreadsheet::displayAllCells() const {
        std::cout << "All Cells:\n";
        for (int i = 0; i < cellCount; ++i) {
            std::cout << "Cell " << i << ":\n";
            cells[i].display();
            std::cout << std::endl;
        }
    }

    int Spreadsheet::getCellCount() const {
        return cellCount;
    }
