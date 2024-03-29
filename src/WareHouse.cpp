#include "../include/WareHouse.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> // for std::copy
using std::vector;

WareHouse::WareHouse(const string &configFilePath) : isOpen(false),
    // initialize vectors to empty vectors
    actionsLog(), volunteers(), pendingOrders(), inProcessOrders(), completedOrders(), customers(),
    customerCounter(-1),  // first id for customers
    volunteerCounter(-1), // first id for volunteers
    orderCounter(-1),     // first id for orders
    // initialize to junk values the defaults - need to destruct it also
    defualtCustomer(new CivilianCustomer(-1, "", -1, -1)),
    defaultVolunteer(new DriverVolunteer(-1, "", -1, -1)),
    defaultOrder(new Order(-1, -1, -1))
{

    this->doParse(configFilePath);
}

// Copy constructor
WareHouse::WareHouse(const WareHouse &other)
    : isOpen(other.isOpen),
      actionsLog(),volunteers(),pendingOrders(),inProcessOrders(),completedOrders(),customers(),customerCounter(other.customerCounter),
        volunteerCounter(other.volunteerCounter),
      orderCounter(other.orderCounter),
      defualtCustomer(new CivilianCustomer(-1, "", -1, -1)),
      defaultVolunteer(new DriverVolunteer(-1, "", -1, -1)),
      defaultOrder(new Order(-1, -1, -1))
{
    // Deep copy for vectors
    for(BaseAction* a: other.actionsLog)
    {
        actionsLog.push_back(a->clone());
    }
    for(Volunteer* v: other.volunteers)
    {
        volunteers.push_back(v->clone());
    }
    for(Order* o: other.pendingOrders)
    {
        pendingOrders.push_back(o->clone());
    }
    for(Order* o: other.inProcessOrders)
    {
        inProcessOrders.push_back(o->clone());
    }
    for(Order* o: other.completedOrders)
    {
        completedOrders.push_back(o->clone());
    }

    for(Customer* c: other.customers)
    {
        customers.push_back(c->clone());
    }

}

WareHouse &WareHouse::operator=(const WareHouse &other)
{
    if (this != &other) // Check for self-assignment
    {
        // delete actionsLog
        for (BaseAction *act : actionsLog)
        {
            delete act;
        }
        // delete volunteers;
        for (Volunteer *vol : volunteers)
        {   
            //std::cout << vol->getName() <<std::endl;
            delete vol;
        }
        
        // delete pendingOrders;
        for (Order *ord : pendingOrders)
        {
            delete ord;
        }
        // delete inProcessOrders;
        for (Order *ord : inProcessOrders)
        {
            delete ord;
        }
        // delete completedOrders;
        for (Order *ord : completedOrders)
        {
            delete ord;
        }
        // delete customers;
        for (Customer *cus : customers)
        {
            delete cus;
        }

        // Copy data from 'other' to 'this'
        isOpen = other.isOpen;

        customerCounter = other.customerCounter;
        volunteerCounter = other.volunteerCounter;
        orderCounter = other.orderCounter;
        // clear all this vectors before inserting
        actionsLog.clear();
        volunteers.clear();
        pendingOrders.clear();
        inProcessOrders.clear();
        completedOrders.clear();
        completedOrders.clear();
        customers.clear();
        // Deep copy for vectors
        for(BaseAction* a: other.actionsLog)
        {
            actionsLog.push_back(a->clone());
        }
        for(Volunteer* v: other.volunteers)
        {
            volunteers.push_back(v->clone());
        }
        for(Order* o: other.pendingOrders)
        {
            pendingOrders.push_back(o->clone());
        }
        for(Order* o: other.inProcessOrders)
        {
            inProcessOrders.push_back(o->clone());
        }
        for(Order* o: other.completedOrders)
        {
            completedOrders.push_back(o->clone());
        }

        for(Customer* c: other.customers)
        {
            customers.push_back(c->clone());
        }

    }
    return *this;
}

