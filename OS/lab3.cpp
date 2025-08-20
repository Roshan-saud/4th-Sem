#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void lruPageReplacement(const string &referenceString, int frameSize) {
    vector<char> frames;          // store characters in frames
    vector<int> lastUsed;         // parallel vector to store last used index
    int pageFaults = 0, pageHits = 0;

    cout << "\nStep-by-step Table (LRU Page Replacement):\n";
    cout << "-----------------------------------------------------------------\n";
    cout << setw(10) << "Page"
         << setw(20) << "Frames"
         << setw(15) << "Page Fault"
         << setw(10) << "Hit\n";
    cout << "-----------------------------------------------------------------\n";

    for (int i = 0; i < (int)referenceString.size(); i++) {
        char page = referenceString[i];
        bool found = false;

        // Check if page already in frames
        for (int j = 0; j < (int)frames.size(); j++) {
            if (frames[j] == page) {
                found = true;
                lastUsed[j] = i; // update last used index
                break;
            }
        }

        if (!found) { // Page fault
            if ((int)frames.size() < frameSize) {
                frames.push_back(page);
                lastUsed.push_back(i);
            } else {
                // Find least recently used page
                int lruIndex = 0;
                for (int j = 1; j < frameSize; j++) {
                    if (lastUsed[j] < lastUsed[lruIndex])
                        lruIndex = j;
                }
                frames[lruIndex] = page;
                lastUsed[lruIndex] = i;
            }
            pageFaults++;
        } else {
            pageHits++;
        }

        // Print current step
        cout << setw(10) << page << setw(20);
        for (char f : frames) cout << f << " ";
        cout << setw(15) << (found ? "No" : "Yes")
             << setw(10) << (found ? "Yes" : "No") << "\n";
    }

    cout << "-----------------------------------------------------------------\n";
    cout << "Total Page Faults = " << pageFaults << endl;
    cout << "Total Page Hits   = " << pageHits;
}

int main() {
    int frameSize, refSize;
    string referenceString;
    cout << "Enter reference string size: ";
    cin >> refSize;
    cout << "Enter reference string (length should be " << refSize << "): ";
    cin >> referenceString;
    cout << "Enter frame size: ";
    cin >> frameSize;
    if ((int)referenceString.size() != refSize) {
        cout << "Error: reference string size does not match input length!\n";
        return 1;
    }

    lruPageReplacement(referenceString, frameSize);

    return 0;
}
