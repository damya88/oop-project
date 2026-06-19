#include <iostream>
#include "Student.h"
#include <stdexcept>



Student::Student(long ID, std::string fn, int a,int year,int rn)
    :Person(ID,fn,a)
{
    setAcademicYear(year);
    setRoomNumber(rn);
}

void Student::setAcademicYear(int year){
    if(year<0){
        throw std::invalid_argument("Year can't negative !") ;
    }

    academicYear=year;
}

int Student::getAcademicYear()const{
    return academicYear;
}

void Student::setRoomNumber(int rn){
    if(rn<0){
        throw std::invalid_argument("not valid");
    }
    roomNumber=rn;
}

int Student::getRoomNumber()const{
    return roomNumber;
}

void Student::display()const{
    Person::display();
    std::cout<<"Academic Year : "<<getAcademicYear()<<std::endl;
    std::cout<<"Room number : "<<getRoomNumber()<<std::endl;

}