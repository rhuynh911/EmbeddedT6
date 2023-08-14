#include "Payment.hpp"

Payment::Payment(const Customer& customer, double amount) : customer(customer), amount(amount) {}

const Customer& Payment::getCustomer() const {
    return customer;
}

double Payment::getAmount() const {
    return amount;
}
