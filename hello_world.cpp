#include <iostream>
#include <string>

// Main function
int main() {
    // Name variable
    std::string name;
    
    // Name request
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Output
    std::cout << "Hello world from " << name << std::endl;
    
    return 0; // End of program
}
