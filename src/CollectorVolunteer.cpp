#include "../include/Volunteer.h"
#include "../include/Order.h"
#include <string>
#include <vector>
using std::string;
using std::vector;


CollectorVolunteer::CollectorVolunteer(int id, const string &name, int coolDown)
    : CollectorVolunteer(id, name, coolDown)
{
    // not sure if the inheritance is being done correctly.
}

CollectorVolunteer *CollectorVolunteer::clone() const
{
    CollectorVolunteer *a = new CollectorVolunteer(getId(), getName(), getCoolDown()); 
    a->timeLeft = getTimeLeft();  
    return (a);
}

bool CollectorVolunteer::hasOrdersLeft() const{
    return true;
}

bool CollectorVolunteer::canTakeOrder(const Order &order) const{
    return ((coolDown == 0)&&(getActiveOrderId == 0));
}

// virtual void acceptOrder(const Order &order) = 0;
// Prepare for new order(Reset activeOrderId,TimeLeft,DistanceLeft,OrdersLeft depends on the volunteer type)

void CollectorVolunteer::acceptOrder(const Order &order){
    activeOrderId = order.getId();
    timeLeft = coolDown;
}
