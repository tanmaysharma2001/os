#include <stdio.h>
#include <limits.h>

// Ageing Algorithm
// number of page frames - parameters

#define MAX_PAGES 1000
#define AGE_LIM 32

int main()
{
    // number of page frames
    printf("Enter number of page frames: ");
    unsigned int n;
    scanf("%d", &n);

    unsigned int pageTable[n];

    for(int i = 0; i < n; i++) {
        pageTable[i] = 0;
    }

    int numberOfPages = 0;
    int pages[MAX_PAGES];

    for(int i = 0; i < MAX_PAGES; i++) {
        pages[i] = 0;
    }

    printf("Type how you want the input to be:\n0 - for input file\t1 - for console\n");
    int response;
    scanf("%d", &response);

    if(response == 1) {
        printf("Enter number of pages:");
        scanf("%d", &numberOfPages);

        for (int i = 0; i < numberOfPages; i++)
        {
            scanf("%d", &pages[i]);
        }
    }
    else {
        FILE* inputFile = fopen("/home/tanmay/Tanmay/os/week09/input.txt", "r");
        int page;
        while(fscanf(inputFile, "%d", &page) != EOF) {
            pages[numberOfPages] = page;
            numberOfPages++;
        }
        fclose(inputFile);
    }

    // pages time values
    // indexing by pages
    unsigned int pageValues[MAX_PAGES];

    for(int i = 0; i < MAX_PAGES; i++) {
        pageValues[i] = 0;
    }

    int misses = 0;

//    for(int i = 0; i < numberOfPages; i++) {
//        printf("%d ", pages[i]);
//    }
//    printf("\n");

//    printf("Hello");

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
                unsigned int pageValue = pageValues[pageTable[j]];
                if(pageValue <= minTime) {
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