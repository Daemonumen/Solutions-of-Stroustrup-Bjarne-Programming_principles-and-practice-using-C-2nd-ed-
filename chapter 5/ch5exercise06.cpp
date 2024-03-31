// 6. Write a program that converts from Celsius to Fahrenheit and from Fahrenheit to Celsius 
//(formula in §4.3.3). Use estimation (§5.8) to see if your 
// results are plausible.
#include "std_lib_facilities.h"

class Bad_input
{
};
// classe specifically defined for errors handling

double ctof(double c)
{
    double f = 9.0/5.0*c + 32;
    return f;
}
double ftoc(double f)
{
    double c = (f - 32) *5.0/9.0;
    return c;
}
int main()
{
    try
    {
        double value = 0;
        char tempera = ' ';
        cout << "Insert a temperature in Celsius or Kelvin to convert.\n"
             << "(Magnitude and unit separated by an space; e.g. 10 f or 100 f)\n"
             << ": ";
        cin >> value >> tempera;
        if (cin)
        {
            switch (tempera)
            {
            case 'f':
                cout << ftoc(value) << " c" << endl;
                break;
            case 'c':
                cout << ctof(value) << " f" << endl;
                break;
            default:
                error("we may not be able to handle that kind of temperature measure");
                break;
            }
        }
        else
        {
            throw Bad_input{};
        }
        return 0;
    }
    catch (runtime_error &e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch (Bad_input)
    {
        cerr<< "there is a problem with the input provided ... please try again" << '\n';
        return 2;
    }
}