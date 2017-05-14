// Validates a ticket number like so:
//
// 47715497443 → {4771549744}{3} → ({4771549744} % 7) == {3} → VALID

// Works by keeping a running sum of just the remainder (of 7)  when reading each char

#include <stdio.h>

int main() {
  char ch; //char is the ticket number
  int digit; // digit represents the last digit in ticket number
  int dividend;
  int remainder = 0; // remainder is the remainder of (sum of all but last digit) % 7
  printf("Enter ticket number: ");
  //Read input, convert char to numerical value (char - '0') to go from ASCII to decimal, exploiting consecutive nature of ASCII for numerals.
  while ((ch = getchar()) != '\n') {
    digit = ch - '0'; // equivalent to ch - 48 (0 is 48 in ASCII)
    dividend = (remainder * 10) + digit;
    remainder = (dividend >= 7) ?  dividend % 7 : dividend;
  }
  // Reverse last remainder calculation, because check digit.
  remainder = (dividend - digit) / 10;
  if (remainder == digit)
    printf("VALID\n");
  else
    printf("INVALID\n");
  return 0;
}
