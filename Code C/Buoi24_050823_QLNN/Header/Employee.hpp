#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Manager.hpp"
#include "Table.hpp"

using namespace std;

class Employee : public Manager {

    private:

        bool isTableCreated;

    public:

        Employee() : isTableCreated(false) {}

        list <Table> tables;

        void createTables(int num);

        void displayTableList();

        void displayMenu();

        void addFoodToTable(int tableId, int foodId);

        void removeFoodFromTable(int tableId, int foodId);

        void calculateBillForTable(int tableId);

        void printTableStatus() ;
};

#endif //EMPLOYEE_HPP
