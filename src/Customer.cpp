#include "../include/Customer.h"
#include "../include/Order.h" // Include the Order class header
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;

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
        //we need to see if this is needed - dont see why right now
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

/**
    int main(int argc, char** argv){
        std::cout << "Hello World!" << std::endl;
        SoldierCustomer soli(212400114,"bar",120,6);
        std::cout << soli.getId() <<soli.getCustomerDistance()<<soli.getLocationDistance()<<soli.getMaxOrders()<<soli.getName()<<soli.getNumOrders() <<std::endl;
        
        soli.addOrder(22222222);
                soli.addOrder(11);

        soli.addOrder(1111);
        
        vector<int> orders = soli.getOrdersIds();
        for (std::vector<int>::size_type i = 0; i < orders.size(); i++) {
                   std::cout << orders[i]<<std::endl;
        }


        std::cout << soli.getNumOrders()<<std::endl;


        SoldierCustomer newci = *soli.clone();
        std::cout << newci.getId() <<newci.getCustomerDistance()<<newci.getLocationDistance()<<newci.getMaxOrders()<<newci.getName()<<newci.getNumOrders() <<std::endl;
                vector<int> orders1 = newci.getOrdersIds();
        for (std::vector<int>::size_type i = 0; i < orders1.size(); i++) {
                   std::cout << orders1[i]<<std::endl;
        }


        std::cout << newci.getNumOrders()<<std::endl;

}
**/