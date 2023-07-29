#include "student.hpp"

// Constructor
Student::Student(int _id, std::string _name, char _gender, int _age, double _math, double _physics, double _chemistry) {
    setId(_id);
    setName(_name);
    setGender(_gender);
    setAge(_age);
    setMathScore(_math);
    setPhysicsScore(_physics);
    setChemistryScore(_chemistry);
    calculateAverageScore();
    calculateAcademicPerformance();
}

// Getter methods
int Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

char Student::getGender() const {
    return gender;
}

int Student::getAge() const {
    return age;
}

double Student::getMathScore() const {
    return mathScore;
}

double Student::getPhysicsScore() const {
    return physicsScore;
}

double Student::getChemistryScore() const {
    return chemistryScore;
}

double Student::getAverageScore() const {
    return averageScore;
}

std::string Student::getAcademicPerformance() const {
    return academicPerformance;
}

// Setter methods
void Student::setId(int _id) {
    id = _id;
}

void Student::setName(std::string _name) {
    name = _name;
}

void Student::setGender(char _gender) {
    gender = _gender;
}

void Student::setAge(int _age) {
    age = _age;
}

void Student::setMathScore(double _math) {
    mathScore = _math;
}

void Student::setPhysicsScore(double _physics) {
    physicsScore = _physics;
}

void Student::setChemistryScore(double _chemistry) {
    chemistryScore = _chemistry;
}

void Student::setAverageScore(double _average) {
    averageScore = _average;
}

void Student::setAcademicPerformance(std::string _academicPerformance) {
    academicPerformance = _academicPerformance;
}

// Other methods
void Student::calculateAverageScore() {
    averageScore = (mathScore + physicsScore + chemistryScore) / 3.0;
}

void Student::calculateAcademicPerformance() {
    if (averageScore >= 8.0)
        academicPerformance = "Giỏi";
    else if (averageScore >= 6.5)
        academicPerformance = "Khá";
    else if (averageScore >= 5.0)
        academicPerformance = "Trung bình";
    else
        academicPerformance = "Yếu";
}
