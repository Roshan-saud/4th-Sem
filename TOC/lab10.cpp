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
