#include <iostream>

class DCMotor {
private:
    double voltage;
    double maxCurrent;
    double speed;
    bool isRunning;
    
public:

    DCMotor(double v, double maxCurr) : voltage(v), maxCurrent(maxCurr), speed(0.0), isRunning(false), direction(CLOCKWISE) {}

    enum Direction { CLOCKWISE, COUNTERCLOCKWISE };

    Direction direction;

    void setSpeed(double spd) {
        speed = spd;
        std::cout << "Speed set to: " << speed << std::endl;
    }

    void setDirection(Direction dir) {
        direction = dir;
        std::cout << "Direction set to: " << (dir == CLOCKWISE ? "CLOCKWISE" : "COUNTERCLOCKWISE") << std::endl;
    }

    void start() {
        isRunning = true;
        std::cout << "Motor started." << std::endl;
    }

    void stop() {
        isRunning = false;
        std::cout << "Motor stopped." << std::endl;
    }
};

class FeedbackSystem {
public:
    bool overloadDetected(double current) {
        // Compare current with maxCurrent to detect overload
        if (current > maxCurrent) {
            std::cout << "Overload detected." << std::endl;
            return true;
        }
        return false;
    }

    bool overheatDetected(double temperature) {
        // Compare temperature with threshold to detect overheat
        if (temperature > maxTemperatureThreshold) {
            std::cout << "Overheat detected." << std::endl;
            return true;
        }
        return false;
    }

private:
    double maxCurrent = 5.0; // Set your max current threshold here
    double maxTemperatureThreshold = 80.0; // Set your max temperature threshold here
};

class DCMotorController {
private:
    DCMotor motor;
    FeedbackSystem feedback;

public:
    DCMotorController(double voltage, double maxCurrent) : motor(voltage, maxCurrent) {};

    void setDirection(DCMotor::Direction direction) {
        motor.setDirection(direction); // Now this is allowed
    }
    
    void controlMotor(){
        if (feedback.overloadDetected(2.2) || feedback.overheatDetected(2.3)) {
            motor.stop();
        } else {
            motor.start();
            motor.setSpeed(50.0); // Set speed to 50% for demonstration
            motor.setDirection(DCMotor::CLOCKWISE); // Set direction to CLOCKWISE
        }
    }
};

int main() {
    DCMotorController motorController(12.0, 5.0); // Initialize with voltage and max current
    motorController.controlMotor(); // Control the motor based on feedback

    return 0;
}
