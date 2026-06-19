#include "RestaurantAdministrator.h"
#include <iostream>
#include <stdexcept>

RestaurantAdministrator::RestaurantAdministrator(
    long id,
    std::string name,
    int age,
    std::string pos,
    double sal
    )
    : Person(id, name, age)
{
    setPosition(pos);
    setSalary(sal);
}

void RestaurantAdministrator::setPosition(std::string pos)
{
    if (pos.empty())
    {
        throw std::invalid_argument("Position cannot be empty");
    }

    position = pos;
}

std::string RestaurantAdministrator::getPosition() const
{
    return position;
}

void RestaurantAdministrator::setSalary(double sal)
{
    if (sal < 0)
    {
        throw std::invalid_argument("Salary cannot be negative");
    }

    salary = sal;
}

double RestaurantAdministrator::getSalary() const
{
    return salary;
}

void RestaurantAdministrator::display() const
{
    Person::display();

    std::cout << "Position : "
              << position
              << std::endl;

    std::cout << "Salary : "
              << salary
              << std::endl;
}