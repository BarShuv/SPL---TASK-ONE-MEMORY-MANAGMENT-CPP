#include "../include/Volunteer.h"
#include "../include/Order.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;


// LimitedCollectorVolunteer::LimitedCollectorVolunteer(int id, const string &name, int coolDown ,int maxOrders)
// :CollectorVolunteer(id,name,coolDown), maxOrders(maxOrders) {}

class LimitedCollectorVolunteer : public CollectorVolunteer {
public:
    LimitedCollectorVolunteer(int id, const string &name, int coolDown, int maxOrders)
        : CollectorVolunteer(id, name, coolDown), maxOrders(maxOrders), ordersLeft(maxOrders) {}

    LimitedCollectorVolunteer *clone() const override {
        return new LimitedCollectorVolunteer(*this);
    }

    bool hasOrdersLeft() const override {
        return ordersLeft > 0;
    }

    bool canTakeOrder(const Order &order) const override {
        return CollectorVolunteer::canTakeOrder(order) && ordersLeft > 0;
    }

    void acceptOrder(const Order &order) override {
        CollectorVolunteer::acceptOrder(order);
        ordersLeft--;
    }

    int getMaxOrders() const {
        return maxOrders;
    }

    int getNumOrdersLeft() const {
        return ordersLeft;
    }

    string toString() const override {
        std::stringstream str;
         str << "Volunteer ID:" << getId() << std::endl;
         str << "Is busy:" << isBusy() << std::endl;
         str << "Order ID:" << getActiveOrderId() << std::endl;
         str << "Time left:" << getTimeLeft() << std::endl;
         str << "Orders Left:" << getNumOrdersLeft() << std::endl;
         return str.str();
    }

private:
    const int maxOrders;
    int ordersLeft;
};
