#ifndef DAYMENU_H
#define DAYMENU_H
#include <string>

class DayMenu{

private:
    std::string breakFast ;
    std::string lunch ;
    std::string dinner ;

public:
    DayMenu(std::string="",std::string="",std::string="");
    void setBreakFast(std::string);
    std::string getBreakFast()const;

    void setLunch(std::string);
    std::string getLunch()const;

    void setDinner(std::string);
    std::string getDinner()const;

    void setMenu(std::string,std::string,std::string);

};
#endif // DAYMENU_H
