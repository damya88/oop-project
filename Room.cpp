#include <iostream>
#include "Room.h"
#include <stdexcept>

Room::Room(int num,int c){
    setRoomNum(num);
    setCapacity(c);
}

void Room::setRoomNum(int n){
    if(n<0){
        throw std::invalid_argument("Room number can't be negative") ;
    }
    roomNum=n;
}

int Room::getRoomNum()const{
    return roomNum;
}

void Room::setCapacity(int c){
    if(c<0){
        throw std::invalid_argument("Capacity can't be negative") ;
    }
    capacity=c;
}

int Room::getCapacity()const{
    return capacity;
}

void Room::setRoom(int num,int c){
    setRoomNum(num);
    setCapacity(c);
}

int Room::getOccupants()const{
    return occupants.size();
}

bool Room::isFull()const{
    return (capacity<=occupants.size());
}

bool Room::addStudent(Student* s)
{
    if (isFull())
    {
        return false;
    }

    for (size_t i = 0; i < occupants.size(); i++)
    {
        if (occupants[i] == s)
        {
            return false;
        }
    }

    occupants.push_back(s);
    return true;
}

bool Room::removeStudent(Student* s)
{
    for (size_t i = 0; i < occupants.size(); i++)
    {
        if (occupants[i] == s)
        {
            occupants.erase(occupants.begin() + i);
            return true;
        }
    }

    return false;
}

std::vector<Student*> Room::getOccupantsList() const
{
    return occupants;
}