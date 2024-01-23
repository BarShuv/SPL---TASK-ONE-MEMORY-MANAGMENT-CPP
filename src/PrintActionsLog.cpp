#include "../include/Volunteer.h" // Include the Volunteer class header
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
    wareHouse.addAction(this);
    std::vector<BaseAction*> actions = wareHouse.getActions();
    for(BaseAction* act : actions){
        st << act->toString() << std::endl;
    }
    std::cout << st.str() << std::endl;
    complete();

}
string PrintActionsLog::toString() const
{
    return "log COMPLETED";
}
PrintActionsLog *PrintActionsLog::clone() const
{
    return new PrintActionsLog(*this);
}
