#include "../include/Customer.h"
#include "../include/Order.h" // Include the Order class header
#include <string>
#include <vector>
using std::string;
using std::vector;


Customer::Customer(int id, const std::string &name, int locationDistance, int maxOrders)
    : id(id), name(name), locationDistance(locationDistance), maxOrders(maxOrders),ordersId(),ordersMade(0) {}

const std::string &Customer::getName() const {
    return name;
}

int Customer::getId() const {
    return id;
}

int Customer::getCustomerDistance() const {
    return locationDistance;
}

int Customer::getMaxOrders() const {
    return maxOrders;
}

int Customer::getNumOrders() const {
    return ordersMade;
}

bool Customer::canMakeOrder() const {
    return ordersMade < maxOrders;
}

//is this ok?
const vector<int> &Customer::getOrdersIds() const {
    return ordersId;
}

int Customer::addOrder(int orderId) {
    if (canMakeOrder()) {
        ordersId.push_back(orderId);
        return orderId; // Successfully added order
    }
     else {
        return -1; // Customer reached max orders
    }
}



        SoldierCustomer::SoldierCustomer(int id, string name, int locationDistance, int maxOrders)
          : Customer(id, name,locationDistance,maxOrders) { }
               
        Customer:SoldierCustomer:: *clone() 
        {
                return new SoldierCustomer(*this);  

        }       