WareHouse::WareHouse(WareHouse &&other) noexcept
    : isOpen(other.isOpen),
      actionsLog(), volunteers(), pendingOrders(), inProcessOrders(), completedOrders(), customers(),
      customerCounter(other.customerCounter),
      volunteerCounter(other.volunteerCounter),
      orderCounter(other.orderCounter),
      defualtCustomer(other.defualtCustomer),
      defaultVolunteer(other.defaultVolunteer),
      defaultOrder(other.defaultOrder)
{
    // Deep copy for vectors
    for(BaseAction* a: other.actionsLog)
    {
        actionsLog.push_back(a->clone());
    }
    for(Volunteer* v: other.volunteers)
    {
        volunteers.push_back(v->clone());
    }
    for(Order* o: other.pendingOrders)
    {
        pendingOrders.push_back(o->clone());
    }
    for(Order* o: other.inProcessOrders)
    {
        inProcessOrders.push_back(o->clone());
    }
    for(Order* o: other.completedOrders)
    {
        completedOrders.push_back(o->clone());
    }

    for(Customer* c: other.customers)
    {
        customers.push_back(c->clone());
    }
    // clear all others vectors
    other.actionsLog.clear();
    other.volunteers.clear();
    other.pendingOrders.clear();
    other.inProcessOrders.clear();
    other.completedOrders.clear();
    other.completedOrders.clear();
    other.defaultOrder =nullptr;
    other.defaultVolunteer = nullptr;
    other.defaultOrder=nullptr;
}

WareHouse &WareHouse::operator=(WareHouse &&other) noexcept
{
    if (this != &other)
    {     
        // delete actionsLog
        for (BaseAction *act : actionsLog)
        {
            delete act;
        }
        // delete volunteers;
        for (Volunteer *vol : volunteers)
        {   
            //std::cout << vol->getName() <<std::endl;
            delete vol;
        }
        
        // delete pendingOrders;
        for (Order *ord : pendingOrders)
        {
            delete ord;
        }
        // delete inProcessOrders;
        for (Order *ord : inProcessOrders)
        {
            delete ord;
        }
        // delete completedOrders;
        for (Order *ord : completedOrders)
        {
            delete ord;
        }
        // delete customers;
        for (Customer *cus : customers)
        {
            delete cus;
        }
        // clear all this vectors before inserting
        actionsLog.clear();
        volunteers.clear();
        pendingOrders.clear();
        inProcessOrders.clear();
        completedOrders.clear();
        completedOrders.clear();
        customers.clear();

        // take others fields
        isOpen = other.isOpen;
        customerCounter = other.customerCounter;
        volunteerCounter = other.volunteerCounter;
        orderCounter = other.orderCounter,
        defualtCustomer = other.defualtCustomer;
        defaultVolunteer = other.defaultVolunteer;
        defaultOrder = other.defaultOrder;

        // Deep copy for vectors
        for(BaseAction* a: other.actionsLog)
        {
            actionsLog.push_back(a->clone());
        }
        for(Volunteer* v: other.volunteers)
        {
            volunteers.push_back(v->clone());
        }
        for(Order* o: other.pendingOrders)
        {
            pendingOrders.push_back(o->clone());
        }
        for(Order* o: other.inProcessOrders)
        {
            inProcessOrders.push_back(o->clone());
        }
        for(Order* o: other.completedOrders)
        {
            completedOrders.push_back(o->clone());
        }

        for(Customer* c: other.customers)
        {
            customers.push_back(c->clone());
        }
        // clear all others vectors
        other.actionsLog.clear();
        other.volunteers.clear();
        other.pendingOrders.clear();
        other.inProcessOrders.clear();
        other.completedOrders.clear();
        other.completedOrders.clear();
        other.defaultOrder =nullptr;
        other.defaultVolunteer = nullptr;
        other.defaultOrder=nullptr;
    }
    return *this;
}

