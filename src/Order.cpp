#include "../include/Order.h"
#include <iostream>

Order::Order(int orderId, int orderCustomerId, int orderDistance)
    : id(orderId), customerId(orderCustomerId), distance(orderDistance), status(OrderStatus::PENDING), collectorId(NO_VOLUNTEER), driverId(NO_VOLUNTEER) {
}

int Order::getId() const {
    return id;
}

int Order::getCustomerId() const {
    return customerId;
}

void Order::setStatus(OrderStatus orderStatus) {
    status = orderStatus;
}

void Order::setCollectorId(int collector) {
    collectorId = collector;
}

void Order::setDriverId(int driver) {
    driverId = driver;
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

const std::string Order::toString() const {
    std::string statusStr;
    switch (status) {
        case OrderStatus::PENDING:
            statusStr = "Pending";
            break;
        case OrderStatus::COLLECTING:
            statusStr = "Collecting";
            break;
        case OrderStatus::DELIVERING:
            statusStr = "Delivering";
            break;
        case OrderStatus::COMPLETED:
            statusStr = "Completed";
            break;
    }

    return "Order ID: " + std::to_string(id) + ", Customer ID: " + std::to_string(customerId) + ", Distance: " +
           std::to_string(distance) + ", Status: " + statusStr;
}

int main() {
    // Example usage
    Order order1(1, 101, 10);
    order1.setStatus(OrderStatus::COLLECTING);
    order1.setCollectorId(201);

    std::cout << order1.toString() << std::endl;

    return 0;
}
