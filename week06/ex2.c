#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    int processNumbers[n];

    for (int i = 0; i < n; i++)
    {
        processNumbers[i] = i + 1;
    }

    int arrivalTime[n];
    int burstTime[n];

    printf("Enter the arrival times: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrivalTime[i]);
    }

    printf("Enter the burst time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &burstTime[i]);
    }

    // in shortest job algorithm, we need to sort according to the burst time
    // so that the process with shortest burst time, will get executed first
    // (which is the main theory of shortest job algorithm)

    // sorting by arrival time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arrivalTime[i] < arrivalTime[j])
            {
                int temp = arrivalTime[i];
                arrivalTime[i] = arrivalTime[j];
                arrivalTime[j] = temp;

                // switch processNumbers and burst time too
                temp = processNumbers[i];
                processNumbers[i] = processNumbers[j];
                processNumbers[j] = temp;

                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
            }
        }
    }

    // then sorting by burst time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (burstTime[i] < burstTime[j])
            {
                int temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                temp = arrivalTime[i];
                arrivalTime[i] = arrivalTime[j];
                arrivalTime[j] = temp;

                // switch processNumbers and burst time too
                temp = processNumbers[i];
                processNumbers[i] = processNumbers[j];
                processNumbers[j] = temp;
            }
        }
    }

    int completeionTime[n];
    int turnaroundTime[n];
    int waitingTime[n];

    // int sumTurnaroundTime = 0, sumWaitingTime = 0, currentTime = 0;
    // int completed = 0;

    // int readyProcesses[n];
    // for (int i = 0; i < n; i++)
    // {
    //     readyProcesses[i] = 0;
    // }
    // memset(readyProcesses, 0, sizeof readyProcesses);
    // int execProcesses[n];
    // for (int i = 0; i < n; i++)
    // {
    //     execProcesses[i] = 0;
    // }
    // memset(execProcesses, 0, sizeof execProcesses);

    // while (completed < n)
    // {
    //     for (int i = 0; i < n; i++)
    //         if (arrivalTime[i] <= currentTime && !readyProcesses[i])
    //             readyProcesses[i] = 1;
    //     int best_proc = -1;

    //     // a very large value
    //     int mini = (1 << 29);

    //     for (int i = 0; i < n; i++)
    //     {
    //         if (!execProcesses[i] && readyProcesses[i] && burstTime[i] < mini)
    //         {
    //             mini = burstTime[i];
    //             best_proc = i;
    //         }
    //     }
    //     if (best_proc != -1)
    //     {
    //         completeionTime[best_proc] = currentTime + burstTime[best_proc];
    //         turnaroundTime[best_proc] = completeionTime[best_proc] - arrivalTime[best_proc];
    //         waitingTime[best_proc] = turnaroundTime[best_proc] - burstTime[best_proc];
    //         sumTurnaroundTime += turnaroundTime[best_proc];
    //         sumWaitingTime += waitingTime[best_proc];
    //         currentTime += burstTime[best_proc];
    //         completed++;
    //         execProcesses[best_proc] = 1;
    //     }
    // }

    int currentTime = 0;

    int sumTurnAroundTime = 0;
    int sumWaitingTime = 0;

    for(int i = 0; i < n; i++) {
        if(arrivalTime[i] > currentTime) {
            currentTime = arrivalTime[i];
        }

        completeionTime[i] = burstTime[i] + currentTime;
        turnaroundTime[i] = completeionTime[i] - arrivalTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];

        currentTime = completeionTime[i];
        
        sumTurnAroundTime += turnaroundTime[i];
        sumWaitingTime += waitingTime[i];
    }

    double averageTurnAroundTime = (double) sumTurnAroundTime / n;
	double averageWaitingTime = (double) sumWaitingTime / n;

    printf("Process Numbers\t Completeion Time:\t Turnaround Time:\t Waiting Time:\t\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n", processNumbers[i], completeionTime[i], turnaroundTime[i], waitingTime[i]);
    }

    printf("Average TurnAroundTime:%.2f\n", averageTurnAroundTime);
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
}