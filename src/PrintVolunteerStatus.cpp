#include "../include/Action.h"
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;

PrintVolunteerStatus::PrintVolunteerStatus(int id) : volunteerId(id) {}

void PrintVolunteerStatus::act(WareHouse &wareHouse)
{
    string str = "";
    //gets the volunteer from list
    Volunteer &v = wareHouse.getVolunteer(volunteerId);
    if (v.getId() == -1)
    {
        //cant find id
        str = "Volunteer doesn’t exist";
        error(str);
        str = "Error: Volunteer doesn’t exist";
    }
    else
    {
        //take the volunteer toString implemented by conditions
        complete();
        str = v.toString();
    }
    //print and add to actions vector
    std::cout << str << std::endl;
    wareHouse.addAction(this);
}
string PrintVolunteerStatus::toString() const
{
    //return string matches action status
    if (getStatus() == ActionStatus::COMPLETED)
    {
        return "volunteerStatus " + std::to_string(volunteerId) + " COMPLETED";
    }
    else
        return "volunteerStatus " +  std::to_string(volunteerId) + " FAILED";
}
PrintVolunteerStatus *PrintVolunteerStatus::clone() const
{
    //cloning the PrintVolunteerStatus action
    return new PrintVolunteerStatus(*this);
}
