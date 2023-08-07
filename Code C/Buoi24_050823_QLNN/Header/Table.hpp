#ifndef TABLE_HPP
#define TABLE_HPP

#include "Manager.hpp"

enum TableStatus {Open, Close};

class Table {
    public:
        int id;
        TableStatus status;
        list<Food> orders;

        Table(int _id);

        void addFood(const Food& food);

        void removeFood(int foodId);

        void calculateBill();
};
#endif //TABLE_HPP
