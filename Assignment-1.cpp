
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
        }
    } catch (const std::exception&) {
        // fall through to error message
    }

    }
    }

}


int main() {
  int Z;
  std::cout << "Please enter an integer value for Z: "; // Type a number and press enter
  Z = valid_input();

  std::cout << "Your number is: " << Z << std::endl;

  int n_i, n_j;
  std::cout << "Please enter two positive integer values for n_i and n_j (n_i > n_j): "; // Type two numbers and press enter
  while(!(std::cin >> n_i >> n_j) || n_i <= 0 || n_j <= 0 || n_i <= n_j) {
    std::cin.clear(); // Reset input errors
    std::cin.ignore(10000, '\n'); // Remove bad input
    std::cout << "Invalid input! Please enter two positive integer values for n_i and n_j (n_i > n_j): ";
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
  return 0;
}

