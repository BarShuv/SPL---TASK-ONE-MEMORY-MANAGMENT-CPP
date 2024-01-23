#include "../include/Volunteer.h"
#include "../include/Order.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;

    LimitedDriverVolunteer::LimitedDriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep, int maxOrders)
        : DriverVolunteer(id, name, maxDistance, distancePerStep), maxOrders(maxOrders), ordersLeft(maxOrders) {}

    LimitedDriverVolunteer* LimitedDriverVolunteer::clone() const {
        return new LimitedDriverVolunteer(*this);
    }

    int LimitedDriverVolunteer::getMaxOrders() const {
        return maxOrders;
    }

    int LimitedDriverVolunteer::getNumOrdersLeft() const {
        return ordersLeft;
    }

    bool LimitedDriverVolunteer::hasOrdersLeft() const {
        return ordersLeft > 0;
    }

    bool LimitedDriverVolunteer::canTakeOrder(const Order &order) const {
        return DriverVolunteer::canTakeOrder(order) && ordersLeft > 0;
    }

    void LimitedDriverVolunteer::acceptOrder(const Order &order) {
        DriverVolunteer::acceptOrder(order);
        ordersLeft--;
    }

    bool LimitedDriverVolunteer::isDriver() const {
        return true;
    }
    bool LimitedDriverVolunteer::isCollector() const {
        return false;
    }

    string LimitedDriverVolunteer::toString() const {
         std::stringstream str;
         str << "VolunteerID: " << getId() << std::endl;
         str << "IsBusy: " << isBusy() << std::endl;
         str << "OrderId: " << getActiveOrderId() << std::endl;
         str << "DistanceLeft: " << getDistanceLeft() << std::endl;
         str << "Orders Left: " << getNumOrdersLeft() ;
         return str.str();
    }
