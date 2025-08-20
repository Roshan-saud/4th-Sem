#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Job {
    int jobId;
    int burst;
    int remaining;
    int arrival;
    int completion;
    int tat;   // Turn Around Time
    int wt;    // Waiting Time
};

int main() {
    int totalJobs, timeSlice;
    cout << "Enter number of processes: ";
    cin >> totalJobs;

    vector<Job> taskList(totalJobs);

    // Assume all processes arrive at time 0
    for (int j = 0; j < totalJobs; j++) {
        taskList[j].jobId = j + 1;
        taskList[j].arrival = 0;
        cout << "Enter burst time for process " << j + 1 << ": ";
        cin >> taskList[j].burst;
        taskList[j].remaining = taskList[j].burst;
    }

    cout << "Enter Time Quantum: ";
    cin >> timeSlice;

    // Round Robin Simulation
    queue<int> rrQueue;
    int clk = 0, finished = 0;
    vector<bool> inLine(totalJobs, false);

    // Initially push all processes since AT = 0
    for (int j = 0; j < totalJobs; j++) {
        rrQueue.push(j);
        inLine[j] = true;
    }

    cout << "\nGantt Chart:\n|";

    while (!rrQueue.empty()) {
        int j = rrQueue.front();
        rrQueue.pop();
        inLine[j] = false;

        int runTime = min(timeSlice, taskList[j].remaining);
        clk += runTime;
        taskList[j].remaining -= runTime;

        cout << "  P" << taskList[j].jobId << "\t|";

        if (taskList[j].remaining == 0) {
            taskList[j].completion = clk;
            finished++;
        } else {
            rrQueue.push(j);
            inLine[j] = true;
        }
    }

    // Time scale printing
    cout << "\n0";
    clk = 0;
    queue<int> tempQ;
    for (int j = 0; j < totalJobs; j++) tempQ.push(j);
    vector<int> leftBurst(totalJobs);
    for (int j = 0; j < totalJobs; j++) leftBurst[j] = taskList[j].burst;

    while (!tempQ.empty()) {
        int j = tempQ.front();
        tempQ.pop();

        int runTime = min(timeSlice, leftBurst[j]);
        clk += runTime;
        leftBurst[j] -= runTime;
        cout << "     \t" << clk;

        if (leftBurst[j] > 0) tempQ.push(j);
    }
    cout << "\n";

    // Calculate TAT & WT
    cout << "\nProcess\tBT\tAT\tCT\tTAT (CT-AT)\tWT (TAT-BT)\n";
    double sumTAT = 0, sumWT = 0;

    for (int j = 0; j < totalJobs; j++) {
        taskList[j].tat = taskList[j].completion - taskList[j].arrival;
        taskList[j].wt = taskList[j].tat - taskList[j].burst;

        cout << "  P" << taskList[j].jobId << "\t"
             << taskList[j].burst << "\t"
             << taskList[j].arrival << "\t"
             << taskList[j].completion << "\t"
             << taskList[j].completion << "-" << taskList[j].arrival
             << "=" << taskList[j].tat << "\t\t"
             << taskList[j].tat << "-" << taskList[j].burst
             << "=" << taskList[j].wt << "\n";

        sumTAT += taskList[j].tat;
        sumWT += taskList[j].wt;
    }

    cout << "\nAverage Turnaround Time = " << sumTAT / totalJobs;
    cout << "\nAverage Waiting Time = " << sumWT / totalJobs << "\n";

    return 0;
}
