#include "Room.hpp"

Room::Room(int number, int capacity) : number(number), capacity(capacity), status(Status::Available) {}

void Room::setStatus(Status status) {
    this->status = status;
}

Room::Status Room::getStatus() const {
    return status;
}

int Room::getNumber() const{
    return number;
}

int Room::getCapacity() const{
    return capacity;
}
