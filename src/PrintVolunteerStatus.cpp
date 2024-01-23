#include "../include/Volunteer.h" // Include the Volunteer class header
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
    Volunteer &v = wareHouse.getVolunteer(volunteerId);
    if (v.getId() == -1)
    {
        str = "Volunteer doesn’t exist";
        error(str);
        str = "Error: Volunteer doesn’t exist";

    }
    else
    {
        complete();
        str = v.toString();
    }
    std::cout << str << std::endl;
    wareHouse.addAction(this);
}
string PrintVolunteerStatus::toString() const
{
    if (getStatus() == ActionStatus::COMPLETED)
    {
        return "volunteerStatus " + std::to_string(volunteerId) + " COMPLETED";
    }
    else
        return "Error: " + getErrorMsg();
}
PrintVolunteerStatus *PrintVolunteerStatus::clone() const
{
    return new PrintVolunteerStatus(*this);
}
