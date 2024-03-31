// 5.exercise.07.cpp
//
// Quadratic equations are of the form
//
//      a·x² + b·x + c = 0
//
// To solve these, one uses the quadratic formula:
//
//      x = (-b ± sqrt(b² - 4ac)) / 2a
//
// There is a problem, though: if b² - 4ac is less than zero, then it will
// fail. Write a program that calculate x for a quadratic equation. Create
// a function that prints out the roots of a quadratic equation, given a, b, c.
// When the program detects an equation with no real roots, have it print out
// a message. How do you know that your results are plausible? Can you check
// that they are correct?
// yes we can do post-condition that checks if the solution does indeed provide 0 with the coeffecient ... 
//ofc we shouldnt forget that there is no such thing as a zero double or float ...

#include "std_lib_facilities.h"
constexpr double smallnum = 1e-13; // since floats are never really equal to zero ... and for us to have only one solution delta has to be 0 thus ...+
class Bad_input{};
class Need_c{};
int getx (double d , int sign , double a , double b )
{
    if(d < -smallnum)
    {
        throw Need_c{};
    }
    return (-b+sign*d)/(2*a);

}
int main ()
{
    try
    {
        double a , b , c ;
        cout << "Enter a b c for the quadtratic formula in that order while leaving a whitespace between the numbers provided "
             << "if u wish to not use one just type 0"
             << endl;
        cin >> a >> b >> c ;
        if(cin)
        {
            double delta = b*b-4*a*c;

            if (delta > smallnum){  // delta is not zero basically
                double x1 = getx (delta , 1 , a , b);
                double x2 = getx  (delta , -1 , a, b);
                cout << "solutions : " << x1 << ' ' << x2 ;
           }
           else if (delta < smallnum && delta > -smallnum)
           {

                double x = getx (delta , 1 , a ,b);
                cout <<"solution : " << x << endl;
           }

           
        }
        else{
            throw Bad_input{};
        }
        return 0;
    }
    catch(runtime_error& e)
    {
        cerr << e.what() << '\n';
        return 1;
    }
    catch(Bad_input)
    {
        cerr << "check your input and try again" << '\n';
        return 2;
    }
    catch(Need_c)
    {
        cerr << "we may need imaginary numbers to find the answer which is out of the scope of this program.. "<< '\n';
        return 3;
    }
    
}