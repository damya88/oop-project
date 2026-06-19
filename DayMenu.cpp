#include <iostream>
#include "DayMenu.h"

DayMenu::DayMenu(std::string bf,std::string l,std::string d){
    breakFast=bf;
    lunch=l;
    dinner=d;
}

void DayMenu::setBreakFast(std::string bf){
    breakFast=bf;
}

std::string DayMenu::getBreakFast()const{
    return breakFast;
}

void DayMenu::setLunch(std::string l){
    lunch=l;
}

std::string DayMenu::getLunch()const{
    return lunch;
}

void DayMenu::setDinner(std::string d){
    dinner=d;
}
std::string DayMenu::getDinner()const{
    return dinner;
}

void DayMenu::setMenu(std::string bf,std::string l,std::string d){
    setBreakFast(bf);
    setLunch(l),
        setDinner(d);
}

