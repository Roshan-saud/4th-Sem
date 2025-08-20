#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

void fifoPageReplacement(const string &referenceString, int frameSize) {
    vector<char> frames;    // store characters in frames
    queue<char> q;          // FIFO order
    int pageFaults = 0, pageHits = 0;

    cout << "\nStep-by-step Table (FIFO Page Replacement):\n";
    cout << "---------------------------------------------------------------\n";
    cout << setw(10) << "Page"
         << setw(20) << "Frames"
         << setw(15) << "Page Fault"
         << setw(15) << "Page Hit\n";
    cout << "---------------------------------------------------------------\n";

    for (char page : referenceString) {
        bool found = false;

        // Check if page is already in frames
        for (char f : frames) {
            if (f == page) {
                found = true;
                break;
            }
        }

        if (!found) { // Page fault
            if ((int)frames.size() < frameSize) {
                frames.push_back(page);
                q.push(page);
            } else {
                // Replace oldest page (front of queue)
                char oldPage = q.front();
                q.pop();

                for (int i = 0; i < frameSize; i++) {
                    if (frames[i] == oldPage) {
                        frames[i] = page;
                        break;
                    }
                }
                q.push(page);
            }
            pageFaults++;
        } else {
            pageHits++;
        }

        // Print current step
        cout << setw(10) << page << setw(20);
        for (char f : frames) cout << f << " ";
        cout << setw(15) << (found ? "No" : "Yes")
             << setw(15) << (found ? "Yes" : "No") << "\n";
    }

    cout << "---------------------------------------------------------------\n";
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

    fifoPageReplacement(referenceString, frameSize);

    return 0;
}
