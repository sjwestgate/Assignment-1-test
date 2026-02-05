
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

  int n_i, n_j;
  std::cout << "Please enter two positive integer values for n_i and n_j (n_i > n_j): "; // Type two numbers and press enter
  while(!(std::cin >> n_i >> n_j) || n_i <= 0 || n_j <= 0 || n_i <= n_j) {
    std::cin.clear(); // Reset input errors
    std::cin.ignore(10000, '\n'); // Remove bad input
    std::cout << "Invalid input! Please enter two positive integer values for n_i and n_j (n_i > n_j): ";
  }
  std::cout << "Your numbers are: n_i = " << n_i << ", n_j = " << n_j << std::endl;
  return 0;
}

