#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define REPEAT 1000000

unsigned int extendedEuclid(unsigned int a, unsigned int b,long long *x, long long *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }

    long long x1, y1;
    unsigned int gcd = extendedEuclid(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int extendedEuclidSteps(unsigned int a, unsigned int b)
{
    int steps = 0;

    while (b != 0)
    {
        unsigned int r = a % b;
        a = b;
        b = r;
        steps++;
    }

    return steps;
}

int main(void)
{
    srand(time(NULL));

    printf("\n\nEXTENDED EUCLID\n");
    {
    int a, b;
    volatile unsigned int result;
    long long x, y;

    clock_t start, end;

    double elapsedTime;
    double totalTime;
    double maxTime;
    double minTime;

    int steps;
    int totalSteps;
    int maxSteps;
    int minSteps;

    totalTime = 0;
    maxTime = 0;
    minTime = 0;
    totalSteps = 0;
    maxSteps = 0;
    minSteps = 0;

    for (int i = 0; i < N; i++) 
    {
        a = rand() % 90000 + 10001;
        b = rand() % 90000 + 10001;

        start = clock();

        for (int j = 0; j < REPEAT; j++) 
        {
            result = extendedEuclid(a, b, &x, &y);
        }

        end = clock();

        elapsedTime =
            (double)(end - start) / CLOCKS_PER_SEC / REPEAT;

        totalTime += elapsedTime;

        if (elapsedTime > maxTime) maxTime = elapsedTime;
        if (i == 0 || elapsedTime < minTime) minTime = elapsedTime;

        steps = extendedEuclidSteps(a, b);
        totalSteps += steps;
        if (steps > maxSteps) maxSteps = steps;
        if (i == 0 || steps < minSteps) minSteps = steps;

        printf("(%d,%d) %.15f | Steps: %d\n", a, b, elapsedTime, steps);
    }

    printf("=> %.15f\n", totalTime / N);
    printf("Average time: %.15f\n", totalTime / N);
    printf("Max time: %.15f\n", maxTime);
    printf("Min time: %.15f\n", minTime);
    printf("Average step: %.2f\n", (double)totalSteps / N);
    printf("Max step: %d\n", maxSteps);
    printf("Min step: %d\n\n", minSteps);

    totalTime = 0;
    maxTime = 0;
    minTime = 0;
    totalSteps = 0;
    maxSteps = 0;
    minSteps = 0;

    for (int i = 0; i < N; i++) 
    {

        do {
            a = rand() % 90000 + 10001;
            b = rand() % 90000 + 10001;
        } while (extendedEuclid(a, b, &x, &y) != 1);

        start = clock();

        for (int j = 0; j < REPEAT; j++) 
        {
            result = extendedEuclid(a, b, &x, &y);
        }

        end = clock();

        elapsedTime =
            (double)(end - start) / CLOCKS_PER_SEC / REPEAT;

        totalTime += elapsedTime;

        if (elapsedTime > maxTime) maxTime = elapsedTime;
        if (i == 0 || elapsedTime < minTime) minTime = elapsedTime;

        steps = extendedEuclidSteps(a, b);
        totalSteps += steps;
        if (steps > maxSteps) maxSteps = steps;
        if (i == 0 || steps < minSteps) minSteps = steps;

        printf("(%d,%d) %.15f | Steps: %d\n", a, b, elapsedTime, steps);
    }

    printf("=> %.15f\n", totalTime / N);
    printf("Average time: %.15f\n", totalTime / N);
    printf("Max time: %.15f\n", maxTime);
    printf("Min time: %.15f\n", minTime);
    printf("Average step: %.2f\n", (double)totalSteps / N);
    printf("Max step: %d\n", maxSteps);
    printf("Min step: %d\n\n", minSteps);

    totalTime = 0;
    maxTime = 0;
    minTime = 0;
    totalSteps = 0;
    maxSteps = 0;
    minSteps = 0;

    for (int i = 0; i < N; i++) 
    {

        int common = rand() % 10000 + 10001;
        int xFactor = rand() % 3;
        int yFactor = rand() % 3;

        a = common * (1 << xFactor);
        b = common * (1 << yFactor);

        start = clock();

        for (int j = 0; j < REPEAT; j++) {
            result = extendedEuclid(a, b, &x, &y);
        }

        end = clock();

        elapsedTime =
            (double)(end - start) / CLOCKS_PER_SEC / REPEAT;

        totalTime += elapsedTime;

        if (elapsedTime > maxTime) maxTime = elapsedTime;
        if (i == 0 || elapsedTime < minTime) minTime = elapsedTime;

        steps = extendedEuclidSteps(a, b);
        totalSteps += steps;
        if (steps > maxSteps) maxSteps = steps;
        if (i == 0 || steps < minSteps) minSteps = steps;

        printf("(%d,%d) %.15f | Steps: %d\n", a, b, elapsedTime, steps);
    }

    printf("=> %.15f\n", totalTime / N);
    printf("Average time: %.15f\n", totalTime / N);
    printf("Max time: %.15f\n", maxTime);
    printf("Min time: %.15f\n", minTime);
    printf("Average step: %.2f\n", (double)totalSteps / N);
    printf("Max step: %d\n", maxSteps);
    printf("Min step: %d\n", minSteps);

    }
    return 0;
}
