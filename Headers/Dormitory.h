#ifndef DORMITORY_H
#define DORMITORY_H
#include <vector>
#include "Room.h"
#include "Student.h"
#include "Restaurant.h"

class Dormitory
{
private:
    int roomCapacity;      // maximum number of rooms
    int studentCapacity;   // maximum number of students
    std::string name; // name of the dormitory

    std::vector<Room*> rooms;
    std::vector<Student*> students;

public:
    Dormitory(int , int );

    //Each dormitory has exactly one restaurant
    Restaurant rest ;

    void setStudentCapacity(int);
    int getStudentCapacity() const;

    void setRoomCapacity(int);
    int getRoomCapacity() const;

    std::vector<Room*> getRooms() const;

    void setName(std::string);
    std::string getName()const;

    bool addStudent(Student*);
    bool removeStudent(Student*);

    bool addRoom(Room*);
    bool removeRoom(Room*);

    bool addStudentToRoom(Student*, Room*);
    bool removeStudentFromRoom(Student*, Room*);

    void displayOccupied() const;
    void displayAvailable() const;

    void DisplayMenu(int)const;
};
#endif // DORMITORY_H
