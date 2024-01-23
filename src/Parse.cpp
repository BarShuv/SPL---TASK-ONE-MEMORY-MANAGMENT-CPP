#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../include/WareHouse.h"



bool WareHouse:: doParse(std::string file_name){

    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "Error opening file. Make sure the file is in the correct location and check permissions." << std::endl;
        return false;
    }

    std::string line;
    std::string firstWord; //can be volunteer or customer
    //parameters for costumer
    std::string customerName, customerType;
    int distance, maxOrders;
    //parameters for volunteer
    std::string  volunteerName, volunteerType; //type - collector, limited collector , driver, limited driver
    int coolDown,maxOrdersCollector; // collector fields
    int maxDistance,distance_per_step,maxOrdersDriver; //driver fields
    while (std::getline(file, line)) {
        //get the line
        std::istringstream iss(line);

        if (iss >> firstWord) {
            // firstWord now contains the first word of the inputString

            if (firstWord == "customer") {
                // Extract customer details and add them to your system
                if (iss >> customerName >> customerType >> distance >> maxOrders) {
                    
                    //corresponding variables filled with the parsed values
                    //std::cout << customerName << customerType<< distance<< maxOrders<< std::endl;
                    ///////////////////////////////////////////////////////////////
                    
                    if (customerType == "civilian")
                    {
                        CivilianCustomer* cust = new CivilianCustomer(this->getIdNewCustomer(), customerName, distance, maxOrders);
                        this->addCustomer(cust);

                    }
                    else
                    {
                        SoldierCustomer* cust = new SoldierCustomer(this->getIdNewCustomer(), customerName, distance, maxOrders);
                        this->addCustomer(cust);
                    }
                } 
                else {
                    //std::cerr << "Error parsing customer details." << std::endl;
                }
                

        } 
        else if (firstWord == "volunteer") {
                // Extract volunteer details and add them to your system
                if (iss >> volunteerName >> volunteerType) {
                    if (volunteerType == "collector")
                    {
                        iss >> coolDown;
                        //std::cout <<volunteerName << volunteerType <<coolDown<< "it is" << std::endl;    
                        CollectorVolunteer* vol = new CollectorVolunteer(this->getIdNewvolunteer(), volunteerName, coolDown);
                        this->addVolunteer(vol);
                    }

                    if (volunteerType == "limited_collector")
                    {
                        iss >> coolDown >> maxOrdersCollector;
                        //std::cout <<volunteerName << volunteerType <<coolDown<<maxOrdersCollector<< " it is" << std::endl;                        
                        LimitedCollectorVolunteer* vol = new LimitedCollectorVolunteer(this->getIdNewvolunteer(), volunteerName, coolDown,maxOrdersCollector);
                        this->addVolunteer(vol);
                    }
                    if (volunteerType == "driver")
                    {
                        iss >> maxDistance >> distance_per_step;
                        //std::cout <<volunteerName << volunteerType <<maxDistance<<distance_per_step<< " it is" << std::endl;                        
                        DriverVolunteer* vol = new DriverVolunteer(this->getIdNewvolunteer(), volunteerName, maxDistance, distance_per_step);
                        this->addVolunteer(vol);
                    }
                    if (volunteerType == "limited_driver")
                    {
                        iss >> maxDistance >> distance_per_step>>maxOrdersDriver;
                        //std::cout <<volunteerName << volunteerType <<maxDistance<<distance_per_step<< maxOrdersDriver<<" it is" << std::endl;                        
                        LimitedDriverVolunteer* vol = new LimitedDriverVolunteer(this->getIdNewvolunteer(), volunteerName, maxDistance, distance_per_step,maxOrdersDriver);
                        this->addVolunteer(vol);
                    }
                    
                } 
                else {
                //std::cerr << "Error parsing volunteer details." << std::endl;
                }

            } 
            else {
                //std::cout << "Not recognized word" << std::endl;
            }
        
        }
        else {
            // Handle the case where the string is empty
            //std::cerr << "The input string is empty." << std::endl;
        }
    }

    file.close();
    return true;

    }


//int main() {

//  Parse::doParse("asd");
// return 0;
//}
