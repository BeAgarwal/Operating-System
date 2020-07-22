#include<bits/stdc++.h>
using namespace std;

/*
Completion Time: Time at which process completes its execution
Completion Time = Last Completion Time - Burst Time

Turn Around Time: Time difference between completion time and arrival time
Turn Around Time = Completion Time - Arrival Time

Waiting Time: Time difference between turn around time and burst time
Waiting Time = Turn Around Time - Burst Time
*/

void calculateCompletionTime(int numberOfProcess, int burstTime[], int completionTime[]) {
    completionTime[0] = burstTime[0];
    for (int it = 1; it < numberOfProcess; it++) {
        completionTime[it] = completionTime[it - 1] + burstTime[it];
    }
}

void calculateWaitingTime(int numberOfProcess, int turnAroundTime[], int burstTime[], int waitingTime[]) {
    waitingTime[0] = 0;
    for (int it = 1; it < numberOfProcess; it++) {
        waitingTime[it] = turnAroundTime[it] - burstTime[it];
    }
}

void calculateTurnAroundTime(int numberOfProcess, int arrivalTime[], int turnAroundTime[], int completionTime[]) {
    for (int it = 0; it < numberOfProcess; it++) {
        turnAroundTime[it] = completionTime[it] - arrivalTime[it];
    }
}

void display(int numberOfProcess, int arrivalTime[], int burstTime[], int completionTime[], int turnAroundTime[], int waitingTime[]) {
    cout << "P\tAT\tBT\tCT\tTAT\tWT" << endl;
    for (int it = 0; it < numberOfProcess; it++) {
        cout << it + 1 << "\t" << arrivalTime[it] << "\t" << burstTime[it] << "\t" << completionTime[it] << "\t" << turnAroundTime[it] << "\t" << waitingTime[it] << endl;
    }
}

float calculateAverageWaitingTime(int numberOfProcess, int waitingTime[]) {
    int totalWaitingTime = 0;
    for (int it = 0; it < numberOfProcess; it++) {
        totalWaitingTime += waitingTime[it];
    }
    float averageWaitingTime = (float)totalWaitingTime / numberOfProcess;
    return averageWaitingTime;
}

float calculateAverageTurnAroundTime(int numberOfProcess, int turnAroundTime[]) {
    int totalTurnAroundTime = 0;
    for (int it = 0; it < numberOfProcess; it++) {
        totalTurnAroundTime += turnAroundTime[it];
    }
    float averageTurnAroundTime = (float)totalTurnAroundTime / numberOfProcess;
    return averageTurnAroundTime;
}

int main()
{
    int numberOfProcess;
    // cout << "How many processes? ";
    cin >> numberOfProcess;
    int arrivalTime[numberOfProcess], burstTime[numberOfProcess];

    //cout << "Enter the arrival time and Burst time:";
    for (int it = 0; it < numberOfProcess; it++) {
        cin >> arrivalTime[it] >> burstTime[it];
    }

    int completionTime[numberOfProcess];
    int waitingTime[numberOfProcess];
    int turnAroundTime[numberOfProcess];

    calculateCompletionTime(numberOfProcess, burstTime, completionTime);
    calculateTurnAroundTime(numberOfProcess, arrivalTime, turnAroundTime, completionTime);
    calculateWaitingTime(numberOfProcess, turnAroundTime, burstTime, waitingTime);
    display(numberOfProcess, arrivalTime, burstTime, completionTime, turnAroundTime, waitingTime);

    cout << "Avg. Waiting Time: " << calculateAverageWaitingTime(numberOfProcess, waitingTime) << endl;
    cout << "Avg. Turn Around Time: " << calculateAverageTurnAroundTime(numberOfProcess, turnAroundTime);
    return 0;
}
