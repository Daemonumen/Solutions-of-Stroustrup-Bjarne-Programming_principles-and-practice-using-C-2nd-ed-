//4. Do exercise 3 again, but this time handle the error inside ctok()
// 
#include "std_lib_facilities.h"

double ctok(double c)
{
    if(c < -273.15 )    
    {
        error("wrong temperature inputed");
    }  
    double k = c + 273.15; 
    return k;              
}
int main()
{
    double c = 0;        
    cin >> c;      
    double k = ctok(c); 
    cout << k << '\n';

}