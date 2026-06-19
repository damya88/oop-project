#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "DayMenu.h"

class Restaurant
{
private:
    DayMenu weeklyMenu[7];

public:
    Restaurant();

    void setMenuDay(int, const DayMenu&);
    DayMenu getMenuDay(int) const;

    void PrintDayMenu(int) const;
};
#endif // RESTAURANT_H
