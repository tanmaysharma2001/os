#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/time.h>

long currentTimeMillis()
{
	struct timeval time;
	gettimeofday(&time, NULL);

	return time.tv_sec * 1000 + time.tv_usec / 1000;
}

int main(void)
{

	pid_t pid1 = fork();

	long begin;

	if (pid1 == 0)
	{
		begin = currentTimeMillis();
		printf("Child process. ID: %d, Parent ID: %d\n", getpid(), getppid());
	}
	else
	{
		pid_t pid2 = fork();

		begin = currentTimeMillis();

		if (pid2 == 0)
		{
			printf("Child process. ID: %d, Parent ID: %d\n", getpid(), getppid());
		}
		else
		{
			printf("Main process. ID: %d, Parent ID: %d\n", getpid(), getppid());
		}
	}

	long end = currentTimeMillis();
	long time_spent = end - begin;

	printf("Execution time for [PID = %d]: %ldms\n\n", getpid(), time_spent);

	return EXIT_SUCCESS;
}
