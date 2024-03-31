
/*  Chapter 5: exercise 11
 *
 *  Write a program that writes out the first so many values of the Fibonacci
 *  series, that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next
 *  number of the series is the sum of the two previous ones. Fmd the largest
 *  Fibonacci number that fits in an int.
 */

/*  COMMENT:
 *  we can also work with...well since an int is 32 bits (4 bytes) that is 2^31-1 So, -2,147,483,648 to 2,147,483,647
 *  possible values. If sum adds the two previous fibs and that sum becomes negative, we know
 *  we reached an overflow. 
 */

#include "std_lib_facilities.h"

int main()
{
    int num1 = 1 ,num2 = 1;
    while (num2 <= numeric_limits<int>::max() - num1)
    {
        int temp = num2;
        num2 += num1;
        num1 = temp;
    }
    cout << num2<< endl;
}