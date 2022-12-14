#pragma once
#include <vector>
#include "Student.h"

// StudenList, который содержит список студентов (используйте массив)
// класс StudenList методы, позволяющие добавить студента, удалить студента, поставить оценку студенту,
// получить среднюю оценку студентов, спиоск лучших студентов (высокая оценка), список худших студентов (низка оценка)

class StudentList
{
public:
    StudentList();
    ~StudentList();
    int getSize() const;
    Student getStudent(int index) const;
    void addStudent(Student *student);
    void removeStudent(Student *student);
    void giveMark(Student *student, int mark);
    double getAverageMark();
    StudentList getBestStudents();
    StudentList getWorstStudents();

private:
    Student *students;
    int size;
};

inline std::ostream &operator<<(std::ostream &out, const StudentList &list)
{
    for (int i = 0; i < list.getSize(); i++)
    {
        out << list.getStudent(i) << std::endl;
    }
    return out;
}