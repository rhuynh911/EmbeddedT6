#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Manager.hpp"
#include "Food.hpp"
#include <list>

#define ENTER_INPUT(str, var) cout << str; cin >> var; 
#define NAME_INPUT(msg, var) cout << msg; cin.ignore(); getline(cin, var);

using namespace std;

class Manager{
    private:
        int TableQuantity;
    protected:
        list <Food> RestaurantMenu;
    public:
        void addMenuFood();
        void editMenu();
        void deleteMenuFood();
        void displayMenu();
        void setTableQuantity(int num);
        int getTableQuantity() const;
        list <Food> getRestaurantMenu();
};

#endif //MANAGER_HPP
