#include "../include/Volunteer.h" // Include the Volunteer class header
#include "../include/Order.h" // Include the Order class header
#include <string>
#include <vector>
using std::string;
using std::vector;

Volunteer::Volunteer(int idP, const string &nameP) : id(idP), name(nameP), completedOrderId(0), activeOrderId(0) {}

int Volunteer::getId() const {
    return id;
}

const string &Volunteer::getName() const {
    return name;
}

int Volunteer::getActiveOrderId() const{
    if(activeOrderId==0) {
        // add code to handle 0
    }
    else return activeOrderId;
}

int Volunteer::getCompletedOrderId() const{
    if(completedOrderId==0) {
        // add code to handle 0
    }
    else return completedOrderId;
}

bool Volunteer::isBusy() const{
    if(activeOrderId == 0) return false;
    return true;
}
