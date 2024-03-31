// 5.exercise.05.cpp
// 
// Add to the program so that it can also convert from Kelvin to Celsius.
#include "std_lib_facilities.h"

class Bad_input
{
};
class Below_zero
{
}; // classes specifically defined for errors handling

double ctok(double c)
{
    if (c < -273.15)
        throw Below_zero{};
    double k = c + 273.15;
    return k;
}
double ktoc(double k)
{
    if (k < 0)
        throw Below_zero{};
    double c = k - 273.15;
    return c;
}
int main()
{
    try
    {
        double value = 0;
        char tempera = ' ';
        cout << "Insert a temperature in Celsius or Kelvin to convert.\n"
             << "(Magnitude and unit separated by an space; e.g. 10 c or 100 k)\n"
             << ": ";
        cin >> value >> tempera;
        if (cin)
        {
            switch (tempera)
            {
            case 'k':
                cout << ktoc(value) << " c" << endl;
                break;
            case 'c':
                cout << ctok(value) << " k" << endl;
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
    catch (Below_zero)
    {
        cerr<<"there is a problem with the temperature inputed...it's not legal"<< '\n';
        return 2;
    }
    catch (Bad_input)
    {
        cerr<< "there is a problem with the input provided ... please try again" << '\n';
        return 3;
    }
}