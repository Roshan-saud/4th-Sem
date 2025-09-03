// LAB9. C++ code that generates strings representing properly balanced parentheses using a context-free grammar:
#include <iostream>
#include <string>

using namespace std;

// Function to generate strings representing properly balanced parentheses
void gBP(string pr, int oC, int cC, int n) {
    // Base case: if oC->openCount  and cC->closeCount reach n (both are balanced)
    // pr: prefix
    if (oC == n && cC == n) {
        cout << pr << endl;
        return;
    }

    // Recursive case: if openCount < n, add an open parenthesis
    if (oC < n) {
        gBP(pr + "(", oC + 1, cC, n);
    }

    // Recursive case: if closeCount < openCount, add a close parenthesis
    if (cC < oC) {
        gBP(pr + ")", oC, cC + 1, n);
    }
}

int main() {
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    cout << "Properly balanced parentheses of size " << n << ":" << endl;
    gBP("", 0, 0, n);

    return 0;
}
