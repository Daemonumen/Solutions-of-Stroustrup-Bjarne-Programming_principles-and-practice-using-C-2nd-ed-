// 14. Read (day-of-the-week,value) pairs from standard input. For example:
// Tuesday 23 Friday 56 Tuesday –3 Thursday 99
//  Collect all the values for each day of the week in a vector<int>. Write out
// the values of the seven day-of-the-week vectors. Print out the sum of the
// values in each vector. Ignore illegal days of the week, such as Funday,
// but accept common synonyms such as Mon and monday. Write out the
// number of rejected values.

#include "std_lib_facilities.h"
class Invalid_input
{
};

constexpr int abreviation_size = 3;

int leavel()
{
    cout << "\t\t\t\t\t\tquit ? \"Y or N\"";
    char qui;
    while (1)
    {
        cin >> qui;
        if (cin && (toupper(qui) == 'Y' || toupper(qui) == 'N'))
        {

            break;
        }
        cerr << "\t\t\t\t\t\t\tplease enter a char ... Y or N" << endl;
    }
    switch (toupper(qui))
    {
    case 'Y':
        cout << "\t\t\t\t\t\t\t\t\t\t\tsee you again" << endl;
        return 1;
        break;
    case 'N':
        return 0;
        break;
    default:
        throw runtime_error("there is a problem in Y or N part");
        break;
    }
}
int main(void)
{
    const vector<string> abreviation{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};// we can just content ourselves with the abreviation 
    int quit = 0;
    vector<vector<int>> weekscores(7);
    int wrongcount = 0;
    while (!quit)
    {
        try
        {
            cout << "Enter weekday and score... or just an abreviation... and please a space between them " << endl;
            string weekday{};
            int weekscore;
            cin >> weekday;
            if (!cin)
            {
                throw Invalid_input{};
            }

            cin >> weekscore;
            if (!cin)
            {
                throw Invalid_input{};
            }

            int exist = 0, existi;
            for (int i = 0; i < abreviation.size(); i++)
            {
                int notit = 1;
                for (int j = 0; j < abreviation_size; j++)
                {
                    if (toupper(weekday[j]) != abreviation[i][j])
                    {
                        notit = 0;
                    }
                }
                if (notit)
                {
                    exist = 1;
                    existi = i;
                    break;
                }
            }
            if (!exist)
            {
                wrongcount++;
                quit = leavel();
                continue;
            }
            weekscores[existi].push_back(weekscore);
            quit = leavel();
        }
        catch (Invalid_input)
        {
            cerr << "wrong type of input or smth ... try again" << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (runtime_error &err)
        {
            cerr << "exeption :" << err.what() << '\n';
        }
    }
    cout << "the number of invalid weekday is " << wrongcount << endl;
    for (int i = 0; i < abreviation.size(); i++)
    {
        cout << "the values for the " << abreviation[i] << endl;
        int sumscowee = 0;
        for (int j = 0; j < weekscores[i].size(); j++)
        {
            cout << weekscores[i][j] << endl;
            sumscowee += weekscores[i][j];
        }
        cout << "and the sum of its values is " << sumscowee << endl;
    }
    return 0;
}
