#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES_LENGTH 500
#define MAX_RESOURCES_LENGTH 500
#define MAX_LINE_LENGTH 256


int main()
{
    FILE *input = fopen("/home/tanmay/Tanmay/os/week13/input_ok.txt", "r");
    if (input != NULL) {
        char buffer[MAX_LINE_LENGTH];

        int processes[MAX_PROCESSES_LENGTH], existing_resources[MAX_RESOURCES_LENGTH], available_resources[MAX_RESOURCES_LENGTH], current_allocation[MAX_PROCESSES_LENGTH][MAX_RESOURCES_LENGTH], request[MAX_PROCESSES_LENGTH][MAX_RESOURCES_LENGTH];

        // reading the input
        fgets(buffer, MAX_LINE_LENGTH, input);

        char *pointerToRead = buffer;

        int index;
        index = 0;
        while (*pointerToRead != '\n') {
            int temp;
            temp = strtol(pointerToRead, &pointerToRead, 10);
            existing_resources[index++] = temp;
        }

        if (getc(input) == '\n') {

            fgets(buffer, MAX_LINE_LENGTH, input);
            pointerToRead = buffer;

            int index_2;
            index_2 = 0;
            while (*pointerToRead != '\n') {
                int temp;
                temp = strtol(pointerToRead, &pointerToRead, 10);
                available_resources[index_2++] = temp;
            }

            int temp;

            if (index == index_2 && getc(input) == '\n') {

                int n_processes = 0;

                while (strcmp(fgets(buffer, MAX_LINE_LENGTH, input), "\n") != 0) {

                    pointerToRead = buffer;

                    for (int i = 0; i < index; i++) {
                        temp = strtol(pointerToRead, &pointerToRead, 10);
                        current_allocation[n_processes][i] = temp;
                    }

                    n_processes++;
                }

                for (int i = 0; i < n_processes; i++) {
                    fgets(buffer, MAX_LINE_LENGTH, input);
                    pointerToRead = buffer;
                    for (int j = 0; j < index; j++) {
                        temp = strtol(pointerToRead, &pointerToRead, 10);
                        request[i][j] = temp;
                    }
                }

                bool process_ok[MAX_PROCESSES_LENGTH];
                for (int i = 0; i < MAX_PROCESSES_LENGTH; i++)
                    process_ok[i] = false;

                bool satisfied = true;

                while (satisfied) {
                    satisfied = false;
                    for (int i = 0; i < n_processes; i++) {
                        if (!process_ok[i]) {
                            bool can_provide = true;
                            for (int j = 0; j < index_2; j++) {
                                if (request[i][j] <= available_resources[j]) continue;
                                can_provide = false;
                                break;
                            }
                            if (can_provide) {

                                for (int j = 0; j < index_2; j++) {
                                    available_resources[j] += current_allocation[i][j];
                                }
                                satisfied = process_ok[i] = true;
                            }
                        }
                    }
                }

                FILE *output = fopen("/home/tanmay/Tanmay/os/week13/output_ok.txt", "w");

                bool deadlock = false;
                for (int i = 0; i < n_processes; i++) deadlock |= !(process_ok[i]);

                if (!deadlock) {
                    fprintf(output, "No deadlock found!\n");
                } else {
                    fprintf(output, "These processes are deadlocked: ");
                    for (int i = 0; i < n_processes; i++) {
                        if (process_ok[i]) continue;
                        fprintf(output, "%d, ", i);
                    }
                    fprintf(output, "\n");
                }
                return 0;
            } else {
                printf("Malformed input file!\n");
                return 1;
            }
        } else {
            printf("Malformed input file!\n");
            return 1;
        }
    } else {
        printf("Cannot open input file!\n");
        return 2;
    }
}