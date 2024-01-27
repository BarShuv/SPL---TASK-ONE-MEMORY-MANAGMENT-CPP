#include "../include/Volunteer.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;

CollectorVolunteer::CollectorVolunteer(int id, const string &name, int coolDown)
    : Volunteer(id, name), coolDown(coolDown), timeLeft(coolDown) {}

CollectorVolunteer *CollectorVolunteer::clone() const
{
    return new CollectorVolunteer(*this);
}

void CollectorVolunteer::step()
{
    if (timeLeft > 0)
    {
        bool finished = decreaseCoolDown();
        // if (finished) {
        //     completedOrderId = activeOrderId;
        //     activeOrderId = NO_ORDER;
        // }
    }
}

int CollectorVolunteer::getCoolDown() const
{
    return coolDown;
}

int CollectorVolunteer::getTimeLeft() const
{
    return timeLeft;
}

bool CollectorVolunteer::decreaseCoolDown()
{
    if (timeLeft > 0)
    {
        timeLeft--;
        return timeLeft == 0;
    }
    return false;
}

bool CollectorVolunteer::hasOrdersLeft() const
{
    return true; // Collector always has orders left
}

bool CollectorVolunteer::canTakeOrder(const Order &order) const
{
    return !isBusy(); // Collector can take an order if not busy
}

bool CollectorVolunteer::isDriver() const
{
    return false;
}
bool CollectorVolunteer::isCollector() const
{
    return true;
}

// Prepare for new order(Reset activeOrderId,TimeLeft,DistanceLeft,OrdersLeft depends on the volunteer type)
void CollectorVolunteer::acceptOrder(const Order &order)
{
    activeOrderId = order.getId();
    timeLeft = coolDown;
}

int CollectorVolunteer::getCoolDown() const
{
    return coolDown;
}

// int CollectorVolunteer::getDistanceLeftFromVol() const{
//     return -1;
// }

int CollectorVolunteer::getUpdatedDistanceLeft() const
{
    return -1;
}

void CollectorVolunteer::resetVolAfterFinishedOrder()
{
    completedOrderId = activeOrderId;
    activeOrderId = NO_ORDER;
}

string CollectorVolunteer::toString() const
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
    if (timeLeft == 0)
    {
        str << "OrderId: None" << std::endl;
    }
    else
    {
        str << "OrderId: " << getActiveOrderId() << std::endl;
    }
    if (timeLeft == 0)
    {
        str << "TimeLeft: None" << std::endl;
    }
    else
    {
        str << "TimeLeft: " << getTimeLeft() << std::endl;
    }
    str << "ordersLeft: No Limit";
    return str.str();
}
