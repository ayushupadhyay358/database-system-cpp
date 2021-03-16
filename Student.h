#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <iomanip>
class Student
{
public:
    std::string first_name;
    std::string second_name;
    int id;
    std::string department;
    Student()
    :first_name{"None"},second_name{"None"},id{0},department{"None"}
    {}
    Student(std::string a,std::string b,int c,std::string d)
    :first_name{a},second_name{b},id{c},department{d}
    {}
    ~Student()
    {}
    Student(Student &source)
    :first_name{source.first_name},second_name{source.second_name},id{source.id},department{source.department}
    {}
    friend std::ostream &operator<<(std::ostream &obj,const Student &source);
    friend std::istream &operator>>(std::istream &obj,Student &source);
};

#endif // STUDENT_H
