#include <stdio.h>
#include <stdlib.h>

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *));

void *addInt(const void *a, const void *b)
{
    //<WRITE YOUR CODE HERE>;
    int result = *((int *)a) + *((int *)b);
    int *returnPointer = &result;
    return (void *)returnPointer;
}

void *addDouble(const void *a, const void *b)
{

    //<WRITE YOUR CODE HERE>;
    double result = *((double *)a) + *((double *)b);
    double *returnPointer = &result;
    return (void *)returnPointer;
}

void *mulInt(const void *a, const void *b)
{

    //<WRITE YOUR CODE HERE>;
    int result = *((int *)a) * *((int *)b);
    int *returnPointer = &result;
    return (void *)returnPointer;
}

void *mulDouble(const void *a, const void *b)
{

    //<WRITE YOUR CODE HERE>;
    double result = *((double *)a) * *((double *)b);
    double *returnPointer = &result;
    return (void *)returnPointer;
}

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *))
{

    void *output;

    if (size == sizeof(int))
    { // base is a pointer to an integer

        //<WRITE YOUR CODE HERE>;
        int initialValue = *((int *)initial_value);
        // as we need the actual adress instead of the value.
        output = &initialValue;

        for (int i = 0; i < n; i++)
        {
            output = opr(output, ((int *)base + i));
        }
    }
    else
    { // base is a pointer to a double

        //<WRITE YOUR CODE HERE>;
        double initialValue = *((double *)initial_value);
        output = &initialValue;
        for (int i = 0; i < n; i++)
        {
            output = opr(output, ((double *)base + i));
        }
    }

    return output;
}

int main()
{

    int n = 5;

    int *ints = malloc(sizeof(int) * 5);
    double *doubles = malloc(sizeof(double) * 5);

    //<WRITE YOUR CODE HERE>;
    for (int i = 0; i < n; i++)
    {
        *(ints + i) = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        *(doubles + i) = i + 2.0;
    }

    // initial values

    int addIntInitialValue = 0;
    int *addIntInitialPointer = &addIntInitialValue;

    double addDoubleInitialValue = 0.0;
    double *addDoubleInitialPointer = &addDoubleInitialValue;

    int mulIntInitialValue = 1;
    int *mulIntInitialPointer = &mulIntInitialValue;

    double mulDoubleInitialValue = 1.0;
    double *mulDoubleInitialPointer = &mulDoubleInitialValue;

    // Addition

    int *result1a = aggregate(ints, sizeof(int), n, addIntInitialPointer, &addInt);

    //<WRITE YOUR CODE HERE>;

    printf("%d\n", *result1a);

    double *result2a = aggregate(doubles, sizeof(double), n, addDoubleInitialPointer, &addDouble);

    //<WRITE YOUR CODE HERE>;

    printf("%f\n", *result2a);

    // Multiplication

    int *result1m = aggregate(ints, sizeof(int), n, mulIntInitialPointer, &mulInt);

    //<WRITE YOUR CODE HERE>;

    printf("%d\n", *result1m);

    double *result2m = aggregate(doubles, sizeof(double), n, mulDoubleInitialPointer, &mulDouble);

    //<WRITE YOUR CODE HERE>;

    printf("%f\n", *result2m);

    // Mean

    int *result1mean = aggregate(ints, sizeof(int), n, addIntInitialPointer, &addInt);

    //<WRITE YOUR CODE HERE>;

    printf("%d\n", (*result1mean / n));

    double *result2mean = aggregate(doubles, sizeof(double), n, addDoubleInitialPointer, &addDouble);

    //<WRITE YOUR CODE HERE>;

    printf("%f\n", (*result2mean / n));

    // free the pointers
    //<WRITE YOUR CODE HERE>;
    free(ints);
    free(doubles);

    return EXIT_SUCCESS;
}
