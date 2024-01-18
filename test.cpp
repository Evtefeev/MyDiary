#include <iostream>
#include <string>

int main() {
    char t;
    std::cin >> t; 
    std::string userInput;

    // Prompt the user to enter a line
    std::cout << "Enter a line: ";

    // Read a line from the console
    std::getline(std::cin, userInput);

    // Display the entered line
    std::cout << "You entered: " << userInput << std::endl;

    return 0;
}
