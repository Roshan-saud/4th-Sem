// LAB8. NFA to check if string starts with "10" over {0,1}

#include <iostream>
#include <vector>
using namespace std;

// states: 0=start, 2=accept
vector<int> q = {0,1,2};

// transitions: (input, next_state)
vector<vector<pair<char,int>>> tr = {
    {{'1',1}},
    {{'0',2}},
    {{'0',2},{'1',2}}
};

// simulate NFA
bool f(string w){
    vector<int> cs = {0}; // current states
    for(char x:w){
        vector<int> ns;   // next states
        for(int s:cs)
            for(auto p:tr[s])
                if(p.first==x) ns.push_back(p.second);
        if(ns.empty()) return false;
        cs = ns;
    }
    for(int s:cs) if(s==2) return true;
    return false;
}

int main(){
    string w;
    cout<<"Enter: ";
    cin>>w;
    if(f(w)) cout<<"Starts with 10\n";
    else cout<<"Does not start with 10\n";
}
