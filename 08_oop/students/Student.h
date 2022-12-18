#pragma once
#include <string>
#include <iostream>

// класс Student, который содержит имя и оценку студента
class Student
{
private:
    std::string name;
    int mark; // оценка

public:
    Student();
    Student(const std::string &name, int mark);
    ~Student();

    std::string getName() const;
    int getMark() const;
    void setMark(int mark);
    bool operator==(const Student &other) const;
    bool operator!=(const Student &other) const;
};

inline std::ostream &operator<<(std::ostream &out, const Student &student)
{
    out << student.getName() << " " << student.getMark();
    return out;
}