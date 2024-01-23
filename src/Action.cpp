#include "../include/Action.h"
#include <iostream>

BaseAction::BaseAction() : errorMsg(""), status()
{
}

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

// AddOrder Class implementetion
AddOrder::AddOrder(int id) : customerId(id)
{
} // constructor initializes id

void AddOrder::act(WareHouse &wareHouse)
{
    Customer *a = &wareHouse.getCustomer(customerId);
    if (a->getId() <= -1 || !a->canMakeOrder())
    {
        // not valid customer id or customer reached max orders
        if (a->getId() == -1)
        {
            delete a;
        }
        error("Cannot place this order");
        std::cout << "Error: " << getErrorMsg() << std::endl;
    }
    else
    {
        int orderID = wareHouse.getIdNeworder();
        int distance = a->getCustomerDistance();
        Order *order = new Order(orderID, customerId, distance);
        wareHouse.addOrder(order);
        complete();
    }
}

string AddOrder::toString() const{
    return "temp";
}

AddOrder* AddOrder::clone() const{
    return new AddOrder(*this);
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
}

std::string SimulateStep::toString() const
{
    return "SimulateStep: " + std::to_string(numOfSteps) + " steps";
}

SimulateStep *SimulateStep::clone() const
{
    return new SimulateStep(*this);
}
