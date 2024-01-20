#include "../include/Volunteer.h"
#include "../include/Order.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;


class DriverVolunteer : public Volunteer {
public:
    DriverVolunteer(int id, const string &name, int maxDistance, int distancePerStep)
        : Volunteer(id, name), maxDistance(maxDistance), distancePerStep(distancePerStep), distanceLeft(0) {}

    DriverVolunteer *clone() const override {
        return new DriverVolunteer(*this);
    }

    int getDistanceLeft() const {
        return distanceLeft;
    }

    int getMaxDistance() const {
        return maxDistance;
    }

    int getDistancePerStep() const {
        return distancePerStep;
    }

    bool decreaseDistanceLeft() {
        if (distanceLeft > 0) {
            distanceLeft -= distancePerStep;
            return distanceLeft <= 0;
        }
        return false;
    }

    bool hasOrdersLeft() const override {
        return true; // Driver always has orders left
    }

    bool canTakeOrder(const Order &order) const override {
        return !isBusy() && order.getDistance() <= maxDistance;
    }

    void acceptOrder(const Order &order) override {
        activeOrderId = order.getId();
        distanceLeft = order.getDistance();
    }

    void step() override {
        if (distanceLeft > 0) {
            decreaseDistanceLeft();
        }
    }

    string toString() const override {
         std::stringstream str;
         str << "Volunteer ID:" << getId() << std::endl;
         str << "Is busy:" << isBusy() << std::endl;
         str << "Order ID:" << getActiveOrderId() << std::endl;
         str << "Distance left:" << getDistanceLeft() << std::endl;
         return str.str();
    }

private:
    const int maxDistance;
    const int distancePerStep;
    int distanceLeft;
};
