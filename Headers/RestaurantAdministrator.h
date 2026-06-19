#ifndef RESTAURANTADMINISTRATOR_H
#define RESTAURANTADMINISTRATOR_H

#include "Person.h"
#include <string>

class RestaurantAdministrator : public Person
{
private:
    std::string position;
    double salary;

public:
    RestaurantAdministrator(
        long,
        std::string,
        int,
        std::string = "",
        double = 0.0
        );

    void setPosition(std::string);
    std::string getPosition() const;

    void setSalary(double);
    double getSalary() const;

    void display() const override;
};

#endif // RESTAURANTADMINISTRATOR_H
