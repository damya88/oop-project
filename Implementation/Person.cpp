#include <iostream>
#include <stdexcept>
#include "Person.h"

Person::Person(long ID, std::string fn, int a)
{
    setId(ID);
    setFullName(fn);
    setAge(a);
}

void Person::setId(long ID)
{
    if (ID < 0)
    {
        throw std::invalid_argument("Negative id");
    }
    id = ID;
}

long Person::getId() const
{
    return id;
}

void Person::setFullName(std::string fn)
{
    if (fn == "")
    {
        throw std::invalid_argument("NO name!");
    }
    fullName = fn;
}

std::string Person::getFullName() const
{
    return fullName;
}

void Person::setAge(int a)
{
    if (a < 0)
    {
        throw std::invalid_argument("Negative id");
    }
    age = a;
}

int Person::getAge() const
{
    return age;
}

void Person::display()const{
    std::cout<<"Full Name : "<<getFullName()<<std::endl;
    std::cout<<"ID : "<<getId()<<std::endl;
    std::cout<<"Age : "<<getAge()<<std::endl;
}
