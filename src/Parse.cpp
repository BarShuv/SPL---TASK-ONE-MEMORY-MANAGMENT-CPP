#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    // Replace "ConfigFileExample.txt" with the actual file name
    std::ifstream file("./bin/configFileExample.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file. Make sure the file is in the correct location and check permissions." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Process the line here
        // std::cout << "Read line: " << line << std::endl;

        std::istringstream iss(line);
        std::string firstWord;
        std::string category, customerName, customerType;
        int distance, maxOrders;


        if (iss >> firstWord) {
            // firstWord now contains the first word of the inputString
            std::cout << "First word: " << firstWord << std::endl;

            if (firstWord == "customer") {
                std::cout << "Yes, the first word is 'customer'" << std::endl;
                // Extract customer details and add them to your system
                if (iss >> customerName >> customerType >> distance >> maxOrders) {
                    // Now, you have the corresponding variables filled with the parsed values
                    std::cout << "Customer Name: " << customerName << std::endl;
                    std::cout << "Customer Type: " << customerType << std::endl;
                    std::cout << "Distance: " << distance << std::endl;
                    std::cout << "Max Orders: " << maxOrders << std::endl;
                    ///////////////////////////////////////////////////////////////
                    //when we do this - add here: AddCustomer(customerName, customerType, distance, maxOrders);
                    ///////////////////////////////////////////////////////////////////////////////
                } 
                else {
                std::cerr << "Error parsing customer details." << std::endl;
                }
                

        } 
        else if (firstWord == "volunteer") {
                std::cout << "Yes, the first word is 'volunteer'" << std::endl;
                // BaseAction.AddVolunteer(string volunteerName, string volunteerRole, int coolDown, int maxDistance, int distancePerStep, int maxOrders);
            } 
            else {
                std::cout << "Not recognized word" << std::endl;
            }
        
        }
        else {
            // Handle the case where the string is empty
            std::cerr << "The input string is empty." << std::endl;
        }
    }

    file.close();

    return 0;
}
