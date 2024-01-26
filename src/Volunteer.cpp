#include "../include/Volunteer.h" 
#include <string>
#include <vector>
using std::string;
using std::vector;

Volunteer::Volunteer(int id, const string &name) : completedOrderId(NO_ORDER), activeOrderId(NO_ORDER), id(id), name(name) {}
//cunstructs to default values and fathers values

int Volunteer::getId() const
{
    return id;
}

const string &Volunteer::getName() const
{
    return name;
}

int Volunteer::getActiveOrderId() const
{
    return activeOrderId;
}

int Volunteer::getCompletedOrderId() const
{
    return completedOrderId;
}

bool Volunteer::isBusy() const
{
    //busy if there is an order
    return activeOrderId != NO_ORDER;
}
