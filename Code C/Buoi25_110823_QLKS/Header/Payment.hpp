#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include "Customer.hpp"

class Payment {
public:
    Payment(const Customer& customer, double amount);
    const Customer& getCustomer() const;
    double getAmount() const;
private:
    Customer customer;
    double amount;
};

#endif
