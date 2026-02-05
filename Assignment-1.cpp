
// Program to calculate transition energy using simple Bohr formula

#include <iostream>
using namespace std;

int main() {
  int Z;
  cout << "Please enter an integer value for Z: "; // Type a number and press enter
  while(!(cin >> Z) || Z <= 0) {
    cin.clear(); // Reset input errors
    cin.ignore(10000, '\n'); // Remove bad input
    cout << "That's not a positive integer! Please enter a positive integer value for Z: ";
  }

  cout << "Your number is: " << Z << endl;
  return 0;
}

