#include <iostream>
#include "../Header/Table.hpp"

using namespace std;
/*
 * Fuction: Table(int _id)
 * Decription: constructor of Table class
 */
Table::Table(int _id) : id(_id) {status = Open;}
/*
 * Fuction: addFood()
 * Decription: add food to orders list
 */
void Table::addFood(const Food& food) {
    if (status == Close) {
        cout << "Table " << id << " is closed. Cannot add food." << endl;
    }
    else {
        orders.push_back(food);
        cout << "Added \"" << food.getName() << "\" to table " << id << endl;
        status = Close;
    }
}
/*
 * Fuction: removeFood()
 * Decription: just delete food from orders list
 */
void Table::removeFood(int foodId) {
    if (status == Close) {
        cout << "Table " << id << " is closed. Cannot remove food." << endl;
    }
    else {
        bool found = false;
        for (auto it = orders.begin(); it != orders.end(); ++it) {
            if (it->getId() == foodId) {
                orders.erase(it);
                cout << "Removed food with ID " << foodId << " from table " << id << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Food with ID " << foodId << " is not found in table " << id << endl;
        }
    }
}
/*
 * Fuction: calculateBill()
 * Decription: like a function to sum of all food in a table
 */
void Table::calculateBill() {
    double total = 0;
    cout << "==== Bill for table " << id << " ====" << endl;
    for (Food& food : orders) {
        total += food.getPrice();
        cout << food.getName() << ": \t\t$" << food.getPrice() << endl;
    }
    cout << "Total: \t\t$" << total << endl;

    orders.clear();
    status = Open;
}
