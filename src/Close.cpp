#include "../include/WareHouse.h" // Include the Volunteer class header
#include "../include/Action.h"
#include "../include/Order.h"

#include <sstream>

Close::Close() {}

void Close::act(WareHouse &wareHouse)
{
    wareHouse.close();
    std::stringstream str;
    vector<vector<Order *>> allOrders = wareHouse.getAllOrders();
    for (vector<Order *> orderVector : allOrders)
    {
        for (Order *order : orderVector)
        {
            str << "OrderID: " << order->getId();
            str << ", CustomerID: " << order->getCustomerId();
            str << ", Status: " << (order->getStatusStr()) << std::endl;
        }
    }
}

Close *Close::clone() const
{
    return new Close(*this);
}
string Close::toString() const
{
    return "close COMPLETED";
}
