#include <iostream>
#include "../Header/Manager.hpp"

 list <Food> Manager::getRestaurantMenu(){
        return RestaurantMenu;
    }
/*
 * Fuction: addMenuFood()
 * Decription: to import the food to the RestaurantMenu List
 */
    void Manager::addMenuFood(){
        
        int key;
        
        do {
            string name;
            double price;

            NAME_INPUT("Enter the name of the food: ", name);
            ENTER_INPUT("Enter the price of the food: ", price);

            Food newFood(name, price);
            RestaurantMenu.push_back(newFood);

            cout << "ID\t" << "Name\t\t" << "Price" << endl;
            cout << newFood.getId() << "." << "\t" << newFood.getName() << "\t\t$" << newFood.getPrice() << endl;

            cout << "1. Continue to add food\n0. Turn back\n";
            ENTER_INPUT("Enter option: \n", key);

        } while (key != 0);
    }
/*
 * Fuction: editMenu()
 * Decription: change name or price of food added to Menu List above
 */
    void Manager::editMenu(){
        
        int id;
        displayMenu();
        ENTER_INPUT("Enter Id: ", id);

        for(auto& food : RestaurantMenu){
            if(food.getId() == id) {
                string newName;
                double newPrice;
                int key;

                do {
                    cout << "1. Edit name\n2. Edit Price\n0. Turn back\n";
                    ENTER_INPUT("Enter option: ", key);

                    switch (key){
                        case 0:
                            break;
                        case 1:
                            NAME_INPUT("Enter the new name of food: ", newName);
                            if(!newName.empty())
                                food.setName(newName);
                            break;
                        case 2: 
                            ENTER_INPUT("Enter the new price of food: ", newPrice);
                            if(newPrice != 0.0)
                                food.setPrice(newPrice);
                            break;
                        default: 
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                } while (key != 0);
                cout << "Food with Id: " << id << " has been updated\n";
                return;
            }
        }
        cout << "Food with Id: " << id << " not found!\n";
    }
/*
 * Fuction: deleteMenuFood()
 * Decription: remove the food existing on the Menu List 
 */
    void Manager::deleteMenuFood(){
        
        int id;
        displayMenu();
        ENTER_INPUT("Enter Id to delete: ", id);

        for(auto it = RestaurantMenu.begin(); it != RestaurantMenu.end(); ++it){
            if(it -> getId() == id){
                RestaurantMenu.erase(it);
                cout << "Food with Id: " << id << " has been deleted." << endl;
                return;
            }
        }
        cout << "Food with Id: " << id << " not found!" << endl;
    }
/*
 * Fuction: displayMenu()
 * Decription: print Menu List out
 */
    void Manager::displayMenu(){

        cout << "======= Restaurant Menu =======" << endl;
        cout << "ID\tName\t\tPrice\n";
        for (auto& food : RestaurantMenu) {
            cout << food.getId() << "." << "\t" << food.getName() << "\t\t$" << food.getPrice() << endl;
        }
    }
/*
 * Fuction: setTableQuantity()
 * Decription: input the total number of table 
 */
    void Manager::setTableQuantity(int num){
        this -> TableQuantity = num;
    }
/*
 * Fuction: getTableQuantity() 
 * Decription: pick the total number of table out
 */
    int Manager::getTableQuantity() const{
        return TableQuantity;
    }
