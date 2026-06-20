#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <vector>
#include "Dormitory.h"
#include <string>

class University{

private:
    std::vector<Dormitory*> univers;
    int capacity;

public:
    University(int=3);

    void setCapacity(int);
    int getCapacity()const;

    bool addDormitory(Dormitory*);

    void displayDormitories()const;

    Dormitory* findDormitory(const std::string&)const;

    Room* findRoom(int roomNum, const std::string& dormName);

    bool found(Dormitory*)const;

    Student* findStudent(long id, const std::string& dormName);

    // FILE HANDLING
    void saveToFiles() const;
    void loadFromFiles();

};
#endif // UNIVERSITY_H
