//#include <iostream>
//#include <string>
#include <fstream>
//#include <iomanip>
#include "Student.h"
using namespace std;
//class Student
//{
//public:
//    std::string first_name;
//    std::string second_name;
//    int id;
//    std::string department;
//    Student()
//    :first_name{"None"},second_name{"None"},id{0},department{"None"}
//    {}
//    Student(std::string a,std::string b,int c,std::string d)
//    :first_name{a},second_name{b},id{c},department{d}
//    {}
//    ~Student()
//    {}
//    Student(Student &source)
//    :first_name{source.first_name},second_name{source.second_name},id{source.id},department{source.department}
//    {}
//    friend ostream &operator<<(ostream &obj,const Student &source);
//    friend istream &operator>>(istream &obj,Student &source);
//};
//ostream &operator<<(ostream &obj,const Student &source)
//{
//    obj<<std::setw(12)<<std::left<<source.first_name<<std::setw(12)<<std::left<<source.second_name<<std::setw(12)<<std::left<<source.id<<std::setw(12)<<std::left<<source.department;
//    return obj;
//}
//istream &operator>>(istream &obj,Student &source)
//{
//    std::string a;
//    std::string b;
//    int c;
//    std::string d;
//    std::cout<<std::endl<<"Enter First Name: ";
//    std::getline(cin,a);
//    std::cout<<std::endl<<"Enter Last Name(Surname): ";
//    std::getline(cin,b);
//    std::cout<<std::endl<<"Enter Id: ";
//    obj>>c;
//    std::cout<<std::endl<<"Enter Department: ";
//    obj>>d;
//    source = Student(a,b,c,d);
//    return obj;
//}
void add_data(std::string a,std::string b,int c,std::string d)
{
    std::ofstream obj{"./original.dat",std::ios::binary|std::ios::out|std::ios::app};//opening file to write in append mode
    if(!obj)//File has opened or not
    {
        std::cerr<<std::endl<<"Error opening file";//If not open
    }
    else
    {
        Student *temp = new Student(a,b,c,d);
        obj<<*temp<<std::endl;
        delete temp;
        obj.close();
    }
}
void display_data()
{
//    system("cls");
    std::ifstream obj{"./original.dat",std::ios::binary|std::ios::in};
    if(!obj)
    {
        std::cerr<<std::endl<<"Error opening files";
    }
    else
    {
        std::string str;
        std::cout<<std::endl<<std::setw(12)<<std::left<<"First Name"<<std::setw(12)<<std::left<<"Last Name"<<std::setw(10)<<std::left<<"User Id"<<std::setw(12)<<std::left<<"Department"<<std::endl;
        while(std::getline(obj,str))
        {
            std::cout<<str<<std::endl;
        }
        obj.close();
    }
}
void copy_records()
{
    std::ifstream obj1{"./original.dat",std::ios::binary|std::ios::in};
    std::ofstream obj2{"./temporary.dat",std::ios::binary|std::ios::out|std::ios::trunc};
    if(!obj1 && !obj2)
    {
        std::cerr<<std::endl<<"Error opening files";
    }
    else
    {
        std::string str;
        while(std::getline(obj1,str))
        {
            obj2<<str<<std::endl;
        }
    }
    obj1.close();
    obj2.close();
}
void delete_record(std::string a,std::string b,int c,std::string d)
{
    std::ifstream obj1{"./original.dat",std::ios::binary|std::ios::in};
    std::ofstream obj2{"./temporary.dat",std::ios::binary|std::ios::out|std::ios::trunc};
    if(!obj1 && !obj2)
    {
        std::cerr<<std::endl<<"Error opening files";
    }
    else
    {
      std::string str;
      while(std::getline(obj1,str))
      {
          obj2<<str<<std::endl;
      }
    }
    obj1.close();
    obj2.close();
    std::ofstream obj3{"./original.dat",std::ios::binary|std::ios::out|std::ios::trunc};
    std::ifstream obj4{"./temporary.dat",std::ios::binary|std::ios::in};
    if(!obj3 && !obj4)
    {
        std::cerr<<std::endl<<"Error opening files";
    }
    else
    {
        std::string a1;
        std::string b1;
        int c1;
        std::string d1;
        Student *temp{nullptr};
        while(obj4>>a1>>b1>>c1>>d1)
        {
            if(a1 == a && b1 == b && c1 == c && d1 == d)
            {
                continue;
            }
            else
            {
                temp = new Student(a1,b1,c1,d1);
                obj3<<*temp<<std::endl;
            }
        }
        delete temp;
    }
    obj3.close();
    obj4.close();
}
void clear_data()
{
    std::ofstream obj{"./original.dat",std::ios::binary|std::ios::out|std::ios::trunc};
    obj.close();
}
bool check_data()
{
    
}
void menu()
{
    int num{};
    while(1)
    {
        std::cout<<std::endl<<"1. Display records";
        std::cout<<std::endl<<"2. Add a new record";
        std::cout<<std::endl<<"3. Delete a record";
        std::cout<<std::endl<<"4. Clear all records";
        std::cout<<std::endl<<"5. Clear the screen";
    }
    system("cls");//Clear screen
}
int main()
{
	//code starts here
    clear_data();
    add_data("ayush","upadhyay",1234,"mechanical");
    add_data("akku","upadhyay",4150,"computer");
    add_data("ayushi","upadhyay",4126,"commerce");
    display_data();
    delete_record("ayush","upadhyay",1234,"mechanical");
    cout<<endl;
    display_data();
	return 0;
}
