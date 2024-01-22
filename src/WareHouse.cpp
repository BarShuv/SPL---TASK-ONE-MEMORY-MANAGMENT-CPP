#include "../include/WareHouse.h"
#include <iostream>
#include <string>
#include <sstream>
using std::vector;

WareHouse::WareHouse(const string &configFilePath) :

isOpen(false),
//initialize vectors to empty vectors
actionsLog(),volunteers(),pendingOrders(),inProcessOrders(),completedOrders(),customers(),
customerCounter(0), //first id for customers
volunteerCounter(0), // first id for volunteers
orderCounter(0) //first id for orders
{
    this->doParse(configFilePath);
}

void WareHouse::start()
{
    open();
    string userInput;
    // break the input to command and parameters
    string command;

    std::cout << "Warehouse is open!" << std::endl;

    while (isOpen)
    {

        std::cout << "Enter a command: ";
        std::getline(std::cin, userInput);

        // Use stringstream to extract the first word
        std::stringstream ss(userInput);
        ss >> command;

    // Switch based on the first word
    if (command == "step") {
        int number_of_steps;
        ss >> number_of_steps;
        std::cout << "entered step " <<  number_of_steps << std::endl;
        //SimulateStep simStep = SimulateStep(number_of_steps);
        //simStep.act(*this);
    } 
    else if (command == "order") {
        int customer_id;
        ss >> customer_id;
        std::cout << "entered order " <<  customer_id << std::endl;
        AddOrder addOrder = AddOrder(customer_id);
        addOrder.act(*this);
    } 

    else if (command == "customer") {
        string customer_name;
        string customer_type;
        int customer_distance;
        int max_orders;

            ss >> customer_name;
            ss >> customer_type;
            ss >> customer_distance;
            ss >> max_orders;

            std::cout << "entered customer " << customer_name << std::endl;
            // AddCustomer addCustomer = AddCustomer(customer_name,customer_type,customer_distance,max_orders);
            // addCustomer.act(*this);
        }

        else if (command == "orderStatus")
        {
            int order_id;
            ss >> order_id;
            std::cout << "entered orderStatus " << order_id << std::endl;
            // PrintOrderStatus printOrder = PrintOrderStatus(order_id);
            // printOrder.act(*this);
        }

        else if (command == "customerStatus")
        {
            int customer_id;
            ss >> customer_id;
            std::cout << "entered customerStatus " << customer_id << std::endl;
            // PrintCustomerStatus printCustomer = PrintCustomerStatus(customer_id);
            // printCustomer.act(*this);
        }

        else if (command == "volunteerStatus")
        {
            int volunteer_id;
            ss >> volunteer_id;
            std::cout << "entered volunteerStatus " << volunteer_id << std::endl;
            // PrintVolunteerStatus printvolunteer = PrintVolunteerStatus(volunteer_id);
            // printvolunteer.act(*this);
        }

        else if (command == "log")
        {
            std::cout << "entered log " << std::endl;
            // PrintActionsLog log = PrintActionsLog();
            // log.act(*this);
        }

        else if (command == "close")
        {
            std::cout << "entered close " << std::endl;
            // Close close = Close();
            // close.act(*this);
        }

        else if (command == "backup")
        {
            std::cout << "entered backup " << std::endl;
            // BackupWareHouse backup = BackupWareHouse();
            // backup.act(*this);
        }

        else if (command == "restore")
        {
            std::cout << "entered restore " << std::endl;
            // RestoreWareHouse restore = RestoreWareHouse();
            // restore.act(*this);
        }

        else
        {
            std::cout << "Unknown command." << std::endl;
        }
    }
}

void WareHouse::addOrder(Order *order)
{
    // adds the new order to pending orders vector
    pendingOrders.push_back(order);
}

void WareHouse::addAction(BaseAction *action)
{
    // adding the new action to the actions log vector
    actionsLog.push_back(action);
}

void WareHouse::addCustomer(Customer *customer)
{
    // adding the new Customer to the Customers vector
    customers.push_back(customer);
}

void WareHouse::addVolunteer(Volunteer *volunteer)
{
    // adding the new action to the actions log vector
    volunteers.push_back(volunteer);
}

Customer &WareHouse::getCustomer(int customerId) const
{
    // returns a reference to the costumer if exists in the customers vector , nullptr otherwise
    for (vector<Customer *>::size_type i = 0; i < customers.size(); i++)
    {
        if (customers[i]->getId() == customerId)
        {
            return *customers[i];
        }
    }
    // is this ok?
    CivilianCustomer *temp = new CivilianCustomer(-1, "", -1, -1); // return default null customer
    return *temp;
}

