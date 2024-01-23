#include "../include/WareHouse.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> // for std::copy
using std::vector;


WareHouse::WareHouse(const string &configFilePath) :
isOpen(false),
//initialize vectors to empty vectors
actionsLog(),volunteers(),pendingOrders(),inProcessOrders(),completedOrders(),customers(),
customerCounter(-1), //first id for customers
volunteerCounter(-1), // first id for volunteers
orderCounter(-1), //first id for orders
//initialize to junk values the defaults - need to destruct it also
defualtCustomer(new CivilianCustomer(-1, "", -1, -1)),
defaultVolunteer(new DriverVolunteer(-1, "", -1, -1)),
defaultOrder(new Order(-1, -1, -1))
{
    this->doParse(configFilePath);
}


// Copy constructor
WareHouse::WareHouse(const WareHouse &other)
    : isOpen(other.isOpen),
      actionsLog(other.actionsLog.size()),
      volunteers(other.volunteers.size()),
      pendingOrders(other.pendingOrders.size()),
      inProcessOrders(other.inProcessOrders.size()),
      completedOrders(other.completedOrders.size()),
      customers(other.customers.size()),
      customerCounter(other.customerCounter),
      volunteerCounter(other.volunteerCounter),
      orderCounter(other.orderCounter)
{
    // Deep copy for vectors
    std::copy(other.actionsLog.begin(), other.actionsLog.end(), actionsLog.begin());
    std::copy(other.volunteers.begin(), other.volunteers.end(), volunteers.begin());
    std::copy(other.pendingOrders.begin(), other.pendingOrders.end(), pendingOrders.begin());
    std::copy(other.inProcessOrders.begin(), other.inProcessOrders.end(), inProcessOrders.begin());
    std::copy(other.completedOrders.begin(), other.completedOrders.end(), completedOrders.begin());
    std::copy(other.customers.begin(), other.customers.end(), customers.begin());
}



WareHouse::~WareHouse(){
    // delete actionsLog;
    for (BaseAction *  act : actionsLog) {
        delete act;
    }
    // delete volunteers;
     for (Volunteer *  vol : volunteers) {
        delete vol;
    }
    // delete pendingOrders;
     for (Order *  ord : pendingOrders) {
        delete ord;
    }
    // delete inProcessOrders;
     for (Order *  ord : inProcessOrders) {
        delete ord;
    }
    // delete completedOrders;
     for (Order *  ord : completedOrders) {
        delete ord;    }
    // delete customers;
     for (Customer *  cus : customers) {
        delete cus;
    }
}
WareHouse &WareHouse::operator=(const WareHouse &other)
{
    if (this != &other) // Check for self-assignment
    {
        // Copy data from 'other' to 'this'
        isOpen = other.isOpen;
        actionsLog = other.actionsLog;
        volunteers = other.volunteers;
        pendingOrders = other.pendingOrders;
        inProcessOrders = other.inProcessOrders;
        completedOrders = other.completedOrders;
        customers = other.customers;

        customerCounter = other.customerCounter;
        volunteerCounter = other.volunteerCounter;
        orderCounter = other.orderCounter;

        // Deep copy for vectors
        std::copy(other.actionsLog.begin(), other.actionsLog.end(), std::back_inserter(actionsLog));
        std::copy(other.volunteers.begin(), other.volunteers.end(), std::back_inserter(volunteers));
        std::copy(other.pendingOrders.begin(), other.pendingOrders.end(), std::back_inserter(pendingOrders));
        std::copy(other.inProcessOrders.begin(), other.inProcessOrders.end(), std::back_inserter(inProcessOrders));
        std::copy(other.completedOrders.begin(), other.completedOrders.end(), std::back_inserter(completedOrders));
        std::copy(other.customers.begin(), other.customers.end(), std::back_inserter(customers));
    }
    return *this;
}



//WareHouse::WareHouse(WareHouse&& other) noexcept
    //: isOpen(other.isOpen),
//initialize vectors to empty vectors
//actionsLog(other.actionsLog),volunteers(),pendingOrders(),inProcessOrders(),completedOrders(),customers(),
//customerCounter(-1), //first id for customers
//volunteerCounter(-1), // first id for volunteers
//orderCounter(-1) //first id for orders
//{


    //other.actionsLog[0] = nullptr;
    //delete &other.actionsLog;


