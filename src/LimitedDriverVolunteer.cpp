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

    string LimitedDriverVolunteer::toString() const {
         std::stringstream str;
         str << "Volunteer ID:" << getId() << std::endl;
         str << "Is busy:" << isBusy() << std::endl;
         str << "Order ID:" << getActiveOrderId() << std::endl;
         str << "Distance left:" << getDistanceLeft() << std::endl;
         str << "Orders Left:" << getNumOrdersLeft() << std::endl;
         return str.str();
    }
