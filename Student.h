#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Person.h"




class Student : public Person
{

private:
    int academicYear;
    int roomNumber;

public:
    Student(long,std::string,int=0,int=0,int=0);
    void setAcademicYear(int);
    int getAcademicYear()const;
    void setRoomNumber(int);
    int getRoomNumber()const;
    void display() const override;

};
#endif // STUDENT_H
