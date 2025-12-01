//LAB1: Program to find prefixes, suffixes and substrings from a given string (Using C, C++ or else)

#include <iostream>
#include <set>
#include <cstring>
using namespace std;

void prefixes(const char* s, int n) {
    cout << "Prefixes: ε ";
    for (int i = 1; i <= n; i++) cout << string(s, i) << " ";
    cout << endl;
}

void suffixes(const char* s, int n) {
    cout << "Suffixes: ε ";
    for (int i = 0; i < n; i++) cout << (s + i) << " ";
    cout << endl;
}

void substrings(const char* s, int n) {
    cout << "Substrings: ε ";
    set<string> seen;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            string sub = string(s + i, j - i + 1);
            if (seen.insert(sub).second) cout << sub << " ";
        }
    cout << endl;
}

int main() {
    char s[100];
    int ch;

    cout << "Enter a string: ";
    cin >> s;
    int n = strlen(s);

    cout << "1. Prefixes\n2. Suffixes\n3. Substrings\n4. All\nEnter choice: ";
    cin >> ch;

    if (ch == 1 || ch == 4) prefixes(s, n);
    if (ch == 2 || ch == 4) suffixes(s, n);
    if (ch == 3 || ch == 4) substrings(s, n);
    if (ch < 1 || ch > 4) cout << "Invalid choice";

    return 0;
}










// #include <iostream>
// #include <cstring>
// #include <set>
// using namespace std;

// void printPrefixes(const char* str, int l) {
//     cout << "Prefixes: ε ";  // Printing epsilon (empty string)
//     char prefix[100];
//     for (int i = 0; i < l; i++) {
//         for (int j = 0; j <= i; j++) {
//             prefix[j] = str[j];
//         }
//         prefix[i + 1] = '\0';
//         cout << prefix << " ";
//     }
//     cout << endl;
// }

// void printSuffixes(const char* str, int l) {
//     cout << "Suffixes: ε ";  // Printing epsilon (empty string)
//     char suffix[100];
//     for (int k = 0; k < l; k++) {
//         for (int m = k; m < l; m++) {
//             suffix[m - k] = str[m];
//         }
//         suffix[l - k] = '\0';
//         cout << suffix << " ";
//     }
//     cout << endl;
// }

// void printSubstrings(const char* str, int l) {
//     cout << "Substrings: ε ";  // Printing epsilon (empty string)
//     set<string> unique_substrings; // Use a set to keep track of unique substrings
//     for (int n = 0; n < l; n++) {
//         for (int o = n; o < l; o++) {
//             string sub = string(str).substr(n, o - n + 1); // (start, length) of substring
//             if (unique_substrings.find(sub) == unique_substrings.end()) {
//                 unique_substrings.insert(sub);
//                 cout << sub << " ";
//             }
//         }
//     }
//     cout << endl;
// }

// int main() {
//     char str[100];
//     int choice;
    
//     cout << "Enter a string: ";
//     cin >> str;
//     int l = strlen(str);

//     cout << "Choose an option:" << endl;
//     cout << "1. Print Prefixes" << endl;
//     cout << "2. Print Suffixes" << endl;
//     cout << "3. Print Substrings" << endl;
//     cout << "4. Print all" << endl;
//     cout << "Enter your choice: ";
//     cin >> choice;

//     switch (choice) {
//         case 1:
//             printPrefixes(str, l);
//             break;
//         case 2:
//             printSuffixes(str, l);
//             break;
//         case 3:
//             printSubstrings(str, l);
//             break;
//         case 4:
//             printPrefixes(str, l);
//             printSuffixes(str, l);
//             printSubstrings(str, l);
//             break;
//         default:
//             cout << "Invalid choice" << endl;
//     }

//     return 0;
// }


// abc