// 12. Implement a little guessing game called (for some obscure reason) “Bulls
// and Cows.” The program has a vector of four different integers in the
// range 0 to 9 (e.g., 1234 but not 1122) and it is the user’s task to discover
// those numbers by repeated guesses. Say the number to be guessed is 1234
// and the user guesses 1359; the response should be “1 bull and 1 cow”
// because the user got one digit (1) right and in the right position (a bull)
// and one digit (3) right but in the wrong position (a cow). The guessing
// continues until the user gets four bulls, that is, has the four digits correct
// and in the correct order.
//
//


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

    vector<int> number{1, 2, 3, 4};
    cout << "\t\t\t\t\t\t\t\t\twelcome to the game of bulls and cows ..." << '\n'
         << "\t\tcan you finnally be our hero and try to guess our really reaaaallyyy difficult number \"its not 1234\" cuz that would be too easy \n";
    int bull = 0, cow{};
    while (bull != sizeofguess) //if user didn't guess the whole number continue
    {
        try
        {
            cout <<  "\t\t\t\t\t\t\t\t\t\tEnter the sequence of "<< sizeofguess<<" numbers " << endl;

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
            //every number on guess is either a cow or a bull or nothing at all ... how can it be nothing  ? well .. 
            // In “Bulls and Cows,” each digit in the guess is compared to the corresponding digit in the secret number for bulls, and then for cows, but only if it wasn’t already counted as a bull. 
            //Also, each digit in the secret number can only be matched once. So, even though you guessed three additional 1s, they don’t match any new positions in the secret number.
            vector<int> bulledorcowed(sizeofguess, 0); //already bulled or cowed numbers
            for (int i = 0; i < sizeofguess; i++)// get the bulls first 
            {
                if (guess[i] == number[i])
                {
                    bull++;
                    bulledorcowed[i]++;
                }
            }
            for (int i = 0; i < sizeofguess; i++)
            {
                if (!bulledorcowed[i])//if the current indx wasnt guesses already by bull or cowed
                {
                    for (int j = 0; j < sizeofguess; j++)
                    {
                        if (i != j && !bulledorcowed[j] && number[j] == guess[i])
                        {
                            cow++;
                            bulledorcowed[j]++;
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
            cout << "\t\t\t\t\t\t\tdo u want to give up or not yet ... ik its difficult ... muaahahahhahahaha" << endl
                 << "\t\t\t\t\t\t\t\t\tjust enter q to quit and c to continue :"<<endl;
            char qui; 
            while(1)
            {
                cin >> qui ;
                if(cin && (toupper(qui) == 'Q' || toupper(qui) == 'C') )
                {
                    
                    break;
                } 
                cerr << "\t\t\t\t\t\t\tplease enter a char ... q or c"<< endl;
            }
            int quit = 0;
            switch (toupper(qui))
            {
                case 'Q':
                    cout << "\t\t\t\t\t\t\t\t\t\t\tokay byee loser" << endl;
                    quit++;
                    break;
                case 'C':
                    cout << "\t\t\t\t\t\t\t\t\t\t\tso u challenge me... okay " <<endl;
                    break;
                default:
                    throw runtime_error("there is a problem in c or q part");
                    break;
            }
        }
        catch (invalid_input)
        {
            cerr << "this is invalid input please enter a sequence of "<< sizeofguess << " numbers \n";
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
    cout << "ugh ... u won this time ... how did u even guess the number.. u are a monster " << endl;
    return 0;
}