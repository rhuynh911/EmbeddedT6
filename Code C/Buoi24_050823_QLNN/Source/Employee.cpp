#include <iostream>
#include "../Header/Employee.hpp"

/*
 * Fuction: createTables() 
 * Decription: create a list of table rely on the number of total table entered from keyborad
 */
    void Employee::createTables(int num) {
        if (!isTableCreated) {
            for (int i = 1; i <= num; i++) {
                Table table(i);
                tables.push_back(table);
            }
            isTableCreated = true;
        }
    }
/*
 * Fuction: displayTableList()
 * Decription: print the list of table to the Console Screen
 */
    void Employee::displayTableList() {
        if (!tables.empty()) {
            cout << "=== Table list ===" << endl;
            cout << "Table\tStatus" << endl;
            for ( const Table& table : tables) {
                cout << "  " << table.id << "   -   ";
                if (table.status == Open) {
                    cout << "O";
                }
                else {
                    cout << "X";
                }
                cout << endl;
            }
        } else {
            cout << "Table list is empty." << endl;
        }
    }
/*
 * Fuction: displayMenu()
 * Decription: just print out the menu that took from the list
 */
    void Employee::displayMenu() {
        cout << "==== Restaurant Menu ====" << endl;
        for (auto& food : RestaurantMenu) {
            cout << "ID: " << food.getId() << " - Name: " << food.getName() << " - Price: $" << food.getPrice() << endl;
        }
    }
/*
 * Fuction: addFoodToTable
 * Decription: add food from the list to the define table
 */
    void Employee::addFoodToTable(int tableId, int foodId) {
        for (Table& table : tables) {
            if (table.id == tableId) {
                for (Food& food : RestaurantMenu) {
                    if (food.getId() == foodId) {
                        table.addFood(food);
                        return;
                    }
                }
                cout << "Food with ID " << foodId << " does not exist in the menu." << endl;
                return;
            }
        }
        cout << "Table " << tableId << " does not exist." << endl;
    }
/*
 * Fuction: removeFoodFromTable()
 * Decription: to remove the food added to table
 */
    void Employee::removeFoodFromTable(int tableId, int foodId) {
        for (Table& table : tables) {
            if (table.id == tableId) {
                table.removeFood(foodId);
                return;
            }
        }
        cout << "Table " << tableId << " does not exist." << endl;
    }
/*
 * Fuction: calculateBillForTable()
 * Decription: using calculateBill() method from Table class, then print the bill out
 */
    void Employee::calculateBillForTable(int tableId) {
        for (Table& table : tables) {
            if (table.id == tableId) {
                table.calculateBill();
                return;
            }
        }
        cout << "Table " << tableId << " does not exist." << endl;
    }
/*
 * Fuction: printTableStatus()
 * Decription: show to screen the list of table, and their status 'X' or 'O'
 */
    void Employee::printTableStatus() {
        cout << "Table status:" << endl;
        for (const Table& table : tables) {
            cout << "Table " << table.id << ": ";
            if (table.status == Open) {
                cout << "Open";
            }
            else {
                cout << "Close";
            }
            cout << endl;
        }
    }
