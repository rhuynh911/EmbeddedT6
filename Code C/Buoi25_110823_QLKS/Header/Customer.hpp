#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>

class Customer {
public:
    Customer(const std::string& name, const std::string& phoneNumber, const std::string& address);
    const std::string& getName() const;
    const std::string& getPhoneNumber() const;
    const std::string& getAddress() const;
    // Define the == operator to compare two Customer objects
    bool operator==(const Customer& other) const {
        return name == other.getName(); // Assuming you have an 'name' member variable in Customer class
    }
private:
    std::string name;
    std::string phoneNumber;
    std::string address;
};

#endif
