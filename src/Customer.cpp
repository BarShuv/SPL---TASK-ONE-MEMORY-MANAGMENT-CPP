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

const vector<int> &Customer::getOrders() const {
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



class SoldierCustomer: public Customer {
    public:
        
        SoldierCustomer(int id, string name, int locationDistance, int maxOrders)
          : Customer(id, name,locationDistance,maxOrders) { }
        
        
        SoldierCustomer *clone() const override
        {
            
            
            
        }
    
    
        
};