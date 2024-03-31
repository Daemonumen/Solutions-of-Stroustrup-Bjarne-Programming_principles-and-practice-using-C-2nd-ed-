/* Chaptere 5: exercise 9
 *
 * Modify the program from exercise 8 to write an error if the result cannot be
 * represented as an int.
 */

/*  COMMENT:
 * i cheated again with the numeric limits ..miaw... i have no excuse this time
 */
#include "std_lib_facilities.h"

class Bad_input
{
};
class Not_enough
{
};
class No_int
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
                    // Check if adding num would overflow
                    if (num > 0 && sum > std::numeric_limits<int>::max() - num)
                    {
                        throw No_int{};
                    }
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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        catch(No_int)
        {
            cerr << "the sum can't be represented in a int type " << '\n';
        }
    }
    return 0;
}