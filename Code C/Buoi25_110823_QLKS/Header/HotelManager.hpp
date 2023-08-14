#ifndef HOTEL_MANAGER_HPP
#define HOTEL_MANAGER_HPP

#include "Room.hpp"
#include "Customer.hpp"
#include "Employee.hpp"
#include "Service.hpp"
#include "Payment.hpp"
#include <vector>
#include <map>

using namespace std;

class HotelManager {
public:
    HotelManager();
    void showRoomStatus() const;
    void showCustomerList() const;
    void showEmployeeList() const;
    void showServiceList() const;
    void bookRoom(const Customer& customer, int roomNumber);
    void releaseRoom(const Customer& customer, int roomNumber);
    void bookService(const Customer& customer, const std::string& srvName);
    void releaseService(const Customer& customer, const std::string& srvName);
    void addCustomer(const Customer& customer);
    void editCustomer(const Customer& customer);
    void deleteCustomer(const Customer& customer);
    void addEmployee(const Employee& employee);
    void editEmployee(const Employee& employee);
    void deleteEmployee(const Employee& employee);
    void addService(const Service& service);
    void editService(const Service& service);
    void deleteService(const Service& service);
    void makePayment(const Customer& customer);
    void showReportsAndStatistics() const;
    void sendNotification(const Customer& customer, const std::string& message);
    void addReview(const Customer& customer, const std::string& review);

    // Getter and Setter for rooms
    const std::vector<Room>& getRooms() const;
    void setRooms(const std::vector<Room>& rooms);

    // Getter and Setter for customers
    const std::vector<Customer>& getCustomers() const;
    void setCustomers(const std::vector<Customer>& customers);

    // Getter and Setter for employees
    const std::vector<Employee>& getEmployees() const;
    void setEmployees(const std::vector<Employee>& employees);

    // Getter and Setter for services
    const std::vector<Service>& getServices() const;
    void setServices(const std::vector<Service>& services);

    // Getter and Setter for bookedRooms
    const std::map<int, Customer>& getBookedRooms() const;
    void setBookedRooms(const std::map<int, Customer>& bookedRooms);

    // Getter and Setter for bookedService
    const std::map<string, Customer>& getBookedServices() const;
    void setBookedServices(const std::map<string, Customer>& bookedServices);
    
private:
    std::vector<Room> rooms;
    std::vector<Customer> customers;
    std::vector<Employee> employees;
    std::vector<Service> services;
    std::map<int, Customer> bookedRooms;
    std::map<string, Customer> bookedServices;
};

#endif
