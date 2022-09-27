#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_SIZE 120

int dotprod(int u[], int v[], int start, int end)
{

	int result = 0;

	for (int i = start; i <= end; i++)
	{
		result += u[i] * v[i];
	}

	return result;
}

int main(void)
{

	// <WRITE YOUR CODE HERE>

	int u[MAX_SIZE];
	int v[MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; i++)
	{
		u[i] = rand() % 100;
		v[i] = rand() % 100;
	}

	int n;
	scanf("%d", &n);

	FILE *foutr = fopen("temp.txt", "w");

	for (int i = 0; i < n; i++)
	{
		pid_t pid = fork();
		if (pid == 0)
		{
			int count = MAX_SIZE / n;
			int result = dotprod(u, v, count * i, count * i + count - 1);

			fprintf(foutr, "%d ", result);
			
			exit(0);
		}
	}
	fprintf(foutr, "\n");

	FILE *fitr = fopen("temp.txt", "r");

	int finalResult = 0;

	for(int i = 0; i < n; i++) {
		int value;
		fscanf(fitr, "%d", &value);

		finalResult += value;
	}

	fprintf(foutr, "%d", finalResult);

	fclose(fitr);
	fclose(foutr);

	for (int i = 0; i < n; i++)
	{
		wait(NULL);
	}

	return EXIT_SUCCESS;
}
