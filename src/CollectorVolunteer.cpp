#include "../include/Volunteer.h"
#include "../include/Order.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;


    CollectorVolunteer::CollectorVolunteer(int id, const string &name, int coolDown)
        : Volunteer(id, name), coolDown(coolDown), timeLeft(0) {}

    CollectorVolunteer* CollectorVolunteer::clone() const {
        return new CollectorVolunteer(*this);
    }

    void CollectorVolunteer::step() {
        if (timeLeft > 0) {
            timeLeft--;
            if (timeLeft == 0) {
                completedOrderId = activeOrderId;
                activeOrderId = NO_ORDER;
            }
        }
    }

    int CollectorVolunteer::getCoolDown() const {
        return coolDown;
    }

    int CollectorVolunteer::getTimeLeft() const {
        return timeLeft;
    }

    bool CollectorVolunteer::decreaseCoolDown() {
        if (timeLeft > 0) {
            timeLeft--;
            return timeLeft == 0;
        }
        return false;
    }

    bool CollectorVolunteer::hasOrdersLeft() const {
        return true; // Collector always has orders left
    }

    bool CollectorVolunteer::canTakeOrder(const Order &order) const {
        return !isBusy(); // Collector can take an order if not busy
    }

    // Prepare for new order(Reset activeOrderId,TimeLeft,DistanceLeft,OrdersLeft depends on the volunteer type)
    void CollectorVolunteer::acceptOrder(const Order &order) {
        activeOrderId = order.getId();
        timeLeft = coolDown;
    }
    
    string CollectorVolunteer::toString() const  {
         std::stringstream str;
         str << "Volunteer ID:" << getId() << std::endl;
         str << "Is busy:" << isBusy() << std::endl;
         str << "Order ID:" << getActiveOrderId() << std::endl;
         str << "Time left:" << getTimeLeft() << std::endl;
         return str.str();
    }


