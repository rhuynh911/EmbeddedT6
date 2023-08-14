#ifndef SERVICE_HPP
#define SERVICE_HPP

#include <string>

class Service {
public:
    Service(const std::string& name, double price);
    const std::string& getName() const;
    double getPrice() const;
    // Define the == operator to compare two Customer objects
    bool operator==(const Service& other) const {
        return name == other.getName(); // Assuming you have an 'name' member variable in Customer class
    }
private:
    std::string name;
    double price;
};

#endif
