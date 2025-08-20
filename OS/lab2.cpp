#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void optimalPageReplacement(const string &referenceString, int frameSize) {
    vector<char> frames;
    int pageFaults = 0, pageHits = 0;
    int refLen = referenceString.length();

    cout << "\nStep-by-step Table (Optimal Page Replacement):\n";
    cout << "---------------------------------------------------------\n";
    cout << setw(10) << "Page"
         << setw(20) << "Frames"
         << setw(15) << "Page Fault"
         << setw(15) << "Page Hit\n";
    cout << "---------------------------------------------------------\n";

    for (int i = 0; i < refLen; ++i) {
        char currentPage = referenceString[i];
        bool found = false;

        // Check if current page is already in frame
        for (char f : frames) {
            if (f == currentPage) {
                found = true;
                break;
            }
        }

        if (!found) { // Page fault
            if ((int)frames.size() < frameSize) {
                frames.push_back(currentPage);
            } else {
                // Find the page in frames that will not be used for the longest time
                int indexToReplace = -1;
                int farthest = -1;

                for (int j = 0; j < frameSize; ++j) {
                    int k;
                    for (k = i + 1; k < refLen; ++k) {
                        if (referenceString[k] == frames[j])
                            break;
                    }
                    if (k > farthest) {
                        farthest = k;
                        indexToReplace = j;
                    }
                }

                // Replace the chosen page
                frames[indexToReplace] = currentPage;
            }
            pageFaults++;
        } else {
            pageHits++;
        }

        // Print current step
        cout << setw(10) << currentPage << setw(20);
        for (char f : frames) cout << f << " ";
        cout << setw(15) << (found ? "No" : "Yes")
             << setw(15) << (found ? "Yes" : "No") << "\n";
    }

    cout << "---------------------------------------------------------\n";
    cout << "Total Page Faults = " << pageFaults << endl;
    cout << "Total Page Hits   = " << pageHits;
}

int main() {
    int refSize;
    string referenceString;
    int frameSize;

    cout << "Enter reference string size: ";
    cin >> refSize;

    cout << "Enter reference string: ";
    for (int i = 0; i < refSize; ++i) {
        char page;
        cin >> page;
        referenceString += page;
    }

    cout << "Enter frame size: ";
    cin >> frameSize;

    optimalPageReplacement(referenceString, frameSize);

    return 0;
}
