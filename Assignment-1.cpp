
// Program to calculate transition energy using simple Bohr formula

#include <iostream>
#include <string>
#include <cctype>

void energy_calculation(int Z, int n_i, int n_j) {
  double energy = 13.6 * Z * Z * (1.0 / (n_j * n_j) - 1.0 / (n_i * n_i));
  std::cout << "The transition energy is: " << energy << " eV" << std::endl;
}

int valid_input(){
  std::string input;
  while(true) {
    std::cin >> input;
    bool is_valid = true;
    for(char c : input) {
      if(!isdigit(c)) {
        std::cout << "Invalid input! Please enter a positive integer: ";
        is_valid = false;
        break;
      }
    }
    if(is_valid) {
       try {
        int value = std::stoi(input);
        if (value > 0) {
            return value;
        } else {
            std::cout << "Invalid input! Please enter a positive integer: ";
        }
    } catch (const std::exception&) {
        // fall through to error message
        std::cout << "Out of range, sorry! Please enter a smaller positive integer: ";
    }

    }
    }

}


int main() {
  std::string again;
  again = "y";
  std::cout << "Welcome to the transition energy calculator!" << std::endl;
  while(again == "y") {
    int Z;
    std::cout << "Please enter a positive integer value for Z: "; // Type a number and press enter
    Z = valid_input();

    std::cout << "Your number is: " << Z << std::endl;

    int n_i, n_j;
    std::cout << "Please enter two positive integer values for n_i and n_j (n_i > n_j): ";
    n_i = valid_input();
    n_j = valid_input();
    while(n_i <= n_j) {
      std::cout << "Invalid input! Please ensure n_i > n_j. Enter n_i and n_j again: ";
      n_i = valid_input();
      n_j = valid_input();
    }
    std::cout << "Your numbers are: n_i = " << n_i << ", n_j = " << n_j << std::endl;

    std::cout << "Would you like the transition energy in eV or Joules? (Enter 'eV' or 'J'): ";
    std::string unit;
    while(true) {
      std::cin >> unit;
      if(unit == "eV" || unit == "J") {
        break;
      } else {
        std::cout << "Invalid input! Please enter 'eV' or 'J': ";
      }
    }

    std::cout << "Calculating transition energy..." << std::endl;
    if(unit == "eV") {
      energy_calculation(Z, n_i, n_j);
    } else {
      double energy_eV = 13.6 * Z * Z * (1.0 / (n_j * n_j) - 1.0 / (n_i * n_i));
      double energy_J = energy_eV * 1.60218e-19; // Convert eV to Joules
      std::cout << "The transition energy is: " << energy_J << " J" << std::endl;
    }
    std::cout << "Thank you for using the transition energy calculator. Would you like another go? (y/n): ";
    while(true) {
      std::cin >> again;
      if(again == "y" || again == "n") {
        break;
      } else {
        std::cout << "Invalid input! Please enter 'y' or 'n': ";
      }
    }
}
std::cout << "Goodbye!" << std::endl;
return 0;
}

