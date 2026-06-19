#include <iostream>
#include "Dormitory.h"
#include <stdexcept>

Dormitory::Dormitory(int rc, int sc)
{
    setStudentCapacity(sc);
    setRoomCapacity(rc);
}

void Dormitory::setStudentCapacity(int sc)
{
    if (sc <= 0)
        throw std::invalid_argument("Not valid");

    studentCapacity = sc;
}

int Dormitory::getStudentCapacity() const
{
    return studentCapacity;
}

void Dormitory::setRoomCapacity(int rc)
{
    if (rc <= 0)
        throw std::invalid_argument("Not valid");

    roomCapacity = rc;
}

int Dormitory::getRoomCapacity() const
{
    return roomCapacity;
}

void Dormitory::setName(std::string n){
    name=n;
}

std::string Dormitory::getName()const{
    return name;
}

bool Dormitory::addStudent(Student* s)
{
    if (students.size() >= studentCapacity)
        return false;

    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i]->getId() == s->getId())
            return false;
    }

    students.push_back(s);
    return true;
}

bool Dormitory::removeStudent(Student* s)
{
    int index = -1;

    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i] == s)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        return false;

    students.erase(students.begin() + index);
    return true;
}

bool Dormitory::addRoom(Room* r)
{
    if (rooms.size() >= roomCapacity)
        return false;

    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i]->getRoomNum() == r->getRoomNum())
            return false;
    }

    rooms.push_back(r);
    return true;
}

bool Dormitory::removeRoom(Room* r)
{
    int index = -1;

    for (size_t i = 0; i < rooms.size(); i++)
    {
        if (rooms[i]->getRoomNum() == r->getRoomNum())
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        return false;

    rooms.erase(rooms.begin() + index);
    return true;
}

bool Dormitory::addStudentToRoom(Student* s, Room* r)
{
    if (r->isFull())
        return false;

    // check student exists in dormitory
    bool exists = false;
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i] == s)
        {
            exists = true;
            break;
        }
    }

    if (!exists)
        return false;

    // check student is not already in a room
    for (size_t i = 0; i < rooms.size(); i++)
    {
        if (s->getRoomNumber() == rooms[i]->getRoomNum())
            return false;
    }

    // safe assignment
    if (r->addStudent(s))
    {
        s->setRoomNumber(r->getRoomNum());
        return true;
    }

    return false;
}

bool Dormitory::removeStudentFromRoom(Student* s, Room* r)
{
    if (s->getRoomNumber() != r->getRoomNum())
        return false;

    bool removed = r->removeStudent(s);

    if (removed)
    {
        s->setRoomNumber(0);
        return true;
    }

    return false;
}

void Dormitory::displayAvailable() const
{
    for (size_t i = 0; i < rooms.size(); i++)
    {
        if (!rooms[i]->isFull())
        {
            std::cout << "Room " << rooms[i]->getRoomNum() << std::endl;
        }
    }
}

void Dormitory::displayOccupied() const
{
    for (size_t i = 0; i < rooms.size(); i++)
    {
        if (rooms[i]->getOccupants() > 0)
        {
            std::cout << "Room " << rooms[i]->getRoomNum() << std::endl;
        }
    }
}

std::vector<Room*> Dormitory::getRooms() const
{
    return rooms;
}

void Dormitory::DisplayMenu(int day)const{
    rest.PrintDayMenu(day);
}
