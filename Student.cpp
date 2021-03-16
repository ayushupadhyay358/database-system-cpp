#include "Student.h"

std::ostream &operator<<(std::ostream &obj,const Student &source)
{
    obj<<std::setw(12)<<std::left<<source.first_name<<std::setw(12)<<std::left<<source.second_name<<std::setw(10)<<std::left<<source.id<<std::setw(12)<<std::left<<source.department;
    return obj;
}
std::istream &operator>>(std::istream &obj,Student &source)
{
    std::string a;
    std::string b;
    int c;
    std::string d;
    std::cout<<std::endl<<"Enter First Name: ";
    std::getline(std::cin,a);
    std::cout<<std::endl<<"Enter Last Name(Surname): ";
    std::getline(std::cin,b);
    std::cout<<std::endl<<"Enter Id: ";
    obj>>c;
    std::cout<<std::endl<<"Enter Department: ";
    obj>>d;
    source = Student(a,b,c,d);
    return obj;
}

