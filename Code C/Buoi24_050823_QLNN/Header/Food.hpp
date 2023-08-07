#ifndef FOOD_HPP
#define FOOD_HPP

#include <string>
using namespace std;
class Food {
    private:
        static int nextId;
        int Id;
        string Name;
        double Price;
    public:
        Food(string Name, double Price);
        void setName(string Name);
        void setPrice(double Price);
        int getId()const;
        double getPrice()const;
        string getName()const;
};


#endif //FOOD_HPP
