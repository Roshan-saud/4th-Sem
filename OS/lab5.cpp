#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int pid;   // process id
    int bt;    // burst time
    int at;    // arrival time
    int ct;    // completion time
    int tat;   // turnaround time
    int wt;    // waiting time
};

int main() {
    int count;
    cout << "Enter number of processes: ";
    cin >> count;

    vector<Job> procs(count);

    // All arrival times = 0
    for (int i = 0; i < count; i++) {
        procs[i].pid = i + 1;
        procs[i].at = 0;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> procs[i].bt;
    }

    // ---- SJF: sort by burst time ----
    sort(procs.begin(), procs.end(), [](Job &x, Job &y) {
        return x.bt < y.bt;
    });

    // Calculate CT, TAT, WT
    int clk = 0;
    for (int i = 0; i < count; i++) {
        if (clk < procs[i].at)
            clk = procs[i].at;

        clk += procs[i].bt;
        procs[i].ct = clk;
        procs[i].tat = procs[i].ct - procs[i].at;
        procs[i].wt = procs[i].tat - procs[i].bt;
    }

    // Gantt Chart
    cout << "\nGantt Chart:\n|";
    clk = 0;
    for (int i = 0; i < count; i++) {
        cout << "  P" << procs[i].pid << "\t|";
    }
    cout << "\n0";
    for (int i = 0; i < count; i++) {
        clk += procs[i].bt;
        cout << "     \t" << clk;
    }
    cout << "\n";

    // Result table
    cout << "\nProcess\tBT\tAT\tCT\tTAT (CT-AT)\tWT (TAT-BT)\n";
    double sumTAT = 0, sumWT = 0;
    for (int i = 0; i < count; i++) {
        cout << "  P" << procs[i].pid << "\t"
             << procs[i].bt << "\t"
             << procs[i].at << "\t"
             << procs[i].ct << "\t"
             << procs[i].ct << "-" << procs[i].at
             << "=" << procs[i].tat << "\t\t"
             << procs[i].tat << "-" << procs[i].bt
             << "=" << procs[i].wt << "\n";

        sumTAT += procs[i].tat;
        sumWT += procs[i].wt;
    }

    cout << "\nAverage Turnaround Time = " << sumTAT / count;
    cout << "\nAverage Waiting Time = " << sumWT / count << "\n";

    return 0;
}
