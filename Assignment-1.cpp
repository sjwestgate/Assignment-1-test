
// Program to calculate transition energy using simple Bohr formula

#include <iostream>

void energy_calculation(int Z, int n_i, int n_j) {
  double energy = 13.6 * Z * Z * (1.0 / (n_j * n_j) - 1.0 / (n_i * n_i));
  std::cout << "The transition energy is: " << energy << " eV" << std::endl;
}

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
  std::cout << "Calculating transition energy..." << std::endl;
  energy_calculation(Z, n_i, n_j);
  return 0;
}

