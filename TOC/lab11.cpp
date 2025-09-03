// LAB11. TM for L={a^n b^n | n>=1}

#include <iostream>
#include <string>
using namespace std;

enum S { ST, FB, GL, ACC, REJ };

class TM {
    string t;  // tape
    int h;     // head
    S s;       // state
public:
    TM(string w): t(w+"B"), h(0), s(ST) {}
    void run(){
        while(s!=ACC && s!=REJ){
            switch(s){
                case ST:
                    if(t[h]=='a'){ t[h]='X'; h++; s=FB; }
                    else if(t[h]=='X'||t[h]=='Y') h++;
                    else if(t[h]=='B') s=ACC;
                    else s=REJ;
                    break;
                case FB:
                    if(t[h]=='a'||t[h]=='X') h++;
                    else if(t[h]=='b'){ t[h]='Y'; h--; s=GL; }
                    else if(t[h]=='Y') h++;
                    else s=REJ;
                    break;
                case GL:
                    if(h>0 && (t[h]=='a'||t[h]=='X'||t[h]=='Y')) h--;
                    else { h++; s=ST; }
                    break;
                default: s=REJ;
            }
        }
        cout<<(s==ACC?"Accepted\n":"Rejected\n");
    }
};

int main(){
    string w;
    cout<<"Enter: ";
    cin>>w;
    TM(w).run();
}
