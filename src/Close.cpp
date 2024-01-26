#include "../include/WareHouse.h" // Include the Volunteer class header
#include "../include/Action.h"
#include "../include/Order.h"

#include <sstream>
#include <iostream>

Close::Close() {}

void Close::act(WareHouse &wareHouse)
{
    std::stringstream str;
    vector<Order *> allOrders = wareHouse.getAllOrders();
    for (Order *order : allOrders)
    {
        str << "OrderID: " << order->getId();
        str << ", CustomerID: " << order->getCustomerId();
        str << ", OrderStatus: " << (order->getStatusStr()) << std::endl;
    }
    std::cout << str.str();
    wareHouse.addAction(this);

    wareHouse.close();
}

Close *Close::clone() const
{
    return new Close(*this);
}
string Close::toString() const
{
    return "close COMPLETED";
}
