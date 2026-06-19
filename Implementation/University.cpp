#include <iostream>
#include "University.h"
#include "stdexcept"
#include <fstream>
#include <sstream>

University::University(int c){
    setCapacity(c);
}

void University::setCapacity(int c){
    if(c<0){
        throw std::invalid_argument("Not valid");
    }
    capacity=c;
}

int University::getCapacity() const
{
    return capacity;
}

bool University::addDormitory(Dormitory* d){
    if(univers.size()>=getCapacity()){
        return false;
    }

    univers.push_back(d);
    return true;
}

void University::displayDormitories()const{
    for(size_t i=0;i<univers.size();i++){
        std::cout<<"Dormitory "<<i<<" "<<univers[i]->getName()<<std::endl;
    }
}

Dormitory* University::findDormitory(const std::string& n)const{
    for(size_t i=0;i<univers.size();i++){
        if(univers[i]->getName()==n){
            return univers[i];
        }
    }
    return nullptr;
}

bool University::found(Dormitory* d)const{
    if(findDormitory(d->getName())==nullptr){
        return false;
    }
    return true;
}

Room* University::findRoom(int roomNum, const std::string& dormName)
{
    Dormitory* d = findDormitory(dormName);

    if (!d)
        return nullptr;

    std::vector<Room*> rooms = d->getRooms();

    for (size_t i = 0; i < rooms.size(); i++)
    {
        if (rooms[i]->getRoomNum() == roomNum)
            return rooms[i];
    }

    return nullptr;
}


void University::loadFromFiles()
{
    univers.clear();

    std::ifstream dormFile("dormitories.txt");
    std::ifstream roomFile("rooms.txt");
    std::ifstream studentFile("students.txt");

    if (!dormFile || !roomFile || !studentFile)
        throw std::runtime_error("Cannot open files for reading");

    // Load Dormitories
    std::string name;
    int sc, rc;

    while (dormFile >> name >> sc >> rc)
    {
        Dormitory* d = new Dormitory(rc, sc);
        d->setName(name);
        univers.push_back(d);
    }

    // Load Rooms
    std::string dormName;
    int roomNum, cap;

    while (roomFile >> dormName >> roomNum >> cap)
    {
        Dormitory* d = findDormitory(dormName);
        if (!d) continue;

        Room* r = new Room(roomNum, cap);
        d->addRoom(r);
    }

    // Load Students
    std::string dormName2;
    long id;
    std::string fullName;
    int age, year, roomNumber;

    while (studentFile >> dormName2 >> id >> fullName >> age >> year >> roomNumber)
    {
        Dormitory* d = findDormitory(dormName2);
        if (!d) continue;

        Student* s = new Student(id, fullName, age, year, roomNumber);
        d->addStudent(s);

        Room* r = findRoom(roomNumber, dormName2);
        if (r)
        {
            r->addStudent(s);
        }
    }
}


void University::saveToFiles() const
{
    std::ofstream dormFile("dormitories.txt");
    std::ofstream roomFile("rooms.txt");
    std::ofstream studentFile("students.txt");

    if (!dormFile || !roomFile || !studentFile)
        throw std::runtime_error("Cannot open files for writing");

    // Save Dormitories
    for (Dormitory* d : univers)
    {
        dormFile << d->getName() << " "
                 << d->getStudentCapacity() << " "
                 << d->getRoomCapacity() << "\n";

        // Rooms
        for (Room* r : d->getRooms())
        {
            roomFile << d->getName() << " "
                     << r->getRoomNum() << " "
                     << r->getCapacity() << "\n";

            // Students in room
            for (Student* s : r->getOccupantsList())
            {
                studentFile << d->getName() << " "
                            << s->getId() << " "
                            << s->getFullName() << " "
                            << s->getAge() << " "
                            << s->getAcademicYear() << " "
                            << r->getRoomNum() << "\n";
            }
        }
    }
}
