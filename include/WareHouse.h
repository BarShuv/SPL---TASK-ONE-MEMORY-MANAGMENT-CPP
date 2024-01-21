#pragma once
#include <string>
#include <vector>
#include "Order.h"
#include "Customer.h"
#include "Volunteer.h"
//#include "Action.h"
class BaseAction;
class Volunteer;
class Order;

// Warehouse responsible for Volunteers, Customers Actions, and Orders.


class WareHouse {

    public:
        WareHouse(const string &configFilePath);
        void start();
        void addOrder(Order* order);
        void addAction(BaseAction* action);
        void addCustomer(Customer* customer); //adding customer to customers vector
        void addVolunteer(Volunteer* volunteer); //adding volunteer to volunteers vector
        Customer &getCustomer(int customerId) const;
        Volunteer &getVolunteer(int volunteerId) const; 
        Order &getOrder(int orderId) const;
        const vector<BaseAction*> &getActions() const;
        void close();
        void open();
        bool doParse(string file_name);
        

    private:


        bool isOpen;
        vector<BaseAction*> actionsLog;
        vector<Volunteer*> volunteers;
        vector<Order*> pendingOrders;
        vector<Order*> inProcessOrders;
        vector<Order*> completedOrders;
        vector<Customer*> customers;
        int customerCounter; //For assigning unique customer IDs
        int volunteerCounter; //For assigning unique volunteer IDs
    


};