#include "student.hpp"

Student::Student(int _id, std::string _name, char _gender, int _age, double _math, double _physics, double _chemistry) {
    id = _id;
    name = _name;
    gender = _gender;
    age = _age;
    mathScore = _math;
    physicsScore = _physics;
    chemistryScore = _chemistry;
    averageScore = (_math + _physics + _chemistry) / 3.0;
    calculateAcademicPerformance();
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
