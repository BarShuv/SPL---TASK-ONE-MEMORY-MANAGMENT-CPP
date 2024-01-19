#include "../include/Customer.h"
#include "../include/Order.h" // Include the Order class header
#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;

    Customer::Customer(int id, const string &name, int locationDistance, int maxOrders):id(id),name(name),locationDistance(locationDistance),maxOrders(maxOrders),ordersId(),ordersMade(0){}
    const string& Customer::getName() const{
        return name;
    }

    const vector<int>& Customer::getOrdersIds() const
    {
        return ordersId;
    }

    



    SoldierCustomer::SoldierCustomer(int id, const string &name, int locationDistance, int maxOrders):Customer(id,name,locationDistance,maxOrders)
    {
    



    }
    SoldierCustomer* SoldierCustomer::clone() const{
        const vector<int> orders = getOrdersIds();
        SoldierCustomer *a = new SoldierCustomer(getId(),getName(),getLocationDistance(),getMaxOrders());
        for(int i = 0 ; i < orders.size();i++){
            a->addOrder(orders[i]);
        }
        return (a);
    }







    int main(int argc, char** argv){
        std::cout << "Hello World!" << std::endl;
        return 0;
}
//    Customer(int id, const string &name, int locationDistance, int maxOrders):
     
//     {
        
//     }
        

































// class SoldierCustomer:public Customer
// {
//     private:
//         const int id;
//         const string name;
//         const int locationDistance;
//         const int maxOrders;
//         vector<int> ordersId;
//         const int ordersMade;
//     SoldierCustomer(int id, const string &name, int locationDistance, int maxOrders)
//     :
    
//      id(id), 
//      name(name),
//       locationDistance(locationDistance), 
//       maxOrders(maxOrders),
//       ordersId(),
//       ordersMade(0)
//     {}

// const string& getName() const {
//     return name;
// }

// int getId() const {
//     return id;
// }

// int getCustomerDistance() const {
//     return locationDistance;
// }

// int getMaxOrders() const {
    // return maxOrders;
// }

// int getNumOrders() const {
//     return ordersMade;
// }

// bool canMakeOrder() const {
    // return ordersMade < maxOrders;
// }

// //is this ok?
// const vector<int> &getOrdersIds() const {
//     return ordersId;
// }

// int addOrder(int orderId) {
//     if (canMakeOrder()) {
//         ordersId.push_back(orderId);
//         return orderId; // Successfully added order
//     }
//      else {
//         return -1; // Customer reached max orders
//     }
// }


// };