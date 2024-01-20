#include "../include/Volunteer.h"
#include "../include/Order.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;


class CollectorVolunteer : public Volunteer {
public:
    CollectorVolunteer(int id, const string &name, int coolDown)
        : Volunteer(id, name), coolDown(coolDown), timeLeft(0) {}

    CollectorVolunteer *clone() const override {
        return new CollectorVolunteer(*this);
    }

    void step() override {
        if (timeLeft > 0) {
            timeLeft--;
            if (timeLeft == 0) {
                completedOrderId = activeOrderId;
                activeOrderId = NO_ORDER;
            }
        }
    }

    int getCoolDown() const {
        return coolDown;
    }

    int getTimeLeft() const {
        return timeLeft;
    }

    bool decreaseCoolDown() {
        if (timeLeft > 0) {
            timeLeft--;
            return timeLeft == 0;
        }
        return false;
    }

    bool hasOrdersLeft() const override {
        return true; // Collector always has orders left
    }

    bool canTakeOrder(const Order &order) const override {
        return !isBusy(); // Collector can take an order if not busy
    }

    // Prepare for new order(Reset activeOrderId,TimeLeft,DistanceLeft,OrdersLeft depends on the volunteer type)
    void acceptOrder(const Order &order) override {
        activeOrderId = order.getId();
        timeLeft = coolDown;
    }
    
    int getTimeLeft() const{
        return timeLeft;
    }

    string toString() const override {
         std::stringstream str;
         str << "Volunteer ID:" << getId() << std::endl;
         str << "Is busy:" << isBusy() << std::endl;
         str << "Order ID:" << getActiveOrderId() << std::endl;
         str << "Time left:" << getTimeLeft() << std::endl;
         return str.str();
    }

private:
    const int coolDown;
    int timeLeft;
};

