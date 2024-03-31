

/* Chapter 5: exercise 8  
 *
 *  Write a program that reads and stores a series of integers and then computes
 *  the sum of the first N integers. First ask for N, then read the values into
 *  a vector, then calculate the sum of the first N values. For example:
 *
 *  "Please enter the number of values you want to sum:"
 *
 *      3
 *
 *  "Please enter some integers (press '|' to stop):"
 *
 *      12 23 13 24 15 |
 *
 *  "The sum of the first 3 numbers ( 12 23 13 ) is 48."
 *
 *  Handle all inputs. For example, make sure to give an error message if the
 *  user asks for a sum of more numbers than there are in the vector.
 */

/*  COMMENT:
 * i cheated and used cin.clear and cin.ignore but its not really that important i just wanted to try it with a loop
 * u can just use it directly and get rid of the loop so u dont have to use them...
 * 
 * and rather than reading the whole vector i read only up to the last of number of sum ... 
 * since its more efficient ?
*/
#include "std_lib_facilities.h"

class Bad_input
{
};
class Not_enough
{
};
int main()
{
    int yes = 1;
    while (yes)
    {
        try

        {
            int numofsum = 0;
            cout << "Please enter the number of values you want to sum:";
            cin >> numofsum;
            if (cin)
            {
                cout << "Please enter some integers (press '|' to stop): ";
                vector<int> nums;
                for (int num; cin >> num;)
                {
                    nums.push_back(num);
                    if (nums.size() == numofsum)
                    {
                        break;
                    }
                }
                if (nums.size() < numofsum)
                {
                    throw Not_enough{};
                }
                int sum = 0;
                for (int num : nums)
                {
                    sum += num;
                }
                cout << "the sum of the first " << numofsum << " numbers is " << sum << endl;
            }
            else
            {
                throw Bad_input{};
            }
            cout << "would u like to continue or get out "
                 << "enter 0 to get out and any other number to continue: ";

            while (1)
            {
                cin >> yes;
                if (cin)
                {
                    break;
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max() , '\n');
                cout << "please enter a number";
            }
        }
        catch (Bad_input)
        {
            cerr << "Check your input and try again" << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (Not_enough)
        {
            cerr << "You didn't enter enough numbers in the array for the sum" << '\n';
        }
    }
    return 0;
}