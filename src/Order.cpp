#include "../include/Order.h"
#include <sstream>

Order::Order(int id, int customerId, int distance)
    : id(id), customerId(customerId), distance(distance), status(OrderStatus::PENDING),
      collectorId(NO_VOLUNTEER), driverId(NO_VOLUNTEER) {}

int Order::getId() const {
    return id;
}

int Order::getCustomerId() const {
    return customerId;
}

void Order::setStatus(OrderStatus status) {
    status = status;
}

void Order::setCollectorId(int collectorId) {
    collectorId = collectorId;
}

void Order::setDriverId(int driverIda) {
    driverId = driverIda;
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
