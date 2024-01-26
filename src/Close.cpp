#include "../include/Action.h"

#include <sstream>
#include <iostream>

Close::Close() {}

void Close::act(WareHouse &wareHouse)
{
    std::stringstream str;
    vector<Order *> allOrders = wareHouse.getAllOrders();
    for (Order *order : allOrders)
    {
        //print all orders from vector
        str << "OrderID: " << order->getId();
        str << ", CustomerID: " << order->getCustomerId();
        str << ", OrderStatus: " << (order->getStatusStr()) << std::endl;
    }
    std::cout << str.str();
    wareHouse.addAction(this);
    //close the warehouse and exit main loop
    wareHouse.close();
}

Close *Close::clone() const
{
    //cloning the action
    return new Close(*this);
}
string Close::toString() const
{
    return "close COMPLETED";
}
