#include "../include/Action.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using std::string;
using std::vector;


PrintActionsLog::PrintActionsLog(){}

void PrintActionsLog::act(WareHouse &wareHouse)
{
    std::stringstream st;   
    std::vector<BaseAction*> actions = wareHouse.getActions();
    for(BaseAction* act : actions){
        //every action toString is ready for conditions of log - run all vector
        st << act->toString() << std::endl;
    }
    std::cout << st.str() ;
    complete();
    //add the last log action to actions vector
    wareHouse.addAction(this);


}
string PrintActionsLog::toString() const
{
    return "log COMPLETED";
}
PrintActionsLog *PrintActionsLog::clone() const
{
    //cloning the PrintActionsLog action
    return new PrintActionsLog(*this);
}
