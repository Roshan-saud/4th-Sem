//Lab5. C++ program for DFA for the language of string over {0,1} in which each string ends with 11

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;     // string to be checked
    int state = 0;  // initial state (q0)

    cout << "Enter the string: ";
    cin >> str;

    // loop to check each character of the string for the DFA
    for (int i = 0; i < str.length(); i++)
    {
        // check if the string is over {0,1} or not
        if (str[i] != '0' && str[i] != '1')
        {
            cout << "String not accepted.\nPlease enter a string over {0,1}" << endl;
            return 0;
        }

        // DFA transitions
        if (state == 0 && str[i] == '0')
            state = 0;
        else if (state == 0 && str[i] == '1')
            state = 1;
        else if (state == 1 && str[i] == '0')
            state = 0;
        else if (state == 1 && str[i] == '1')
            state = 2;
        else if (state == 2 && str[i] == '0')
            state = 0;
        else if (state == 2 && str[i] == '1')
            state = 2;   // ✅ stay in state 2
    }

    // check if the string ends with "11" (state 2)
    if (state == 2)
        cout << "String accepted\n";
    else
        cout << "String not accepted\n";

    return 0;
}
