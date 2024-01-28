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
    //decrese distance left minimum to zero
    if (distanceLeft > 0)
    {
        distanceLeft -= distancePerStep;
        return distanceLeft <= 0;
    }
    return false;
}

int DriverVolunteer::getCoolDownFromVol() const
{
    return -1;
}


bool DriverVolunteer::hasOrdersLeft() const
{
    return true; // Driver always has orders left
}

bool DriverVolunteer::canTakeOrder(const Order &order) const
{
    //return true if conditions to take order are good
    return !isBusy() && order.getDistance() <= maxDistance;
}

void DriverVolunteer::acceptOrder(const Order &order)
{//sets values to given order
    activeOrderId = order.getId();
    distanceLeft = order.getDistance();
}

void DriverVolunteer::step()
{
    //performs step on simulation, minimum distance left 0
    if (distanceLeft > 0)
    {
        decreaseDistanceLeft();
        if (distanceLeft < 0)
        {
            distanceLeft = 0;
        }
    }
}

void DriverVolunteer::resetVolAfterFinishedOrder()
{
    distanceLeft = 0;
    completedOrderId = activeOrderId;
    activeOrderId = NO_ORDER;
}

int DriverVolunteer::getUpdatedDistanceLeft() const
{
    return distanceLeft;
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

    // returns string matches the volunteer status action

    if (isBusy())
    {
        isBusyStr = "True";
    }
    else
    {
        isBusyStr = "False";
    }

    str << "VolunteerID: " << getId() << std::endl;
    str << "IsBusy: " << isBusyStr << std::endl;
    if (distanceLeft == 0)
    {
        str << "OrderId: None" << std::endl;
    }
    else
    {
        str << "OrderId: " << getActiveOrderId() << std::endl;
    }
    if (distanceLeft == 0)
    {
        str << "TimeLeft: None" << std::endl;
    }
    else
    {
        str << "TimeLeft: " << distanceLeft << std::endl;
    }
    str << "ordersLeft: No Limit";
    return str.str();
}
