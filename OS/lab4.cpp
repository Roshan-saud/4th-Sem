#include <iostream>
#include <vector>
using namespace std;

struct Job {
    int pid;        // process id
    int bt;         // burst time
    int at;         // arrival time
    int ct;         // completion time
    int tat;        // turnaround time
    int wt;         // waiting time
};

int main() {
    int num;
    cout << "Enter number of processes: ";
    cin >> num;

    vector<Job> tasks(num);

    // All arrival times are zero
    for (int i = 0; i < num; i++) {
        tasks[i].pid = i + 1;
        tasks[i].at = 0;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> tasks[i].bt;
    }

    // Calculate CT, TAT, WT
    int time = 0;
    for (int i = 0; i < num; i++) {
        if (time < tasks[i].at)
            time = tasks[i].at;

        time += tasks[i].bt;
        tasks[i].ct = time;
        tasks[i].tat = tasks[i].ct - tasks[i].at;
        tasks[i].wt = tasks[i].tat - tasks[i].bt;
    }

    // Gantt Chart
    cout << "\nGantt Chart:\n|";
    time = 0;
    for (int i = 0; i < num; i++) {
        cout << "  P" << tasks[i].pid << "\t|";
    }
    cout << "\n0";
    for (int i = 0; i < num; i++) {
        time += tasks[i].bt;
        cout << "     \t" << time;
    }
    cout << "\n";

    // Final result table
    cout << "\nProcess\tBT\tAT\tCT\tTAT (CT-AT)\tWT (TAT-BT)\n";
    double sumTAT = 0, sumWT = 0;
    for (int i = 0; i < num; i++) {
        cout << "  P" << tasks[i].pid << "\t"
             << tasks[i].bt << "\t"
             << tasks[i].at << "\t"
             << tasks[i].ct << "\t"
             << tasks[i].ct << "-" << tasks[i].at
             << "=" << tasks[i].tat << "\t\t"
             << tasks[i].tat << "-" << tasks[i].bt
             << "=" << tasks[i].wt << "\n";

        sumTAT += tasks[i].tat;
        sumWT += tasks[i].wt;
    }

    cout << "\nAverage Turnaround Time = " << sumTAT / num;
    cout << "\nAverage Waiting Time = " << sumWT / num << "\n";

    return 0;
}
