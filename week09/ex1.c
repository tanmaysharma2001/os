#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Ageing Algorithm
// number of page frames - parameters

#define MAX_PAGES 1000
#define AGE_LIM 32

int main(int argc, char *argv[])
{
    // number of page frames
    if(argc != 2) {
        printf("Please enter the number of page frames.");
        return 1;
    }
    unsigned int n = atoi(argv[1]);

    int pageTable[n];

    for(int i = 0; i < n; i++) {
        pageTable[i] = -1;
    }

    int numberOfPages = 0;
    int pages[MAX_PAGES];

    for(int i = 0; i < MAX_PAGES; i++) {
        pages[i] = 0;
    }

    FILE* inputFile = fopen("Lab 09 input.txt", "r");
    if(inputFile == NULL) {
        printf("Cannot read input file.");
        return 1;
    }

    int page;
    while(fscanf(inputFile, "%d", &page) != EOF) {
        pages[numberOfPages] = page;
        numberOfPages++;
    }
    fclose(inputFile);

    // pages time values
    // indexing by pages
    unsigned int pageValues[MAX_PAGES];

    for(int i = 0; i < MAX_PAGES; i++) {
        pageValues[i] = 0;
    }

    int misses = 0;

    int hits = 0;

    for(int i = 0; i < numberOfPages; i++) {

        int page = pages[i];

        int itsAHit = 0;

        for(int j = 0; j < n; j++) {
            if(page == pageTable[j]) {
                itsAHit = 1;
                hits++;
                break;
            }
        }

        if(itsAHit == 0) {

            misses++;

            // the maximum value to find the minimum
            unsigned int minTime = UINT_MAX;
            int minIndex = 0;

            for(int j = 0; j < n; j++) {
                if (pageTable[j] == -1) {
                    minIndex = j;
                    break;
                }
                unsigned int pageValue = pageValues[pageTable[j]];
                if(pageValue < minTime) {
                    minTime = pageValue;
                    minIndex = j;
                }
            }

            pageTable[minIndex] = page;
            pageValues[page] = 0;
        }

        for(int j = 0; j < MAX_PAGES; j++) {
            pageValues[j] >>= 1;
        }

//        for(int j = 0; j < n; j++) {
//            pageValues[pageTable[j]] >>= 1;
//        }

        pageValues[page] |= 1 << (AGE_LIM - 1);
    }

//    int hits = numberOfPages - misses;

    double hitMissRatio = hits/(double)misses;

    printf("Hits: %d\n", hits);

    printf("Misses: %d\n", misses);

    printf("Hits/Miss Ratio: %f\n", hitMissRatio);

}