// 2. The following program takes in a temperature value in Celsius and converts it to Kelvin.
// This code has many errors in it. Find the errors, list
// them, and correct the code.

// double ctok(double c) // converts Celsius to Kelvin
// {
//  int k = c + 273.15;
//  return int
// }
// int main()
// {
//  double c = 0; // declare input variable
//  cin >> d; // retrieve temperature to input variable
//  double k = ctok("c"); // convert temperature
//  Cout << k << '/n' ; // print out temperature
// }

#include "std_lib_facilities.h"

double ctok(double c)
{
    double k = c + 273.15; // ctok is supposed to return double not int ... so to avoid implicit type conversion we use double instead
    return k;              // rather than returning int which is no double ... we return the varible intended
}
int main()
{
    double c = 0;         // okay,initialising our variable before reading input
    cin >> c;             // there exists no definition nor declaration of d
    double k = ctok(c); // the function ctok expects a double not a string... we coulve used a char here // ctok('c') since there is a legal conversion between them but there exists none for a string
    cout << k << '\n';    // cout rather than Cout ... and '\n' rather than '/n' which leads to the problem of printing some number after the actual kelvin
    // when you use single quotes around multiple characters, it’s actually an integer type called a multi-character constant. The compiler will translate the characters into their corresponding ASCII values and then pack them into an integer.
}
// notice how we uncouter no problem regarding the declaration of two k in this program the secret is the scope differs ...