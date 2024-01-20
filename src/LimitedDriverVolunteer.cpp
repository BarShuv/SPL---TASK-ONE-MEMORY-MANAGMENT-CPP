#include "../include/Volunteer.h"
#include "../include/Order.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;

class LimitedDriverVolunteer : public DriverVolunteer {
public:
    LimitedDriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep, int maxOrders)
        : DriverVolunteer(id, name, maxDistance, distancePerStep), maxOrders(maxOrders), ordersLeft(maxOrders) {}

    LimitedDriverVolunteer *clone() const override {
        return new LimitedDriverVolunteer(*this);
    }

    int getMaxOrders() const {
        return maxOrders;
    }

    int getNumOrdersLeft() const {
        return ordersLeft;
    }

    bool hasOrdersLeft() const override {
        return ordersLeft > 0;
    }

    bool canTakeOrder(const Order &order) const override {
        return DriverVolunteer::canTakeOrder(order) && ordersLeft > 0;
    }

    void acceptOrder(const Order &order) override {
        DriverVolunteer::acceptOrder(order);
        ordersLeft--;
    }

    string toString() const override {
         std::stringstream str;
         str << "Volunteer ID:" << getId() << std::endl;
         str << "Is busy:" << isBusy() << std::endl;
         str << "Order ID:" << getActiveOrderId() << std::endl;
         str << "Distance left:" << getDistanceLeft() << std::endl;
         str << "Orders Left:" << getNumOrdersLeft() << std::endl;
         return str.str();
    }

private:
    const int maxOrders;
    int ordersLeft;
};
