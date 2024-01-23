#pragma once
#include <string>
#include <vector>
#include "Order.h"
#include "Customer.h"
#include "Volunteer.h"
#include "Action.h"
class BaseAction;
class Volunteer;
class Order;

// Warehouse responsible for Volunteers, Customers Actions, and Orders.

class WareHouse
{

public:
    WareHouse(const string &configFilePath);
    ~WareHouse();
    WareHouse(const WareHouse &other);
    WareHouse(WareHouse&& other) noexcept;
    
    WareHouse &operator=(const WareHouse &other);
    void start();
    void addOrder(Order *order);
    void addAction(BaseAction *action);
    void addCustomer(Customer *customer);    // adding customer to customers vector
    void addVolunteer(Volunteer *volunteer); // adding volunteer to volunteers vector
    Customer &getCustomer(int customerId) const;
    Volunteer &getVolunteer(int volunteerId) const;
    Order &getOrder(int orderId) const;
    const vector<BaseAction *> &getActions() const; // maybe we will need to add something
    void close();
    void open();
    bool doParse(string file_name);
    int getIdNewCustomer();
    int getIdNewvolunteer();
    int getIdNeworder();
    void handOverOrders();
    void performSimulationStep();
    void checkVolunteers();
    void deleteFinishedVolunteers();
    const vector<vector<Order*>> &getAllOrders() const; // needed for close.cpp


private:
    bool isOpen;
    vector<BaseAction *> actionsLog;
    vector<Volunteer *> volunteers;
    vector<Order *> pendingOrders;
    vector<Order *> inProcessOrders;
    vector<Order *> completedOrders;
    vector<Customer *> customers;
    int customerCounter;  // For assigning unique customer IDs
    int volunteerCounter; // For assigning unique volunteer IDs
    int orderCounter;     // For assigning unique order IDs
    ////////////added fields  
    CivilianCustomer *defualtCustomer;// default null customer
    DriverVolunteer *defaultVolunteer;// default null volunteer
    Order *defaultOrder;// default null order
};