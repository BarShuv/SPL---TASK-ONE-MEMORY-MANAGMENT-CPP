#include "../include/Order.h"
#include <sstream>
#include <iostream>

Order::Order(int id, int customerId, int distance)
:id(id),customerId(customerId),distance(distance),status(OrderStatus::PENDING),collectorId(NO_VOLUNTEER),driverId(NO_VOLUNTEER)
{}
    
int Order::getId() const {
    return id;
}

int Order::getCustomerId() const {
    return customerId;
}

void Order::setStatus(OrderStatus status) {
    this->status = status;
}

void Order::setCollectorId(int collectorId) {
    this->collectorId = collectorId;
}

void Order::setDriverId(int driverId) {
    this->driverId = driverId;
}

int Order::getCollectorId() const {
    return collectorId;
}

int Order::getDriverId() const {
    return driverId;
}

OrderStatus Order::getStatus() const {
    return status;
}

 int Order::getDistance() const{
    return distance;
 }


string Order::getStatusStr() const
{
    //returns string of the status
    string orderStatusStr = "";
    if(status == OrderStatus::PENDING)
    {
        orderStatusStr = "Pending";
    }
    else if(status == OrderStatus::COLLECTING)
    {
        orderStatusStr = "Collecting";
    }
    else if(status == OrderStatus::DELIVERING)
    {
        orderStatusStr = "Delivering";
    }
    else if(status == OrderStatus::COMPLETED)
    {
        orderStatusStr = "Completed";
    }
    return orderStatusStr;
}





const string Order::toString() const {
    std::stringstream ss;
    string orderStatusStr = getStatusStr();
    string collectorIdStr = std::to_string(collectorId);
    string driverIdStr = std::to_string(driverId);



    if (collectorId==NO_VOLUNTEER){
        collectorIdStr = "None";
    }
    if (driverId==NO_VOLUNTEER){
        driverIdStr = "None";
    }

    ss << "OrderId: " << id << std::endl;
    ss << "OrderStatus: " << orderStatusStr<< std::endl;
    ss << "CustomerID: " << customerId << std::endl;
    ss << "Collector: " << collectorIdStr << std::endl;
    ss << "Driver: " << driverIdStr ;

    return ss.str();
}

 //   int main(int argc, char** argv){
 //       Order o =  Order(2222,3333,60);
 //       o.setCollectorId(34634654);
  //      o.setDriverId(443534);
  //      std::cout << o.toString()<<std::endl;

    //    return 0;
   // }