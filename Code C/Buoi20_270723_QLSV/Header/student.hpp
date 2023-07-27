#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
public:
    int id;
    std::string name;
    char gender;
    int age;
    double mathScore;
    double physicsScore;
    double chemistryScore;
    double averageScore;
    std::string academicPerformance;

    Student(int _id, std::string _name, char _gender, int _age, double _math, double _physics, double _chemistry);

    void calculateAcademicPerformance();
};

#endif // STUDENT_HPP