WareHouse::~WareHouse()
{
    // delete actionsLog
    for (BaseAction *act : actionsLog)
    {
        delete act;
    }
    // delete volunteers;
    for (Volunteer *vol : volunteers)
    {   
        //std::cout << vol->getName() <<std::endl;
        delete vol;
    }
    
    // delete pendingOrders;
    for (Order *ord : pendingOrders)
    {
        delete ord;
    }
    // delete inProcessOrders;
    for (Order *ord : inProcessOrders)
    {
        delete ord;
    }
    // delete completedOrders;
    for (Order *ord : completedOrders)
    {
        delete ord;
    }
    // delete customers;
    for (Customer *cus : customers)
    {
        delete cus;
    }
    delete defaultOrder;
    delete defaultVolunteer;
    delete defualtCustomer;
    
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

        std::getline(std::cin, userInput);

        // Use stringstream to extract the first word
        std::stringstream ss(userInput);
        ss >> command;

        // Switch based on the first word
        if (command == "step")
        {
            int number_of_steps;
            //takes the secont word
            ss >> number_of_steps;
            SimulateStep *simStep = new SimulateStep(number_of_steps);
            simStep->act(*this);
        }
        else if (command == "order")
        {
            int customer_id;
            ss >> customer_id;
            AddOrder *addOrder = new AddOrder(customer_id);
            addOrder->act(*this);
        }

        else if (command == "customer")
        {
            string customer_name;
            string customer_type;
            int customer_distance;
            int max_orders;
            //takes arguments from user input
            ss >> customer_name;
            ss >> customer_type;
            ss >> customer_distance;
            ss >> max_orders;

            AddCustomer *addCustomer = new AddCustomer(customer_name, customer_type, customer_distance, max_orders);
            addCustomer->act(*this);
        }

        else if (command == "orderStatus")
        {
            int order_id;
            ss >> order_id;
            PrintOrderStatus *printOrder = new PrintOrderStatus(order_id);
            printOrder->act(*this);
        }

        else if (command == "customerStatus")
        {
            int customer_id;
            ss >> customer_id;
            PrintCustomerStatus *printCustomer = new PrintCustomerStatus(customer_id);
            printCustomer->act(*this);
        }

        else if (command == "volunteerStatus")
        {
            int volunteer_id;
            ss >> volunteer_id;
            PrintVolunteerStatus *printvolunteer = new PrintVolunteerStatus(volunteer_id);
            printvolunteer->act(*this);
        }

        else if (command == "log")
        {
            PrintActionsLog *log = new PrintActionsLog();
            log->act(*this);
        }

        else if (command == "close")
        {
            Close *close = new Close();
            close->act(*this);
        }

        else if (command == "backup")
        {
            BackupWareHouse *backup = new BackupWareHouse();
            backup->act(*this);
        }

        else if (command == "restore")
        {
            RestoreWareHouse *restore = new RestoreWareHouse();
            restore->act(*this);
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

void WareHouse::downOneOrderId()
{
    // decrease by 1 order id
    orderCounter--;
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
    //run on all pending orders list
    for (std::vector<Order *>::size_type i = 0; i < pendingOrders.size(); i++)
    {
        //search for volunteers
        for (std::vector<Volunteer *>::size_type j = 0; j < volunteers.size(); j++)
        {
            //check for orders in status pending if there is a  free collector for them
            if ((pendingOrders[i]->getStatus() == OrderStatus::PENDING) && volunteers[j]->canTakeOrder(*pendingOrders[i]) && (volunteers[j]->isCollector()))
            {
                //change the order and volunteer parameters
                volunteers[j]->acceptOrder(*pendingOrders[i]);
                pendingOrders[i]->setCollectorId(volunteers[j]->getId());
                pendingOrders[i]->setProcessingTimeLeft(volunteers[j]->getCoolDownFromVol());
                pendingOrders[i]->setStatus(OrderStatus::COLLECTING);
                //move the order to inProc orders
                inProcessOrders.push_back(pendingOrders[i]);
                pendingOrders.erase(pendingOrders.begin() + i);
                i--;
                break; // Order handed over, move to the next order
            }
            //search for orders waiting for a driver
            else if((pendingOrders[i]->getStatus() == OrderStatus::COLLECTING) && volunteers[j]->canTakeOrder(*pendingOrders[i]) && volunteers[j]->isDriver())
            {
                //set the volunteer and order parameters
                volunteers[j]->acceptOrder(*pendingOrders[i]);
                pendingOrders[i]->setDriverId(volunteers[j]->getId());
                pendingOrders[i]->setStatus(OrderStatus::DELIVERING);
                //move the order to inProc orders
                inProcessOrders.push_back(pendingOrders[i]);
                pendingOrders.erase(pendingOrders.begin() + i);
                i--;
                break; // Order handed over, move to the next order
            }
        }
    }
}

void WareHouse::performSimulationStep()
{
    // Step 2: Perform a step in the simulation
    for (std::vector<Volunteer *>::size_type i = 0; i < volunteers.size(); i++)
    {
        volunteers[i]->step();
    }
    // update processing time left here
    for (std::vector<Order *>::size_type j = 0; j < inProcessOrders.size(); j++)
    {
        Order *order = inProcessOrders[j];
        if (order->getCollectorId() > -1)
        {
            int ptl = order->getProcessingTimeLeft();
            order->setProcessingTimeLeft(ptl - 1);
        }
    }
}


void WareHouse::checkVolunteers()
{
    //run on volunteers vector
    for (std::vector<Volunteer *>::size_type i = 0; i < volunteers.size(); i++)
    {
        Volunteer *vol = volunteers[i];
        int activeOrderId = vol->getActiveOrderId();
        // we check only vol that have active order otherwise we have nothing to update
        if (activeOrderId != -1)
        {
            // first we check the drivers
            for (std::vector<Order *>::size_type j = 0; j < inProcessOrders.size(); j++)
            {
                Order *order = inProcessOrders[j];
                
                if (order->getDriverId() == vol->getId())
                {
                    // if true then driver finished with the order
                    if (vol->getUpdatedDistanceLeft() == 0)
                    {
                        // vol handling
                        vol->resetVolAfterFinishedOrder();
                        // order handling - check if done correctly
                        order->setStatus(OrderStatus::COMPLETED);
                        completedOrders.push_back(order);
                        inProcessOrders.erase(inProcessOrders.begin() + j);
                        j--;
                    }
                    //finished with the order
                    break;
                }
            }

            // now we weill check for collections
            for (std::vector<Order *>::size_type j = 0; j < inProcessOrders.size(); j++)
            {
                Order *order = inProcessOrders[j];
                //
                if (order->getCollectorId() == vol->getId())
                {
                    // if true then driver finished with the order
                    if (vol->getUpdatedDistanceLeft() == 0)
                    {
                        // vol handling
                        vol->resetVolAfterFinishedOrder();
                        // order handling - check if done correctly
                        pendingOrders.push_back(order);
                        inProcessOrders.erase(inProcessOrders.begin() + j);
                        j--;
                    }
                    //finished with the order
                    break;
                }
            }
            
        }
    }


}

void WareHouse::deleteFinishedVolunteers()
{
    // Step 4: Delete volunteers that reached maxOrders limit and finished handling their last order
    for (std::vector<Volunteer *>::size_type i = 0; i < volunteers.size(); i++)
    {
        Volunteer *volunteer = volunteers[i];
        if (!volunteer->hasOrdersLeft() && volunteer->getActiveOrderId() == NO_ORDER)
        {
            //Volunteer reached maxOrders limit and finished handling the last order
            Volunteer *temp = volunteers[i];
            volunteers.erase(volunteers.begin() + i);
            delete temp;
            i--;
        }
    }
}



const vector<Order *> WareHouse::getAllOrders() const
{
    //return all orders in one vector
    vector<Order *> allOrders;

    // Append orders from all three lists
    allOrders.insert(allOrders.end(), pendingOrders.begin(), pendingOrders.end());
    allOrders.insert(allOrders.end(), inProcessOrders.begin(), inProcessOrders.end());
    allOrders.insert(allOrders.end(), completedOrders.begin(), completedOrders.end());

    return allOrders;
}
