#include "../include/Volunteer.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;
// cunstractor to given parameters and default values , and fathers values
LimitedDriverVolunteer::LimitedDriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep, int maxOrders)
    : DriverVolunteer(id, name, maxDistance, distancePerStep), maxOrders(maxOrders), ordersLeft(maxOrders) {}

LimitedDriverVolunteer *LimitedDriverVolunteer::clone() const
{
    return new LimitedDriverVolunteer(*this);
}

int LimitedDriverVolunteer::getMaxOrders() const
{
    return maxOrders;
}

int LimitedDriverVolunteer::getNumOrdersLeft() const
{
    return ordersLeft;
}

bool LimitedDriverVolunteer::hasOrdersLeft() const
{
    return ordersLeft > 0;
}

bool LimitedDriverVolunteer::canTakeOrder(const Order &order) const
{
    return DriverVolunteer::canTakeOrder(order) && ordersLeft > 0;
}

void LimitedDriverVolunteer::acceptOrder(const Order &order)
{
    DriverVolunteer::acceptOrder(order);
}

bool LimitedDriverVolunteer::isDriver() const
{
    return true;
}
bool LimitedDriverVolunteer::isCollector() const
{
    return false;
}

void LimitedDriverVolunteer::resetVolAfterFinishedOrder()
{
    ordersLeft--;
    DriverVolunteer::resetVolAfterFinishedOrder();
}

string LimitedDriverVolunteer::toString() const
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
    if (getDistanceLeft() == 0)
    {
        str << "OrderId: None" << std::endl;
    }
    else
    {
        str << "OrderId: " << getActiveOrderId() << std::endl;
    }
    if (getDistanceLeft() == 0)
    {
        str << "TimeLeft: None" << std::endl;
    }
    else
    {
        str << "TimeLeft: " << getDistanceLeft() << std::endl;
    }
    str << "OrdersLeft: " << getNumOrdersLeft();
    return str.str();
}
