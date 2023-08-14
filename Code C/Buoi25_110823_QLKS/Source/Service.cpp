#include "Service.hpp"

Service::Service(const std::string& name, double price) : name(name), price(price) {}

const std::string& Service::getName() const {
    return name;
}

double Service::getPrice() const {
    return price;
}
