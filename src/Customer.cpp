#include "../include/Customer.h"
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
    //cunstractor to parameters
    Customer::Customer(int id, const string &name, int locationDistance, int maxOrders):
    id(id),name(name),locationDistance(locationDistance),maxOrders(maxOrders),ordersId(),ordersMade(0){}
    
    const string& Customer::getName() const{
        return name;
    }

    int Customer::getId() const{
        return id;
    }

    int Customer::getCustomerDistance() const
    {
        return locationDistance;
    }

    int Customer::getMaxOrders() const
    {
        return maxOrders;
    }

    int Customer::getLocationDistance() const
    {
        return locationDistance;
    }

    int Customer::getNumOrders() const
    {
        return ordersMade;
    }

    int Customer ::getOrdersLeft() const{
        return maxOrders-ordersMade;
    }


    bool Customer::canMakeOrder() const
    {
        return ordersMade < maxOrders;
    }

    const vector<int>& Customer::getOrdersIds() const
    {
        return ordersId;
    }

    int Customer::addOrder(int orderId) {
     if (canMakeOrder()) {
         ordersId.push_back(orderId);
         ordersMade = ordersMade+1;
         return orderId; // Successfully added order
     }
      else {
         return -1; // Customer reached max orders
     }
 } 


    SoldierCustomer::SoldierCustomer(int id, const string &name, int locationDistance, int maxOrders):
    Customer(id,name,locationDistance,maxOrders)
    {}

    SoldierCustomer* SoldierCustomer::clone() const 
    {
        //make deep copy
        return new SoldierCustomer(*this);
    }

    CivilianCustomer::CivilianCustomer(int id, const string &name, int locationDistance, int maxOrders):
    Customer(id,name,locationDistance,maxOrders)
    {}
    CivilianCustomer*  CivilianCustomer::clone() const{  
        //make deep copy
        return new CivilianCustomer(*this);

    }

