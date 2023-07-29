#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
private:
    int id;
    std::string name;
    char gender;
    int age;
    double mathScore;
    double physicsScore;
    double chemistryScore;
    double averageScore;
    std::string academicPerformance;

public:
    // Constructor
    Student(int _id, std::string _name, char _gender, int _age, double _math, double _physics, double _chemistry);

    // Getter methods
    int getId() const;
    std::string getName() const;
    char getGender() const;
    int getAge() const;
    double getMathScore() const;
    double getPhysicsScore() const;
    double getChemistryScore() const;
    double getAverageScore() const;
    std::string getAcademicPerformance() const;

    // Setter methods
    void setId(int _id);
    void setName(std::string _name);
    void setGender(char _gender);
    void setAge(int _age);
    void setMathScore(double _math);
    void setPhysicsScore(double _physics);
    void setChemistryScore(double _chemistry);
    void setAverageScore(double _average);
    void setAcademicPerformance(std::string _academicPerformance);

    // Other methods
    void calculateAverageScore();
    void calculateAcademicPerformance();
};

#endif // STUDENT_HPP
