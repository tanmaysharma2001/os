#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define true 1
#define MAX_SIZE 100

int main(int argc, char const *argv[])
{

	char userCommand[MAX_SIZE];

	while (true)
	{
		fgets(userCommand, 100, stdin);

		system(userCommand);
	}

	return EXIT_SUCCESS;
}

// Example on using system
// https://www.codingunit.com/c-reference-stdlib-h-function-system

// Example on using execve
// https://linuxhint.com/c-execve-function-usage/
