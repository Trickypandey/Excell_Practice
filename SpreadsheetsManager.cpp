// File: SpreadsheetsManager.cpp
#include "SpreadsheetsManager.h"

SpreadsheetsManager::SpreadsheetsManager() : currentSpreadsheetIndex(-1) {}

void SpreadsheetsManager::addSpreadsheet(const Spreadsheet& spreadsheet) {
    spreadsheets.push_back(spreadsheet);
    if (currentSpreadsheetIndex == -1) {
        // If no spreadsheet is selected, set the current spreadsheet to the newly added one
        currentSpreadsheetIndex = spreadsheets.size() - 1;
    }
}

void SpreadsheetsManager::displayAllSpreadsheets() const {
    for (size_t i = 0; i < spreadsheets.size(); ++i) {
        std::cout << "Spreadsheet " << i + 1 << ":\n";
        spreadsheets[i].displayAllCells();
        std::cout << "Total cells: " << spreadsheets[i].getRowCount() * spreadsheets[i].getColCount() << std::endl;
        std::cout << "------------------------\n";
    }
}

void SpreadsheetsManager::selectSpreadsheet() {
    // displayAllSpreadsheets();
    std::cout << "Enter the index of the spreadsheet to select: ";
    int index;
    std::cin >> index;

    if (index >= 1 && index <= static_cast<int>(spreadsheets.size())) {
        currentSpreadsheetIndex = index - 1;  // Adjust index to be zero-based
        std::cout << "Selected spreadsheet: " << currentSpreadsheetIndex + 1 << std::endl;
    } else {
        std::cout << "Invalid spreadsheet index.\n";
    }
}

void SpreadsheetsManager::displayCurrentSpreadsheet() const {
    if (currentSpreadsheetIndex != -1) {
        std::cout << "Currently selected spreadsheet:\n";
        spreadsheets[currentSpreadsheetIndex].displayAllCells();
        std::cout << "Total cells: "
                  << spreadsheets[currentSpreadsheetIndex].getRowCount() * spreadsheets[currentSpreadsheetIndex].getColCount()
                  << std::endl;
    } else {
        std::cout << "No spreadsheet selected.\n";
    }
}

Spreadsheet& SpreadsheetsManager::getCurrentSpreadsheet() {
    return spreadsheets[currentSpreadsheetIndex];
}

int SpreadsheetsManager::getCurrentSpreadsheetIndex(){
    return currentSpreadsheetIndex;
}
