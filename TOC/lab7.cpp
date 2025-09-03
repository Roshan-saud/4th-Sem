// LAB7. NFA to check if string contains substring "101" over {0,1}

#include <iostream>
#include <vector>
using namespace std;

// states: 0=start, 3=accept
vector<int> q = {0,1,2,3};

// transitions: (input, next_state)
vector<vector<pair<char,int>>> tr = {
    {{'0',0},{'1',0},{'1',1}},
    {{'0',2}},
    {{'1',3}},
    {{'0',3},{'1',3}}
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
    for(int s:cs) if(s==3) return true;
    return false;
}

int main(){
    string w;
    cout<<"Enter: ";
    cin>>w;
    if(f(w)) cout<<"Contains 101\n";
    else cout<<"Does not contain 101\n";
}
