#include "../include/Action.h"
#include <iostream>
extern WareHouse* backup;

BaseAction::BaseAction() : errorMsg(""), status()
//construct to default values
{}

ActionStatus BaseAction::getStatus() const
{
    // returns status of action
    return status;
}

void BaseAction::complete()
{
    // changes status to completed
    status = ActionStatus::COMPLETED;
}
void BaseAction::error(string errorMsg)
{
    // sets status to error and chnges to correct error message
    status = ActionStatus::ERROR;
    this->errorMsg = errorMsg;
}
string BaseAction::getErrorMsg() const
{
    // returns the error message
    return errorMsg;
}

//////////////////addorder actions////////////////////////


// AddOrder Class implementetion
AddOrder::AddOrder(int id) : customerId(id)
{
} // constructor initializes id

void AddOrder::act(WareHouse &wareHouse)
{
    Customer* a = &wareHouse.getCustomer(customerId);

    // not valid customer id or customer reached max orders
    if (a->getId() == -1)
    {
        error("Cannot place this order");
        std::cout << "Error: " << getErrorMsg() << std::endl;
    }
    else
    {
        int orderID = wareHouse.getIdNeworder();
        if(a->addOrder(orderID) ==-1)
        {
            //if reached max orders
            error("Cannot place this order");
            std::cout << "Error: " << getErrorMsg() << std::endl;
            //decrease id back - not valid order
            wareHouse.downOneOrderId();
        }
        else
        {//make new order and add this to the pending orders vector
            int distance = a->getCustomerDistance();
            Order *order = new Order(orderID, customerId, distance);
            wareHouse.addOrder(order);
            complete();
        }
    }
    //add to actions vector
    wareHouse.addAction(this);

}

string AddOrder::toString() const 
{
    //return string matches to the action status and customerId
    ActionStatus actionStatus = getStatus();
    if (actionStatus == ActionStatus::COMPLETED) {
        return "order " + std::to_string(customerId) + " COMPLETED";
    } else {
        return "order " + std::to_string(customerId) + " ERROR";
    }

}

AddOrder* AddOrder::clone() const 
{
    //cloning the AddOrder action
    return new AddOrder(*this);

}


//////////////////add customer actions////////////////////


AddCustomer::AddCustomer(const string &customerName, const string &customerType, int distance, int maxOrders)
    : customerName(customerName),  customerType(customerType == "soldier" ? CustomerType::Soldier : CustomerType::Civilian), distance(distance), maxOrders(maxOrders)
{}    // Set customerType based on the provided string

void AddCustomer:: act(WareHouse &wareHouse) 
{
    if(customerType == CustomerType::Soldier)
    {
        //make new Soldier Customer if the type input is soldier, add it to customers list
        Customer* customer = new SoldierCustomer(wareHouse.getIdNewCustomer(), customerName, distance, maxOrders);
        wareHouse.addCustomer(customer);
    }
    else
    {
        //make new Civilian Customer if the type input is civilian, add it to customers list
        Customer* customer = new CivilianCustomer(wareHouse.getIdNewCustomer(), customerName, distance, maxOrders);
        wareHouse.addCustomer(customer);
    }
    //add to actions 
    wareHouse.addAction(this);
    complete();
}



string AddCustomer::toString() const 
{
    //return string matches to the customer type and parameters
    if(customerType == CustomerType::Soldier)
    {
        return "customer " + customerName +  " soldier " + std::to_string(distance) +" " + std::to_string(maxOrders) + " COMPLETED";
    }
    else
    {
        return "customer " + customerName +  " civilian " + std::to_string(distance) +" " + std::to_string(maxOrders) + " COMPLETED";
    }
}

AddCustomer* AddCustomer::clone() const 
{
    //cloning the AddOrder action
    return new AddCustomer(*this);
}



/////////////////////////////////////////////print order ststus actions
PrintOrderStatus::PrintOrderStatus(int id):orderId(id)
{} // construct object with integer given order id

void PrintOrderStatus::act(WareHouse &wareHouse) {
    Order* o = &wareHouse.getOrder(orderId);
    if (o->getId() ==-1)
    {  
        //if get order function return defult order
        error("Order doesn't exists");
        std::cout << "Error: " << getErrorMsg() << std::endl;
    }
    else
    {
        //orders toString ACTION PRINTS THE INFORMATION
        std::cout << o->toString() << std::endl;
        complete();
    }
    //add the action to actions vector
    wareHouse.addAction(this);
}

PrintOrderStatus* PrintOrderStatus:: clone() const
{
    //returns new PrintOrderStatus object with same values
    return new PrintOrderStatus(*this);
}

