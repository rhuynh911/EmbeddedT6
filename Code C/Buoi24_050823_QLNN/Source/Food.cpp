#include "../Header/Food.hpp"

using namespace std;

int Food::nextId = 1;

    Food::Food(string Name, double Price) : Name(Name), Price(Price) {Id = nextId, nextId++;}
/*
 * Fuction: getId()
 * Decription: get Id of food from list
 */
    int Food::getId()const{
        return Id;
    }
/*
 * Fuction: setName()
 * Decription: to put the name of food 
 */
    void Food::setName(string Name){
        this -> Name = Name;
    }
/*
 * Fuction: setPrice()
 * Decription: set the price for food
 */
    void Food::setPrice(double Price){
        this -> Price = Price;
    }
/*
 * Fuction: getPrice()
 * Decription: take the cost of food from list
 */
    double Food::getPrice()const{
        return Price;
    }
/*
 * Fuction: getName()
 * Decription: get the name of food from list
 */
    string Food::getName()const{
        return Name;
    }