Volunteer &WareHouse::getVolunteer(int volunteerId) const
{
    // returns a reference to the volunteer if exists in the customers vector , nullptr otherwise
    for (vector<Volunteer *>::size_type i = 0; i < volunteers.size(); i++)
    {
        if (volunteers[i]->getId() == volunteerId)
        {
            return *volunteers[i];
        }
    }
    // if cant find - return fake volunteer
    const string s = "";
    DriverVolunteer *temp = new DriverVolunteer(-1, s, -1, -1);
    return *temp;
}

Order &WareHouse::getOrder(int orderId) const
{
    // returns a reference to the costumer if exists in the customers vector
    for (vector<Order *>::size_type i = 0; i < pendingOrders.size(); i++)
    {
        if (pendingOrders[i]->getId() == orderId)
        {
            return *pendingOrders[i];
        }
    }
    for (vector<Order *>::size_type i = 0; i < inProcessOrders.size(); i++)
    {
        if (inProcessOrders[i]->getId() == orderId)
        {
            return *inProcessOrders[i];
        }
    }
    for (vector<Order *>::size_type i = 0; i < completedOrders.size(); i++)
    {
        if (completedOrders[i]->getId() == orderId)
        {
            return *completedOrders[i];
        }
    }
    // if cant find - return fake order
    Order *temp = new Order(-1, -1, -1);
    return *temp;
}

const vector<BaseAction *> &WareHouse::getActions() const
{
    return actionsLog;
}

void WareHouse::close()
{
    // close- change isOpen to false to break the main loop. call to destructors?
    isOpen = false;
}

void WareHouse::open()
{
    // close- change isOpen to false to break the main loop. call to destructors?
    isOpen = true;
}

int WareHouse::getIdNewCustomer()
{
    // returns new customer id
    customerCounter++;
    return customerCounter;
}
int WareHouse::getIdNewvolunteer()
{
    // returns new volunteer id
    volunteerCounter++;
    return volunteerCounter;
}
int WareHouse::getIdNeworder()
{
    // returns new order id
    orderCounter++;
    return orderCounter;
}

void WareHouse::handOverOrders()
{
    // Step 1: Hand over orders to volunteers
    for (Order *&order : pendingOrders)
    {
        for (Volunteer *&volunteer : volunteers)
        {
            if (volunteer->canTakeOrder(*order))
            {
                volunteer->acceptOrder(*order);
                inProcessOrders.push_back(order);
                break; // Order handed over, move to the next order
            }
        }
    }

    // Clear the pendingOrders list after handing over
    pendingOrders.clear();
}

void WareHouse::performSimulationStep()
{
    // Step 2: Perform a step in the simulation
    for (Volunteer *&volunteer : volunteers)
    {
        volunteer->step();
    }
}

void WareHouse::checkVolunteers()
{
    // Step 3: Check if volunteers have finished processing their orders
    for (std::vector<Order *>::iterator it = inProcessOrders.begin(); it != inProcessOrders.end();)
    {
        Order *order = *it;
        bool orderCompleted = false;

        for (auto &volunteer : volunteers)
        {
            if (volunteer->getActiveOrderId() == order->getId())
            {
                // Volunteer is still processing the order
                orderCompleted = volunteer->isBusy() ? false : true;
                break;
            }
        }

        if (orderCompleted)
        {
            completedOrders.push_back(order);
            it = inProcessOrders.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void WareHouse::deleteFinishedVolunteers()
{
    // Step 4: Delete volunteers that reached maxOrders limit and finished handling their last order
    std::vector<Volunteer *>::iterator it = volunteers.begin();
    while (it != volunteers.end())
    {
        Volunteer *volunteer = *it;
        if (volunteer->hasOrdersLeft() && volunteer->getActiveOrderId() == NO_ORDER)
        {
            // Volunteer reached maxOrders limit and finished handling the last order
            it = volunteers.erase(it);
            delete volunteer; // Free the memory
        }
        else
        {
            ++it;
        }
    }
}

//   int main(int argc, char** argv){

//      WareHouse a = WareHouse("/home/shubb/spl-Task1/spl-Task1/bin/configFileExample.txt");
//    Customer* yos = new CivilianCustomer(212400113,"yossi",10,3);
//   a.addCustomer(yos);
//   Order* o = new Order(1,212400113,3);
//   a.addOrder(o);
//   a.start();
//   return 0;
//}