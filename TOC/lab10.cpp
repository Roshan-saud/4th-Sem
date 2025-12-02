// LAB10. PDA for L={a^n b^n : n>=1}

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// simulate PDA
bool f(string w){
    stack<char> st;
    for(char x:w){
        if(x=='a') st.push('a');        // push 'a'
        else if(x=='b'){                // pop 'a'
            if(st.empty()) return false;
            st.pop();
        }
        else return false;              // invalid char
    }
    return st.empty();                  // accept if stack empty
}

int main(){
    string w;
    cout<<"Enter: ";
    cin>>w;
    if(f(w)) cout<<"Accepted\n";
    else cout<<"Rejected\n";
}





// #include <iostream>
// #include <stack>
// using namespace std;

// bool f(const string &w) {
//     stack<char> st;
//     bool seenB = false;

//     for (char x : w) {
//         if (x == 'a') {
//             if (seenB) return false; // 'a' after 'b' not allowed
//             st.push('a');
//         } 
//         else if (x == 'b') {
//             seenB = true;
//             if (st.empty()) return false;
//             st.pop();
//         } 
//         else return false; // invalid character
//     }

//     return !st.empty() ? false : true; // accept if stack empty
// }

// int main() {
//     string w;
//     cout<<"Enter string: ";
//     cin >> w;
//     cout << (f(w) ? "Accepted\n" : "Rejected\n");
// }
