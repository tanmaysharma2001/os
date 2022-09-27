#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define true 1
#define MAX_SIZE 100

int main(int argc, char const *argv[])
{

	// the process id that we will get in the child process which will be zero.
	pid_t pid1 = fork();

	// when it is in the child process, only then it will enter in the shell operation.
	if (pid1 == 0)
	{
		char userCommand[MAX_SIZE];

		while (true)
		{
			fgets(userCommand, 100, stdin);

			system(userCommand);
		}
	}

	wait(NULL);

	return EXIT_SUCCESS;
}

// Example on using system
// https://www.codingunit.com/c-reference-stdlib-h-function-system

// Example on using execve
// https://linuxhint.com/c-execve-function-usage/
