#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{

private:
    long id;
    std::string fullName;
    int age;

public:
    Person(long, std::string, int);
    virtual ~Person() = default;

    void setId(long);
    long getId() const;

    void setFullName(std::string);
    std::string getFullName() const;

    void setAge(int);
    int getAge() const;

    virtual void display() const = 0;
};
#endif // PERSON_H
