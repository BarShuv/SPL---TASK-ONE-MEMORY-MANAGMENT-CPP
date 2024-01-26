#include "../include/Volunteer.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;

DriverVolunteer::DriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep)
    : Volunteer(id, name), maxDistance(maxDistance), distancePerStep(distancePerStep), distanceLeft(0) {}

DriverVolunteer *DriverVolunteer::clone() const
{
    return new DriverVolunteer(*this);
}

int DriverVolunteer::getDistanceLeft() const
{
    return distanceLeft;
}

int DriverVolunteer::getMaxDistance() const
{
    return maxDistance;
}

int DriverVolunteer::getDistancePerStep() const
{
    return distancePerStep;
}

bool DriverVolunteer::decreaseDistanceLeft()
{
    if (distanceLeft > 0)
    {
        distanceLeft -= distancePerStep;
        return distanceLeft <= 0;
    }
    return false;
}

bool DriverVolunteer::hasOrdersLeft() const
{
    return true; // Driver always has orders left
}

bool DriverVolunteer::canTakeOrder(const Order &order) const
{
    return !isBusy() && order.getDistance() <= maxDistance;
}

void DriverVolunteer::acceptOrder(const Order &order)
{
    activeOrderId = order.getId();
    distanceLeft = order.getDistance();
}

void DriverVolunteer::step()
{
    if (distanceLeft > 0)
    {
        decreaseDistanceLeft();
    }
}

bool DriverVolunteer::isDriver() const
{
    return true;
}
bool DriverVolunteer::isCollector() const
{
    return false;
}

string DriverVolunteer::toString() const
{
    std::stringstream str;
        string isBusyStr;

        //returns string matches the volunteer status action

        if(isBusy()){isBusyStr = "True";}
        else{isBusyStr = "False";}

         str << "VolunteerID: " << getId() << std::endl;
         str << "IsBusy: " << isBusyStr << std::endl;
         if(distanceLeft ==0){
            str << "OrderId: None" << std::endl;
         }
         else{
         str << "OrderId: " << getActiveOrderId() << std::endl;
         }
        if(distanceLeft ==0){
            str << "TimeLeft: None" << std::endl;
        }
        else
        {
            str << "TimeLeft: " << distanceLeft << std::endl;
        }
        str << "ordersLeft: No Limit" ;
    return str.str();
}
