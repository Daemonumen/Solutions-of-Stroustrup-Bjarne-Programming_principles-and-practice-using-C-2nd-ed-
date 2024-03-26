#include "std_lib_facilities.h"
using namespace std;

int main()
{
    
    vector <int> scores ;
    vector <string> names;
    for(string name ; cin >> name;)
    {
        int score;
        cin >> score;
        if(name == "NoName" && score == 0)
        {
            break;
        }
        int in = 0;
        for(int i = 0 ; i < names.size(); ++i)
        {
            if(name == names[i])
            {
                in = 1;
                break;
            }
        }
        if(in)
        {
            cerr << "this name is already in here ... bye bye" << endl;
            break;
        }
        else{
            names.push_back(name);
            scores.push_back(score);
        }
    }
    for (int i = 0 ; i < names.size() ; ++i)
    {
        cout << names[i] <<   " " << scores[i] << endl;
    }
    for(string name ; cin >> name;)
    {
        int score ,in = 0;
        
        for(int i = 0 ;   i< names.size() ; i++)
        {
            if(names[i] == name)
            {
                in = 1;
                score = scores[i];
            }
        }
        if(in)
        {
            cout << name << " " << score << endl;
        }
        else {
            cerr << "no name found \n" ;
        }
    }
    for (int score ; cin >> score;)
    {
        int in = 0;
        vector <string> foundplayers; 
        for(int i = 0 ; i < scores.size() ;++i)
        {
            if(score == scores[i])
            {
                foundplayers.push_back(names[i]);
                in = 1;
            }
        }
        if(in)
        {
            cout << "the names with the score "<< score << "are:"<<endl;
            for(string player : foundplayers)
            {
                cout << player <<endl;
            }
        }
        else{
            cerr << "score not found "<<endl;
        }
    }
    
}
