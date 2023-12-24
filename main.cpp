#include <iostream>
#include <string>
#include "Spreadsheet.h"

int main() {
    int numRows, numCols;

    // Get user input for the number of rows and columns
    std::cout << "Enter the number of rows: ";
    std::cin >> numRows;

    std::cout << "Enter the number of columns: ";
    std::cin >> numCols;

    // Create a Spreadsheet with the specified number of rows and columns
    Spreadsheet spreadsheet(numRows, numCols);

    int choice;
    while (true) {
        // Display menu
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Cell" << std::endl;
        std::cout << "2. Display All Cells" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "4. Update Cells" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Process user choice
        switch (choice) {
            case 1:
                // Add Cell
                spreadsheet.addCellFromUserInput();
                break;

            case 2:
                // Display All Cells
                spreadsheet.displayAllCells();
                std::cout << "Total cells: " << spreadsheet.getRowCount() * spreadsheet.getColCount() << std::endl;
                break;

            case 3:

                std::cout << "Exiting program." << std::endl;
                return 0;

            case 4:

                spreadsheet.updateCell();
                break;

            default:
            
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
