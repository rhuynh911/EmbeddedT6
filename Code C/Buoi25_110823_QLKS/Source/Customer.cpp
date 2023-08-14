#include "Customer.hpp"

Customer::Customer(const std::string& name, const std::string& phoneNumber, const std::string& address)
    : name(name), phoneNumber(phoneNumber), address(address) {}

const std::string& Customer::getName() const {
    return name;
}

const std::string& Customer::getPhoneNumber() const {
    return phoneNumber;
}

const std::string& Customer::getAddress() const {
    return address;
}
