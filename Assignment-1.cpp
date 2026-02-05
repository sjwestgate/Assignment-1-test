
// Program to calculate transition energy using simple Bohr formula

#include <iostream>

int main() {
  int Z;
  std::cout << "Please enter an integer value for Z: "; // Type a number and press enter
  while(!(std::cin >> Z) || Z <= 0) {
    std::cin.clear(); // Reset input errors
    std::cin.ignore(10000, '\n'); // Remove bad input
    std::cout << "That's not a positive integer! Please enter a positive integer value for Z: ";
  }

  std::cout << "Your number is: " << Z << std::endl;
  return 0;
}

