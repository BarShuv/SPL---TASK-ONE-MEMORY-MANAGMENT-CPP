#include "../include/Order.h"
#include <sstream>



Order::Order(int idP, int customerId, int distance):id(idP),customerId(customerId),distance(distance){
    
}
    



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
