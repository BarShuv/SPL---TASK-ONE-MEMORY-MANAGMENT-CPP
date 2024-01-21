#include "../include/Volunteer.h"
#include "../include/Order.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;


    LimitedCollectorVolunteer::LimitedCollectorVolunteer(int id, const string &name, int coolDown, int maxOrders)
        : CollectorVolunteer(id, name, coolDown), maxOrders(maxOrders), ordersLeft(maxOrders) {}

    LimitedCollectorVolunteer* LimitedCollectorVolunteer::clone() const{
        return new LimitedCollectorVolunteer(*this);
    }

    bool LimitedCollectorVolunteer::hasOrdersLeft() const {
        return ordersLeft > 0;
    }

    bool LimitedCollectorVolunteer::canTakeOrder(const Order &order) const {
        return CollectorVolunteer::canTakeOrder(order) && ordersLeft > 0;
    }

    void LimitedCollectorVolunteer::acceptOrder(const Order &order) {
        CollectorVolunteer::acceptOrder(order);
        ordersLeft--;
    }

    int LimitedCollectorVolunteer::getMaxOrders() const {
        return maxOrders;
    }

    int LimitedCollectorVolunteer::getNumOrdersLeft() const {
        return ordersLeft;
    }

    string LimitedCollectorVolunteer::toString() const {
        std::stringstream str;
         str << "Volunteer ID:" << getId() << std::endl;
         str << "Is busy:" << isBusy() << std::endl;
         str << "Order ID:" << getActiveOrderId() << std::endl;
         str << "Time left:" << getTimeLeft() << std::endl;
         str << "Orders Left:" << getNumOrdersLeft() << std::endl;
         return str.str();
    }