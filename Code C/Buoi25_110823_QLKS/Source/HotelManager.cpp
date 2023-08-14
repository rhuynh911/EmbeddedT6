#include "HotelManager.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Constructor
HotelManager::HotelManager() {
    // Initialize rooms, customers, employees, and services as needed

    // Initialize rooms
    rooms.push_back(Room(101, 2));
    rooms.push_back(Room(102, 2));
    rooms.push_back(Room(103, 3));
    // ... add more rooms as needed

    // Initialize services
    services.push_back(Service("Restaurant", 100));
    services.push_back(Service("Bar", 50));
    services.push_back(Service("Swimming Pool", 200));
    // ... add more services as needed

    // Initialize employees
    employees.push_back(Employee("John", "Manager", "1234567890"));
    employees.push_back(Employee("Jane", "Receptionist", "9876543210"));
    // ... add more employees as needed

    // Initialize customers (optional)
    customers.push_back(Customer("Mathew", "1234567890", "Addr1"));
    customers.push_back(Customer("Micheal", "987654321", "Addr2"));
    customers.push_back(Customer("David", "1112223344", "Addr3"));
    // ...

    // Initialize bookedRooms map
    // ...

    // Initialize other necessary data
    // ...

}

void HotelManager::showRoomStatus() const {
    std::cout << "Room Status:" << std::endl;
    for (const Room& room : rooms) {
        std::cout << "Room " << room.getNumber() << ": ";
        if (room.getStatus() == Room::Status::Booked) {
            std::cout << "Booked" << std::endl;
        } else if (room.getStatus() == Room::Status::Cleaning) {
            std::cout << "Cleaning" << std::endl;
        } else {
            std::cout << "Available" << std::endl;
        }
    }
}

void HotelManager::showCustomerList() const {
    std::cout << "Customer List:" << std::endl;
    for (const Customer& customer : customers) {
        std::cout << "Name: " << customer.getName() << ", Phone: " << customer.getPhoneNumber() << std::endl;
    }
}

void HotelManager::showEmployeeList() const {
    std::cout << "Employee List:" << std::endl;
    for (const Employee& employee : employees) {
        std::cout << "Name: " << employee.getName() << ", Position: " << employee.getPosition() << std::endl;
    }
}

void HotelManager::showServiceList() const {
    std::cout << "Service List:" << std::endl;
    for (const Service& service : services) {
        std::cout << "Service: " << service.getName() << ", Price: $" << service.getPrice() << std::endl;
    }
}

void HotelManager::bookRoom(const Customer& customer, int roomNumber) {
    for (Room& room : rooms) {
        if (room.getNumber() == roomNumber && (room.getStatus() != Room::Status::Booked) && (room.getStatus() != Room::Status::Cleaning)) {
            // Room can be booked, update the room status and add to bookedRooms
            room.setStatus(Room::Status::Booked);
            bookedRooms.insert(std::make_pair(roomNumber, customer));
            std::cout << "Room " << roomNumber << " has been booked by " << customer.getName() << "." << std::endl;
        }
    }
    std::cout << "Room " << roomNumber << " is not available for booking." << std::endl;
}

void HotelManager::addCustomer(const Customer& customer) {
    customers.push_back(customer);
    std::cout << "Customer added: " << customer.getName() << std::endl;
}

void HotelManager::editCustomer(const Customer& customer) {
    for (Customer& existingCustomer : customers) {
        if (existingCustomer.getPhoneNumber() == customer.getPhoneNumber()) {
            existingCustomer = customer;
            std::cout << "Customer information updated." << std::endl;
            return;
        }
    }
    std::cout << "Customer not found." << std::endl;
}

void HotelManager::deleteCustomer(const Customer& customer) {
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (*it == customer) {
            customers.erase(it);
            std::cout << "Customer deleted." << std::endl;
            return;
        }
    }
    std::cout << "Customer not found." << std::endl;
}

void HotelManager::addEmployee(const Employee& employee) {
    employees.push_back(employee);
    std::cout << "Employee added: " << employee.getName() << std::endl;
}

void HotelManager::editEmployee(const Employee& employee) {
    for (Employee& existingEmployee : employees) {
        if (existingEmployee.getPhoneNumber() == employee.getPhoneNumber()) {
            existingEmployee = employee;
            std::cout << "Employee information updated." << std::endl;
            return;
        }
    }
    std::cout << "Employee not found." << std::endl;
}

void HotelManager::deleteEmployee(const Employee& employee) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (*it == employee) {
            employees.erase(it);
            std::cout << "Employee deleted." << std::endl;
            return;
        }
    }
    std::cout << "Employee not found." << std::endl;
}

void HotelManager::addService(const Service& service) {
    services.push_back(service);
    std::cout << "Service added: " << service.getName() << std::endl;
}

void HotelManager::editService(const Service& service) {
    for (Service& existingService : services) {
        if (existingService.getName() == service.getName()) {
            existingService = service;
            std::cout << "Service information updated." << std::endl;
            return;
        }
    }
    std::cout << "Service not found." << std::endl;
}

void HotelManager::deleteService(const Service& service) {
    for (auto it = services.begin(); it != services.end(); ++it) {
        if (*it == service) {
            services.erase(it);
            std::cout << "Service deleted." << std::endl;
            return;
        }
    }
    std::cout << "Service not found." << std::endl;
}

void HotelManager::makePayment(const Customer& customer, double amount) {
    // Implement code to process payment
    // For demonstration purposes, let's just print a message
    std::cout << "Payment of $" << amount << " made by " << customer.getName() << std::endl;
}


void HotelManager::showReportsAndStatistics() const {
    // Implement code to display reports and statistics
    // For demonstration purposes, let's just print a message
    std::cout << "Displaying reports and statistics..." << std::endl;
}

void HotelManager::sendNotification(const Customer& customer, const std::string& message) {
    // Implement code to send notifications to customers
    // For demonstration purposes, let's just print a message
    std::cout << "Sending notification to " << customer.getName() << ": " << message << std::endl;
}

void HotelManager::addReview(const Customer& customer, const std::string& review) {
    // Implement code to add customer reviews
    // For demonstration purposes, let's just print a message
    std::cout << "Adding review from " << customer.getName() << ": " << review << std::endl;
}

// Getter and Setter for rooms
const std::vector<Room>& HotelManager::getRooms() const {
    return rooms;
}

void HotelManager::setRooms(const std::vector<Room>& rooms) {
    this->rooms = rooms;
}

// Getter and Setter for customers
const std::vector<Customer>& HotelManager::getCustomers() const {
    return customers;
}

void HotelManager::setCustomers(const std::vector<Customer>& customers) {
    this->customers = customers;
}

// Getter and Setter for employees
const std::vector<Employee>& HotelManager::getEmployees() const {
    return employees;
}

void HotelManager::setEmployees(const std::vector<Employee>& employees) {
    this->employees = employees;
}

// Getter and Setter for services
const std::vector<Service>& HotelManager::getServices() const {
    return services;
}

void HotelManager::setServices(const std::vector<Service>& services) {
    this->services = services;
}

// Getter and Setter for bookedRooms
const std::map<int, Customer>& HotelManager::getBookedRooms() const {
    return bookedRooms;
}

void HotelManager::setBookedRooms(const std::map<int, Customer>& bookedRooms) {
    this->bookedRooms = bookedRooms;
}