string PrintOrderStatus::toString() const 
{
    //return string matches to the action status and order Id
    ActionStatus actionStatus = getStatus();
    if (actionStatus == ActionStatus::COMPLETED) {
        return "orderStatus " + std::to_string(orderId) + " COMPLETED";
    } else {
        return "orderStatus " + std::to_string(orderId) + " ERROR";
    }
}


///////////////////////////////Print Customer Status
PrintCustomerStatus::PrintCustomerStatus(int customerId):customerId(customerId)
{} // construct object with integer given customer id

void PrintCustomerStatus::act(WareHouse &wareHouse){
    //get the customer object
    Customer* c = &wareHouse.getCustomer(customerId);
    if (c->getId() ==-1)
    {  
        //if get customer function return defult customer delete it
        error("Customer doesn't exsists");
        std::cout << "Error: " << getErrorMsg() << std::endl;
    }
    else
    {
        std::cout << "CustomerID: "<< c->getId() << std::endl;
        //run on the ids of customer's orders and print every id and status of order
        vector<int> ordersIds = c->getOrdersIds();
        for (std::vector<int>::size_type i = 0; i < ordersIds.size(); i++) {
            //run on the customers orders ids
            std::cout << "OrderID: " << ordersIds[i] <<std::endl;
            //get the order object
            Order* o = &wareHouse.getOrder(ordersIds[i]) ;
            std::cout << "OrderStatus: " << o->getStatusStr() <<std::endl;
        }

        std::cout << "numOrdersLeft: "<< c->getOrdersLeft()  << std::endl;

        complete();
    }
    //add to actions 
    wareHouse.addAction(this);
}


PrintCustomerStatus* PrintCustomerStatus:: clone() const
{
    //returns new PrintCustomerStatus object with same values
    return new PrintCustomerStatus(*this);
}

string PrintCustomerStatus::toString() const 
{
    //return string matches to the action status and customerId
    ActionStatus actionStatus = getStatus();
    if (actionStatus == ActionStatus::COMPLETED) {
        return "customerStatus " + std::to_string(customerId) + " COMPLETED";
    } else {
        return "customerStatus " + std::to_string(customerId) + " ERROR";
    }
}




SimulateStep::SimulateStep(int numOfSteps) : numOfSteps(numOfSteps) {}

void SimulateStep::act(WareHouse &wareHouse)
{
    int stepsLeft = numOfSteps;
    while (stepsLeft > 0)
    {
        // Reduce number of steps left
        stepsLeft = stepsLeft -1;
        
        // Step 1: Hand over orders to volunteers
        wareHouse.handOverOrders();

        // Step 2: Perform a step in the simulation
        wareHouse.performSimulationStep();

        // Step 3: Check if volunteers have finished processing their orders
        wareHouse.checkVolunteers();

        // Step 4: Delete volunteers that reached maxOrders limit and finished handling their last order
        wareHouse.deleteFinishedVolunteers();

        // Complete the action
        complete();

    }
    wareHouse.addAction(this);

}

std::string SimulateStep::toString() const
{
    return "simulateStep " + std::to_string(numOfSteps) + " COMPLETED";
}

SimulateStep *SimulateStep::clone() const
{
    return new SimulateStep(*this);
}













 //////////////////////////////////backup 
    
BackupWareHouse::BackupWareHouse()
{}

void BackupWareHouse:: act(WareHouse &wareHouse) {
    //use operator = assignment to assign the current warehouse
    backup = new WareHouse(wareHouse);
    wareHouse.addAction(this);
    complete();
}
BackupWareHouse* BackupWareHouse:: clone() const 
{
    //cloning the backup action
    return new BackupWareHouse(*this);
}
string BackupWareHouse::toString() const 
{
    return "backup COMPLETED";
}



////////////////////////////////restore

RestoreWareHouse::RestoreWareHouse(){}

void RestoreWareHouse:: act(WareHouse &wareHouse) {
    if(backup!=nullptr)
    {
        //use assignment opperator = to assign the backup values to current wareHouse
        wareHouse = *backup;
    }
    else
    {
        //if no backup available its error
        error("No backup available");
        std::cout << "Error: " << getErrorMsg() << std::endl;
    }
    wareHouse.addAction(this);
    complete();
}
RestoreWareHouse* RestoreWareHouse::clone() const {
    //cloning the RestoreWareHouse action
    return new RestoreWareHouse(*this);
}
string RestoreWareHouse::toString() const {
    //return string matches the status
    ActionStatus actionStatus = getStatus();
    if (actionStatus == ActionStatus::COMPLETED) {
        return "restore COMPLETED";
    } else {
        return "restore ERROR";
    }
}












