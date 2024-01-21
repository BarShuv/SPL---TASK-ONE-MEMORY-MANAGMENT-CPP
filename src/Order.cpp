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

const string Order::toString() const {
    std::stringstream ss;
    ss << "Order Information:" << std::endl;
    ss << "ID: " << id << std::endl;
    ss << "Customer ID: " << customerId << std::endl;
    ss << "Distance: " << distance << std::endl;
    ss << "Collector ID: " << collectorId << std::endl;
    ss << "Driver ID: " << driverId << std::endl;
    ss << "Status: " << static_cast<int>(status) << std::endl;

    return ss.str();
}

 //   int main(int argc, char** argv){
   //     Order o =  Order(2222,3333,60);
//
  //      std::cout << o.toString()<<std::endl;

    //    return 0;
    //}