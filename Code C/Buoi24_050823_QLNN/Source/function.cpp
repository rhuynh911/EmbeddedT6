#include <iostream>

#include "../Header/Manager.hpp"
#include "../Header/Employee.hpp"

void displayToConsoleScreen(){
    Manager manager;
    Employee employee;
    int option, choice;

    do {
        cout << "=== Menu ===\n1. MANAGER\n2. EMPLOYEE\n";
        ENTER_INPUT("0.TURN BACK!\n", option);

        switch (option){
            case 1:
                do {
                    cout << "======== MANAGER ========\n1. Add Food to Menu\n2. Edit Food in Menu\n";
                    cout << "3. Delete Menu Food\n4. Show Menu\n5. Set up number of Table\n";
                    ENTER_INPUT("0. Turn back!\n", choice);

                    switch (choice){
                        case 0:
                            break;
                        case 1:
                            employee.addMenuFood();
                            break;
                        case 2: 
                            employee.editMenu();
                            break;
                        case 3:
                            employee.deleteMenuFood();
                            break;
                        case 4: 
                            employee.displayMenu();
                            break;
                        case 5:
                            int num;
                            ENTER_INPUT("Enter number of Table: \n", num);
                            employee.setTableQuantity(num);
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                } while (choice != 0);
                break;

            case 2:
                employee.createTables(employee.getTableQuantity());
                employee.displayTableList();

                int tableId;
                ENTER_INPUT("Enter table ID: ", tableId);

                do {
                    cout << "====== EMPLOYEE ======\n1. Add Food to Table\n";
                    cout << "2. Delete Table Food\n3. Show Menu\n4. Paying\n";
                    ENTER_INPUT("0. Turn back!\n", choice);

                    switch (choice){
                        case 0:
                            break;
                        case 1:
                            int foodId;
                            ENTER_INPUT("Enter food ID: ", foodId);
                            employee.addFoodToTable(tableId, foodId);
                            break;
                        case 2:
                            ENTER_INPUT("Enter food ID: ", foodId);
                            employee.removeFoodFromTable(tableId, foodId);
                            break;
                        case 3: 
                            employee.displayMenu();
                            break;
                        case 4:
                            employee.calculateBillForTable(tableId);
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                } while (choice != 0);
                break;
            // } else {
            //     cout << "Have to input the data in Manager option!!!\n";
            // }
        }
    } while (option != 0);
}
