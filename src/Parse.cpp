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
        //std::cout << "Read line: " << line << std::endl;
        std::istringstream iss(line);
        std::string firstWord;
            if (iss >> firstWord) {
        // firstWord now contains the first word of the inputString
        std::cout << "First word: " << firstWord << std::endl;
    } 
    else {
        // Handle the case where the string is empty
        std::cerr << "The input string is empty." << std::endl;
    }
    }

    file.close();

    return 0;
}
