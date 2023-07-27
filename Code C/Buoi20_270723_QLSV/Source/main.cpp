#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "../Header/student.hpp"
#include <cassert>
#include <cstring> // Thêm thư viện để sử dụng hàm strcmp()

using namespace std;

vector<Student> studentList;

// Các hàm thêm, sửa, xóa, tìm kiếm, sắp xếp và hiển thị sinh viên ở đây

bool isValidGender(char gender) {
    return (gender == 'M' || gender == 'F');
}

void readFile() {
    ifstream file("student.txt");
    if (!file.is_open()) {
        cout << "Khong the doc file student.txt" << endl;
        return;
    }

    int id, age;
    string name;
    char gender;
    double math, physics, chemistry;

    while (file >> id >> name >> gender >> age >> math >> physics >> chemistry) {
        Student student(id, name, gender, age, math, physics, chemistry);
        studentList.push_back(student);
    }
    file.close();
}

void writeFile() {
    ofstream file("student.txt");
    if (!file.is_open()) {
        cout << "Khong the ghi file student.txt" << endl;
        return;
    }

    for (const auto& student : studentList) {
        file << student.id << " " << student.name << " " << student.gender << " " << student.age
             << " " << student.mathScore << " " << student.physicsScore << " " << student.chemistryScore << endl;
    }
    file.close();
}

void addStudent() {
    int id, age;
    string name;
    char gender;
    double math, physics, chemistry;

    cout << "Nhap ID sinh vien: ";
    cin >> id;

    cin.ignore();
    cout << "Nhap ten sinh vien: ";
    getline(cin, name);

    cout << "Nhap gioi tinh (M/F): ";
    cin >> gender;

    cout << "Nhap tuoi sinh vien: ";
    cin >> age;

    cout << "Nhap diem Toan: ";
    cin >> math;

    cout << "Nhap diem Ly: ";
    cin >> physics;

    cout << "Nhap diem Hoa: ";
    cin >> chemistry;

    assert(!name.empty() && "Ten khong duoc rong");
    if (!isValidGender(gender)) {
        assert("Gioi tinh nhap sai");
    }
    assert(age > 0 && "Tuoi phai lon hon 0");
    assert(math >= 0 && math <= 10 && "Diem toan phai giua 0 va 10");
    assert(physics >= 0 && physics <= 10 && "Diem ly phai giua 0 va 10");
    assert(chemistry >= 0 && chemistry <= 10 && "Diem hoa phai giua 0 va 10");

    Student student(id, name, gender, age, math, physics, chemistry);
    studentList.push_back(student);
}

void updateStudent() {
    int id;
    cout << "Nhap ID sinh vien can cap nhap thong tin: ";
    cin >> id;

    auto it = find_if(studentList.begin(), studentList.end(), [&id](const Student& s) { return s.id == id; });

    if (it != studentList.end()) {
        int choice;
        cout << "Thong tin sinh vien hien tai:" << endl;
        cout << "Ten: " << it->name << endl;
        cout << "Tuoi: " << it->age << endl;
        cout << "Gioi tinh: " << it->gender << endl;
        cout << "Diem Toan: " << it->mathScore << endl;
        cout << "Diem Ly: " << it->physicsScore << endl;
        cout << "Diem Hoa: " << it->chemistryScore << endl;

        cout << "Ban muon cap nhap thong tin nao?" << endl;
        cout << "1. Ten" << endl;
        cout << "2. Tuoi" << endl;
        cout << "3. Gioi tinh" << endl;
        cout << "4. Diem Toan" << endl;
        cout << "5. Diem Ly" << endl;
        cout << "6. Diem Hoa" << endl;
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cin.ignore();
            cout << "Nhap ten moi: ";
            string newName;
            getline(cin, newName);
            it->name = newName;
            break;
        }
        case 2: {
            cout << "Nhap tuoi moi: ";
            int newAge;
            cin >> newAge;
            it->age = newAge;
            break;
        }
        case 3: {
            cout << "Nhap gioi tinh moi (M/F): ";
            char newGender;
            cin >> newGender;
            it->gender = newGender;
            break;
        }
        case 4: {
            cout << "Nhap diem Toan moi: ";
            double newMath;
            cin >> newMath;
            it->mathScore = newMath;
            it->averageScore = (it->mathScore + it->physicsScore + it->chemistryScore) / 3.0;
            it->calculateAcademicPerformance();
            break;
        }
        case 5: {
            cout << "Nhap diem Ly moi: ";
            double newPhysics;
            cin >> newPhysics;
            it->physicsScore = newPhysics;
            it->averageScore = (it->mathScore + it->physicsScore + it->chemistryScore) / 3.0;
            it->calculateAcademicPerformance();
            break;
        }
        case 6: {
            cout << "Nhap diem Hoa moi: ";
            double newChemistry;
            cin >> newChemistry;
            it->chemistryScore = newChemistry;
            it->averageScore = (it->mathScore + it->physicsScore + it->chemistryScore) / 3.0;
            it->calculateAcademicPerformance();
            break;
        }
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
        cout << "Cap nhap thong tin sinh vien thanh cong!" << endl;
    } else {
        cout << "Khong tim thay sinh vien co ID nay!" << endl;
    }
}

