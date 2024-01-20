#include "../include/Action.h"

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







