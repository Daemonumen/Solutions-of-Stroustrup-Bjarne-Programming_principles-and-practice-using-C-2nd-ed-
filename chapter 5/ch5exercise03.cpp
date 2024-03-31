// 3. Absolute zero is the lowest temperature that can be reached; it is –273.15°C, 
// or 0K. The above program, even when corrected, will produce erroneous results when given a temperature below this. Place a check in the 
// main program that will produce an error if a temperature is given below 
// –273.15°C.
#include "std_lib_facilities.h"

double ctok(double c)
{
    double k = c + 273.15; 
    return k;              
}
int main()
{
    double c = 0;        
    cin >> c;      
    if(c < -273.15 )    
    {
        error("wrong temperature inputed");
    }  
    double k = ctok(c); 
    cout << k << '\n';

}