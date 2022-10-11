#include <stdio.h>

// burst time: total time taken by the process
// arrival time: time when process arrives
// exit time: time when process complete it's execution
// response time: time spent between when the proccess was ready and when it got the cpy for the first time.
// RT = Time when process got the cpu - AT
// Waiting time: WT = Turnaround time - Burst Time
// Turn around time (TAT): total amount of time spent by the process from coming in the ready state for the first iem to its completeion.
// TAT = BT + WT
// TAT = ET - AT


int main() {
	int n;
	scanf("%d", &n);
	
	int processNumbers[n];

	for(int i = 0; i < n; i++) {
		processNumbers[i] = i+1;
	}

	int arrivalTime[n];
	int burstTime[n];
	
	printf("Enter the arrival times: ");
	for(int i = 0; i < n; i++) {
		scanf("%d", &arrivalTime[i]);
	}

	printf("Enter the burst time: ");
	for(int i = 0; i < n; i++) {
		scanf("%d", &burstTime[i]);
	}

	// Sorting the arrival time and burst time as the input can be in non-sorted order

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(arrivalTime[i] < arrivalTime[j]) {
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

	int completeionTime[n];
	int turnaroundTime[n];
	int waitingTime[n];

	int sumTurnaroundTime = 0, sumWaitingTime = 0, currentTime = 0;

	for(int i = 0; i < n; i++) {
		if(arrivalTime[i] > currentTime) {
			currentTime = arrivalTime[i];
		}

		completeionTime[i] = currentTime + burstTime[i];

		turnaroundTime[i] = completeionTime[i] - arrivalTime[i];

		waitingTime[i] = turnaroundTime[i] - burstTime[i];

		sumTurnaroundTime += turnaroundTime[i];

		sumWaitingTime += waitingTime[i];

		currentTime += burstTime[i];
	}

	double averageTurnAroundTime = (double) sumTurnaroundTime / n;
	double averageWaitingTime = (double) sumWaitingTime / n;

	printf("Process Numbers\t Completeion Time:\t Turnaround Time:\t Waiting Time:\t\n");
	for(int i = 0; i < n; i++) {
		printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n", processNumbers[i], completeionTime[i], turnaroundTime[i], waitingTime[i]);	
	}

	printf("Average TurnAroundTime:%.2f\n", averageTurnAroundTime);
	printf("Average Waiting Time: %.2f\n", averageWaitingTime);

}
