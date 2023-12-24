
#include <iostream>
#include "Spreadsheet.h"




int main() {
    // Spreadsheet spreadsheet;

    // ExcelCell cell1("42", true);
    // ExcelCell cell2("Hello", false);

    // spreadsheet.addCell(cell1);
    // spreadsheet.addCell(cell2);

    // spreadsheet.displayAllCells();
    // std::cout << "Total cells: " << spreadsheet.getCellCount() << std::endl;

    Spreadsheet spreadsheet;

    int choice;

    while (true)
    {
        // Display menu
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Cell" << std::endl;
        std::cout << "2. Display All Cells" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Process user choice
        switch (choice) {
            case 1: {
                // Add Cell test
                spreadsheet.addCellFromUserInput();
                break;
            }
            case 2:
                // Display All Cells
                spreadsheet.displayAllCells();
                std::cout << "Total cells: " << spreadsheet.getCellCount() << std::endl;
                break;
            case 3:
                // Exit
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    }

    return 0;
}
