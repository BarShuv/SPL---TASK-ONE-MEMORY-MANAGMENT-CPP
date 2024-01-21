#include "../include/Action.h"
#include <iostream>

BaseAction::BaseAction():errorMsg(""),status()
{}

ActionStatus BaseAction::getStatus() const
{
    //returns status of action
    return status;
}

void BaseAction::complete()
{
    //changes status to completed
    status = ActionStatus::COMPLETED;
}
void BaseAction::error(string errorMsg){
    //sets status to error and chnges to correct error message
    status = ActionStatus::ERROR;
    this->errorMsg=errorMsg;
}
string BaseAction::getErrorMsg() const
{
    //returns the error message
    return errorMsg;
}




//AddOrder Class implementetion
AddOrder::AddOrder(int id):customerId(id)
{}//constructor initializes id

void AddOrder::act(WareHouse &wareHouse) 
{
    Customer* a =&wareHouse.getCustomer(customerId);
    if (a->getId() ==-1 || !a->canMakeOrder())
    {
        //not valid customer id or customer reached max orders
        if(a->getId() ==-1){
        delete a;
        }
        error("Cannot place this order");
        std::cout <<"Error: " << getErrorMsg() << std::endl;

    }
    else{
        int orderID = wareHouse.getIdNeworder();
        int distance = a->getCustomerDistance();
        Order* order = new Order(orderID, customerId,distance);
        wareHouse.addOrder(order);
        complete();
    }
}
