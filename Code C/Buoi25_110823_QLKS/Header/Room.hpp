#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include "Customer.hpp"

class Room {
public:
    enum class Status { Booked, Available, Cleaning };
    Room(int number, int capacity);
    void setStatus(Status status);
    Status getStatus() const;
    int getNumber() const;
    int getCapacity() const;
private:
    int number;
    int capacity;
    Status status;
};

#endif
