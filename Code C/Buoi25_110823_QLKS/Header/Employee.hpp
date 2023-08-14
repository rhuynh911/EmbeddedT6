#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

class Employee {
public:
    Employee(const std::string& name, const std::string& position, const std::string& phoneNumber);
    const std::string& getName() const;
    const std::string& getPosition() const;
    const std::string& getPhoneNumber() const;
    // Define the == operator to compare two Customer objects
    bool operator==(const Employee& other) const {
        return name == other.getName(); // Assuming you have an 'name' member variable in Customer class
    }
private:
    std::string name;
    std::string position;
    std::string phoneNumber;
};

#endif
