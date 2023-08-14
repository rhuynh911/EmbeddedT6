#include "Employee.hpp"

Employee::Employee(const std::string& name, const std::string& position, const std::string& phoneNumber)
    : name(name), position(position), phoneNumber(phoneNumber) {}

const std::string& Employee::getName() const {
    return name;
}

const std::string& Employee::getPosition() const {
    return position;
}

const std::string& Employee::getPhoneNumber() const {
    return phoneNumber;
}