void deleteStudent() {
    int id;
    cout << "Nhap ID sinh vien can xoa: ";
    cin >> id;

    auto it = find_if(studentList.begin(), studentList.end(), [&id](const Student& s) { return s.id == id; });

    if (it != studentList.end()) {
        studentList.erase(it);
        cout << "Xoa sinh vien thanh cong!" << endl;
    } else {
        cout << "Khong tim thay sinh vien co ID nay!" << endl;
    }
}

void searchStudentByName() {
    string name;
    cout << "Nhap ten sinh vien can tim: ";
    cin.ignore();
    getline(cin, name);

    vector<Student> result;
    for (const auto& student : studentList) {
        if (student.name == name) {
            result.push_back(student);
        }
    }

    if (result.empty()) {
        cout << "Khong tim thay sinh vien co ten nay!" << endl;
    } else {
        cout << "Ket qua tim kiem:" << endl;
        for (const auto& student : result) {
            cout << "ID: " << student.id << ", Ten: " << student.name << ", Gioi tinh: " << student.gender
                 << ", Tuoi: " << student.age << ", Diem Trung binh: " << student.averageScore
                 << ", Hoc luc: " << student.academicPerformance << endl;
        }
    }
}

bool compareByAverageScore(const Student& s1, const Student& s2) {
    return s1.averageScore > s2.averageScore;
}

bool compareByName(const Student& s1, const Student& s2) {
    return s1.name < s2.name;
}

void sortByGPA() {
    sort(studentList.begin(), studentList.end(), compareByAverageScore);
    cout << "Danh sach sinh vien sau khi sap xep theo diem trung binh (GPA):" << endl;
    for (const auto& student : studentList) {
        cout << "ID: " << student.id << ", Ten: " << student.name << ", Diem Trung binh: " << student.averageScore
             << ", Hoc luc: " << student.academicPerformance << endl;
    }
}

void sortByName() {
    sort(studentList.begin(), studentList.end(), compareByName);
    cout << "Danh sach sinh vien sau khi sap xep theo ten:" << endl;
    for (const auto& student : studentList) {
        cout << "ID: " << student.id << ", Ten: " << student.name << ", Diem Trung binh: " << student.averageScore
             << ", Hoc luc: " << student.academicPerformance << endl;
    }
}

void displayStudentList() {
    cout << "Danh sach sinh vien:" << endl;
    for (const auto& student : studentList) {
        cout << "ID: " << student.id << ", Ten: " << student.name << ", Gioi tinh: " << student.gender
             << ", Tuoi: " << student.age << ", Diem Trung binh: " << student.averageScore
             << ", Hoc luc: " << student.academicPerformance << endl;
    }
}

int main() {
    // Đọc và ghi file ở đây

    readFile();

    int choice;
    while (true) {
        cout << "\nMENU:" << endl;
        cout << "1. Them sinh vien." << endl;
        cout << "2. Cap nhap thong tin sinh vien theo ID." << endl;
        cout << "3. Xoa sinh vien theo ID." << endl;
        cout << "4. Tim kiem sinh vien theo ten." << endl;
        cout << "5. Sap xep danh sach sinh vien theo diem trung binh (GPA)." << endl;
        cout << "6. Sap xep danh sach sinh vien theo ten." << endl;
        cout << "7. Hien thi danh sach sinh vien." << endl;
        cout << "8. Ghi danh sach sinh vien vao file 'student.txt'." << endl;
        cout << "9. Thoat chuong trinh." << endl;
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            updateStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            searchStudentByName();
            break;
        case 5:
            sortByGPA();
            break;
        case 6:
            sortByName();
            break;
        case 7:
            displayStudentList();
            break;
        case 8:
            writeFile();
            cout << "Ghi danh sach sinh vien vao file 'student.txt' thanh cong!" << endl;
            break;
        case 9:
            return 0;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    }

    return 0;
}
