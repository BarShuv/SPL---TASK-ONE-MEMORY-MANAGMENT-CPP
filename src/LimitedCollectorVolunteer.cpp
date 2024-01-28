#include "../include/Volunteer.h"
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
        //decrease orders left and set values to volunteer by order
        ordersLeft--;
        CollectorVolunteer::acceptOrder(order);
    }

    int LimitedCollectorVolunteer::getMaxOrders() const {
        return maxOrders;
    }

    int LimitedCollectorVolunteer::getNumOrdersLeft() const {
        return ordersLeft;
    }

    bool LimitedCollectorVolunteer::isDriver() const {
        return false;
    }
    bool LimitedCollectorVolunteer::isCollector() const {
        return true;
    }

    void LimitedCollectorVolunteer::resetVolAfterFinishedOrder(){
        //call to fathers func
        CollectorVolunteer::resetVolAfterFinishedOrder();
    }

    string LimitedCollectorVolunteer::toString() const {
        std::stringstream str;
        string isBusyStr;
        //returns string matches the volunteer status action


        if(isBusy()){isBusyStr = "True";}
        else{isBusyStr = "False";}

         str << "VolunteerID: " << getId() << std::endl;
         str << "IsBusy: " << isBusyStr << std::endl;
         if(getTimeLeft() ==0){
            str << "OrderId: None" << std::endl;
         }
         else{
         str << "OrderId: " << getActiveOrderId() << std::endl;
         }
        if(getTimeLeft() ==0){
            str << "TimeLeft: None" << std::endl;
        }
        else
        {
            str << "TimeLeft: " << getTimeLeft() << std::endl;
        }
         str << "OrdersLeft: " << getNumOrdersLeft() ;
         return str.str();
    }