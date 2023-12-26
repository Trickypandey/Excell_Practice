#include <iostream>
#include "SpreadsheetsManager.h"

int main() {
    SpreadsheetsManager manager;

    int choice;
    while (true) {
        // Display menu
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Manage Spreadsheets" << std::endl;
        std::cout << "2. Perform Operations on Selected Spreadsheet" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Manage Spreadsheets
                int manageChoice;
                std::cout << "Manage Spreadsheets Menu:" << std::endl;
                std::cout << "1. Add New Spreadsheet" << std::endl;
                std::cout << "2. Display All Spreadsheets" << std::endl;
                std::cout << "3. Select Spreadsheet" << std::endl;
                std::cout << "4. Back to Main Menu" << std::endl;   
                std::cout << "Enter your choice: ";
                std::cin >> manageChoice;

                switch (manageChoice) {
                    case 1:
                        // Add New Spreadsheet
                        int numRows, numCols;
                        std::cout << "Enter the number of rows: ";
                        std::cin >> numRows;
                        std::cout << "Enter the number of columns: ";
                        std::cin >> numCols;
                        manager.addSpreadsheet(Spreadsheet(numRows, numCols));
                        std::cout << "New spreadsheet added.\n";
                        break;
                    case 2:
                        // Display All Spreadsheets
                        manager.displayAllSpreadsheets();
                        break;
                    case 3:
                        // Select Spreadsheet
                        manager.selectSpreadsheet();
                        break;
                    case 4:
                        // Back to Main Menu
                        break;
                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                }
                break;

            case 2:
                // Perform Operations on Selected Spreadsheet
                if (manager.getCurrentSpreadsheetIndex() == -1) {
                    std::cout << "No spreadsheet selected. Please select a spreadsheet first.\n";
                } else {
                    int opsChoice;
                    std::cout << "Operations Menu:" << std::endl;
                    std::cout << "1. Add Cell" << std::endl;
                    std::cout << "2. Display All Cells" << std::endl;
                    std::cout << "3. Update Cells" << std::endl;
                    std::cout << "4. Perform Arithmetic Operation" << std::endl;
                    std::cout << "5. Back to Main Menu" << std::endl;
                    std::cout << "Enter your choice: ";
                    std::cin >> opsChoice;

                    switch (opsChoice) {
                        case 1:
                            // Add Cell
                            manager.getCurrentSpreadsheet().addCellFromUserInput();
                            break;
                        case 2:
                            // Display All Cells
                            manager.getCurrentSpreadsheet().displayAllCells();
                            break;
                        case 3:
                            // Update Cells
                            manager.getCurrentSpreadsheet().updateCell();
                            break;
                        case 4:
                            // Perform Arithmetic Operation
                            break;
                        case 5:
                            // Back to Main Menu
                            break;
                        default:
                            std::cout << "Invalid choice. Please try again." << std::endl;
                    }
                }
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
