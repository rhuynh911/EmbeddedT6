#include <iostream>
#include "HotelManager.hpp"

void displayMenu() {
    std::cout << "\nHotel Management System Menu:" << std::endl;
    std::cout << "1. Book a room" << std::endl;
    std::cout << "2. Book a service" << std::endl;
    std::cout << "3. Check out" << std::endl;
    std::cout << "4. Show rooms status" << std::endl;
    std::cout << "5. Show customer list" << std::endl;
    std::cout << "6. Show reports and statistics" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

int main() {
    HotelManager hotel;

    // Add sample data
    // ...

    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        Customer f1 = hotel.getCustomers().at(0); //"Mathew", "1234567890", "Addr1"
        Room r1 = hotel.getRooms().at(0); //Room(101, 2)

        switch (choice) {
            case 1: {
                // Book a room
                // ...
                hotel.bookRoom(f1, r1.getNumber());
                break;
            }
            case 2: {
                // Book a service
                // ...
                hotel.bookService(f1, "Restaurant");
                break;
            }
            case 3: {
                // Check out
                // ...
                hotel.makePayment(f1);
                hotel.releaseRoom(f1, r1.getNumber());
                hotel.releaseService(f1, "Restaurant");
                break;
            }
            case 4: {
                // Show rooms status
                // ...
                hotel.showRoomStatus();
                break;
            }
            case 5: {
                // Show customer list
                // ...
                hotel.showCustomerList();
                break;
            }
            case 6: {
                // Show reports and statistics
                // ...
                hotel.showReportsAndStatistics();
                break;
            }
            case 0: {
                std::cout << "Exiting the program." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }

    } while (choice != 0);

    return 0;
}