//}
















void WareHouse::start()
{
    open();
    string userInput;
    // break the input to command and parameters
    string command;

    std::cout << "Warehouse is open!" << std::endl;

    while (isOpen)
    {

        //std::cout << "Enter a command: ";
        std::getline(std::cin, userInput);

        // Use stringstream to extract the first word
        std::stringstream ss(userInput);
        ss >> command;

    // Switch based on the first word
    if (command == "step") {
        int number_of_steps;
        ss >> number_of_steps;
        //std::cout << "entered step " <<  number_of_steps << std::endl;
        SimulateStep* simStep =new SimulateStep(number_of_steps);
        simStep->act(*this);
    } 
    else if (command == "order") {
        int customer_id;
        ss >> customer_id;
        //std::cout << "entered order " <<  customer_id << std::endl;
        AddOrder* addOrder = new AddOrder(customer_id);
        addOrder->act(*this);
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

            //std::cout << "entered customer " << customer_name << std::endl;
            AddCustomer* addCustomer = new AddCustomer(customer_name,customer_type,customer_distance,max_orders);
            addCustomer->act(*this);
        }

        else if (command == "orderStatus")
        {
            int order_id;
            ss >> order_id;
            //std::cout << "entered orderStatus " << order_id << std::endl;
            PrintOrderStatus* printOrder = new PrintOrderStatus(order_id);
            printOrder->act(*this);
        }

        else if (command == "customerStatus")
        {
            int customer_id;
            ss >> customer_id;
            //std::cout << "entered customerStatus " << customer_id << std::endl;
            PrintCustomerStatus* printCustomer = new PrintCustomerStatus(customer_id);
            printCustomer->act(*this);
        }

        else if (command == "volunteerStatus")
        {
            int volunteer_id;
            ss >> volunteer_id;
            //std::cout << "entered volunteerStatus " << volunteer_id << std::endl;
            PrintVolunteerStatus* printvolunteer = new PrintVolunteerStatus(volunteer_id);
            printvolunteer->act(*this);
        }

        else if (command == "log")
        {
            //std::cout << "entered log " << std::endl;
            PrintActionsLog* log = new PrintActionsLog();
            log->act(*this);
        }

        else if (command == "close")
        {
            //std::cout << "entered close " << std::endl;
            Close* close = new Close();
            close->act(*this);
        }

        else if (command == "backup")
        {
            std::cout << "entered backup " << std::endl;
            //BackupWareHouse* backup = new BackupWareHouse();
            //backup->act(*this);
        }

        else if (command == "restore")
        {
            std::cout << "entered restore " << std::endl;
            //RestoreWareHouse* restore =new RestoreWareHouse();
            //restore->act(*this);
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
    // if cant find - return default customer
    return *defualtCustomer;
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
    // if cant find - return default volunteer
    return *defaultVolunteer;
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
    // if cant find - return default order
    return *defaultOrder;
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
    std::vector<Order*>::iterator it = pendingOrders.begin();
    // Step 1: Hand over orders to volunteers
    while (it != pendingOrders.end())
    {
        Order* &order = *it;
        for (Volunteer *&volunteer : volunteers)
        {
            if (volunteer->canTakeOrder(*order) && (volunteer->isCollector()))
            {
                volunteer->acceptOrder(*order);
                order->setCollectorId(volunteer->getId());
                inProcessOrders.push_back(order);
                pendingOrders.erase(it);
                break; // Order handed over, move to the next order
            }
        }
        ++it;
    }


     std::vector<Order*>::iterator it2 = inProcessOrders.begin();
    while (it2 != inProcessOrders.end())
    {
        Order* &order = *it2; 
        for (Volunteer *&volunteer : volunteers)
        {
            if (volunteer->canTakeOrder(*order) && volunteer->isDriver())
            {
                volunteer->acceptOrder(*order);
                order->setDriverId(volunteer->getId());
                inProcessOrders.push_back(order);
                pendingOrders.erase(it);
                break; // Order handed over, move to the next order
            }
        }
        ++it;
    }

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


const vector<vector<Order*>> &WareHouse::getAllOrders() const{
    vector<vector<Order*>> allOrders{ pendingOrders,inProcessOrders,completedOrders };
    return allOrders;
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