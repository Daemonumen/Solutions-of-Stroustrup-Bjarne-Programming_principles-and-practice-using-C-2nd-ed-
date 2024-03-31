/*
    13. The program is a bit tedious because the answer is hard-coded into the
    program. Make a version where the user can play repeatedly (without
    stopping and restarting the program) and each game has a new set of
    four digits. You can get four random digits by calling the random number
    generator randint(10) from std_lib_facilities.h four times. You will note
    that if you run that program repeatedly, it will pick the same sequence
    of four digits each time you start the program. To avoid that, ask the
    user to enter a number (any number) and call seed_randint(n), also from
    std_lib_ facilities.h, where n is the number the user entered before calling
    randint(10). Such an n is called a seed, and different seeds give different
    sequences of random numbers.
 *
 *
 *

*/

#include "std_lib_facilities.h"
class invalid_number
{
};
class invalid_input
{
};
constexpr int sizeofguess = 4;
int main()
{

    cout << "Enter a number to seed :" ;
    int idkn = 0;
    while(1)
    {
            cin >> idkn ;
            if(cin)
            {
                break;
            } 
            cout << "please enter a number" << endl;
    }

    
    srand(idkn);
    cout << "\t\t\t\t\t\t\t\t\twelcome to the game of bulls and cows ..." << '\n'
         << "\t\tcan you finnally be our hero and try to guess our really reaaaallyyy difficult number \"its not 1234\" cuz that would be too easy \n";

    while (true)
    {

        vector<int> number;
        for (int i = 0; number.size() != sizeofguess; i++)
        {
            int randnum = rand() % 10;
            int oui = 1;
            for (int num : number)
            {
                if (num == randnum)
                {
                    oui = 0;
                    break;
                }
            }
            if (oui)
            {
                number.push_back(randnum);
            }
        }
        int bull = 0, cow{};
        while (bull != sizeofguess) // if user didn't guess the whole number continue
        {
            try
            {

                cout << "\t\t\t\t\t\t\t\t\t\tEnter the sequence of " << sizeofguess << " numbers " << endl;

                bull = 0, cow = 0;
                vector<int> guess;
                for (int i = 0; i < sizeofguess; ++i)
                {
                    int num;
                    cin >> num;
                    if (!cin)
                    {
                        throw invalid_input{};
                    }
                    if (num < 0 || num > 9)
                    {
                        throw invalid_number{};
                    }
                    guess.push_back(num);
                }
                // every number on guess is either a cow or a bull or nothing at all ... how can it be nothing  ? well ..
                //  In “Bulls and Cows,” each digit in the guess is compared to the corresponding digit in the secret number for bulls, and then for cows, but only if it wasn’t already counted as a bull.
                // Also, each digit in the secret number can only be matched once. So, even though you guessed three additional 1s, they don’t match any new positions in the secret number.
            vector<int> bulled (sizeofguess , 0);
            vector <int> cowedinnumber(sizeofguess, 0); //already bulled or cowed numbers
            for (int i = 0; i < sizeofguess; i++)// get the bulls first 
            {
                if (guess[i] == number[i])
                {
                    bull++;
                    bulled[i]++;
                }
            }
            for (int i = 0; i < sizeofguess; i++)
            {
                if (!bulled[i])//if the current indx wasnt guesses already by bull or cowed
                {
                    for (int j = 0; j < sizeofguess; j++)
                    {
                        if (i != j && !cowedinnumber[j] && number[j] == guess[i] && !bulled[j])
                        {
                            cow++;
                            cowedinnumber[j]++;
                        }
                    }
                }
            }
                cout << "\t\t\t\t\t\t\t\t\t\t";
                if (bull == 1 && cow == 1)
                {
                    cout << bull << " bull " << cow << " cow" << endl;
                }
                else if (bull == 1)
                {
                    cout << bull << " bull " << cow << " cows" << endl;
                }
                else if (cow == 1)
                {
                    cout << bull << " bulls " << cow << " cow" << endl;
                }
                else
                {
                    cout << bull << " bulls " << cow << " cows" << endl;
                }
            }

            catch (invalid_input)
            {
                cerr << "this is invalid input please enter a sequence of " << sizeofguess << " numbers \n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            catch (invalid_number)
            {
                cerr << "the number has to be between 0 and 9 included... \" maybe u forgot the whitespace between the numbers \" \n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            catch (runtime_error &err)
            {
                cerr << err.what() << '\n';
            }
        }
        cout << "ugh ... u won this time ... how did u even guess the number.. u wont be so lucky next time " << endl
             << "\t\t\t\t\t\tup for another round ? \"Y or N\"";
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
        int quit = 0;
        switch (toupper(qui))
        {
        case 'N':
            cout << "\t\t\t\t\t\t\t\t\t\t\tokay byee loser" << endl;
            quit++;
            break;
        case 'Y':
            cout << "\t\t\t\t\t\t\t\t\t\t\tso u challenge me... okay " << endl;
            break;
        default:
            throw runtime_error("there is a problem in Y or N part");
            break;
        }
        if (quit)
        {
            break;
        }
    }
    return 0;
}