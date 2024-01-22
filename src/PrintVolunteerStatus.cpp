#include "../include/Volunteer.h" // Include the Volunteer class header
#include "../include/Action.h"
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;

PrintVolunteerStatus::PrintVolunteerStatus(int id) : volunteerId(id) {}

void PrintVolunteerStatus::act(WareHouse &wareHouse) {
    Volunteer& v = wareHouse.getVolunteer(volunteerId);
    string str = v.toString();
    std::cout << str << std::endl;
}
