#include <iostream>
#include <stdexcept>
#include "Restaurant.h"

Restaurant::Restaurant()
{
    for(int i=0;i<7;i++){
        weeklyMenu[i]=DayMenu(); //initialize it to empty string
    }
}

void Restaurant::setMenuDay(int index, const DayMenu& dm)
{
    if (index < 0 || index >= 7)
    {
        throw std::out_of_range("Invalid day index");
    }

    weeklyMenu[index] = dm;
}

DayMenu Restaurant::getMenuDay(int index) const
{
    if (index < 0 || index >= 7)
    {
        throw std::out_of_range("Invalid day index");
    }

    return weeklyMenu[index];
}

void Restaurant::PrintDayMenu(int index) const
{
    if (index < 0 || index >= 7)
    {
        throw std::out_of_range("Invalid day index");
    }

    switch (index + 1)
    {
    case 1:
        std::cout << "Sunday :" << std::endl;
        break;

    case 2:
        std::cout << "Monday :" << std::endl;
        break;

    case 3:
        std::cout << "Tuesday :" << std::endl;
        break;

    case 4:
        std::cout << "Wednesday :" << std::endl;
        break;

    case 5:
        std::cout << "Thursday :" << std::endl;
        break;

    case 6:
        std::cout << "Friday :" << std::endl;
        break;

    case 7:
        std::cout << "Saturday :" << std::endl;
        break;
    }

    std::cout << "Breakfast : "
              << weeklyMenu[index].getBreakFast()
              << std::endl;

    std::cout << "Lunch : "
              << weeklyMenu[index].getLunch()
              << std::endl;

    std::cout << "Dinner : "
              << weeklyMenu[index].getDinner()
              << std::endl;
}