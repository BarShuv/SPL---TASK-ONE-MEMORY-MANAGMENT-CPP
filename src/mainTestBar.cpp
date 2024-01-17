#include "../include/Order.h"
#include <iostream>

int main() {
    // Creating an Order object
    Order order1(555, 55, 5);

    // Displaying order information using toString
    std::cout << "Order Information (Initial):" << std::endl;
    std::cout << order1.toString() << std::endl;

    // Updating order information
    order1.setStatus(OrderStatus::COLLECTING);
    order1.setCollectorId(201);
    order1.setDriverId(245234);

    // Displaying updated order information using toString
    std::cout << "Order Information (Updated):" << std::endl;
    std::cout << order1.toString() << std::endl;

    return 0;
}