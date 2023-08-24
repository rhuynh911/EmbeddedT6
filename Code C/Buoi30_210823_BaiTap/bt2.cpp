#include <iostream>

class Wheel {
private:
    double speed;

public:
    Wheel() : speed(0) {}

    void setSpeed(double newSpeed) {
        speed = newSpeed;
    }

    double getSpeed() const {
        return speed;
    }
};

class Car {
private:
    Wheel wheel;
    double weight;
    double passengerWeight;

public:
    Car() : weight(1000), passengerWeight(0) {}

    void setWeight(double newWeight) {
        weight = newWeight;
    }

    void addPassenger(double passengerWeight) {
        this->passengerWeight += passengerWeight;
    }

    double getTotalWeight() const {
        return weight + passengerWeight;
    }

    double getWeight() const {
        return weight;
    }

    double getWheelSpeed() const {
        return this->wheel.getSpeed();
    }

    double getPassengerWeight() const {
        return passengerWeight;
    }
};

class ABS {
private:
    Car car;

public:
    ABS(const Car &car) : car(car) {}

    void applyBrakes() {
        double wheelSpeed = car.getWheelSpeed();
        double totalWeight = car.getTotalWeight();

        // Logic to adjust brake force based on wheel speed and total weight
        double brakeForce = calculateBrakeForce(wheelSpeed, totalWeight);

        if (brakeForce > 0.8) {
            std::cout << "Brake force adjusted to prevent wheel lock-up." << std::endl;
        } else {
            std::cout << "Brakes applied normally." << std::endl;
        }
    }
private:
    double calculateBrakeForce(double wheelSpeed, double totalWeight) {
        // Your implementation here
        // This could be a formula that considers wheel speed and total weight
        // You might want to use mathematical calculations or lookup tables

        // For demonstration purposes, let's use a simple linear relationship
        double maxBrakeForce = 1.0; // Maximum brake force allowed
        double minBrakeForce = 0.2; // Minimum brake force allowed

        double brakeForce = minBrakeForce + ((maxBrakeForce - minBrakeForce) * (wheelSpeed / 100.0));

        // Adjust brake force based on total weight
        brakeForce *= (1.0 - (totalWeight / 2000.0)); // Reduce brake force as weight increases

        return brakeForce;
    }
};

int main() {
    Car car;
    Wheel wheel;
    ABS abs(car);

    wheel.setSpeed(8); // Simulating wheel speed for testing
    car.setWeight(1100); // Simulating additional weight for testing
    car.addPassenger(70); // Adding passenger weight for testing

    abs.applyBrakes();

    return 0;
}
