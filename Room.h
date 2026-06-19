#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include "Student.h"

class Room {

private:
    int roomNum;
    int capacity;
    std::vector<Student*> occupants; //vector of pointers to students
public:
    Room(int=0,int=0);

    void setRoomNum(int);
    int getRoomNum()const;

    void setCapacity(int);
    int getCapacity()const;

    void setRoom(int,int);

    int getOccupants()const;

    bool isFull()const ;

    bool addStudent(Student*);
    bool removeStudent(Student*);

    std::vector<Student*> getOccupantsList() const;

};
#endif // ROOM_H
