#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define REPEAT 1000000

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

unsigned int BinaryGCD(unsigned int a, unsigned int b)
{
    if (a == 0) return b;
    if (b == 0) return a;

    int Count2 = 0;
    while ((a & 1) == 0 && (b & 1) == 0)
    {
        a >>= 1;
        b >>= 1;
        Count2++;
    }

    while ((a & 1) == 0)
    {
        a >>= 1;
    }

    while (b != 0)
    {
        while ((b & 1) == 0)
        {
            b >>= 1;
        }
        if (a > b)
        {
            unsigned int temp = a;
            a = b;
            b = temp;
        }
        b -= a;
    }
    return a << Count2;
}

int gcdSteps(int a, int b) {
    int steps = 0;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
        steps++;
    }
    return steps;
}


int BinaryGCDSteps(unsigned int a, unsigned int b)
{
    int steps = 0;

    if (a == 0 || b == 0) return steps;

    while ((a & 1) == 0 && (b & 1) == 0)
    {
        a >>= 1;
        b >>= 1;
        steps++;
    }

    while ((a & 1) == 0)
    {
        a >>= 1;
        steps++;
    }

    while (b != 0)
    {
        while ((b & 1) == 0)
        {
            b >>= 1;
            steps++;
        }

        if (a > b)
        {
            unsigned int temp = a;
            a = b;
            b = temp;
            steps++;
        }

        b -= a;
        steps++;
    }

    return steps;
}


int main(void) {
    printf("EUCLIDEAN ALGORITHM\n");
    {
    int a, b;
    int result;

    clock_t start, end;

    double elapsedTime;
    double totalTime;
    double maxTime;
    double minTime;

    int steps;
    int totalSteps;
    int maxSteps;
    int minSteps;

    srand(time(NULL));

    totalTime = 0;
    maxTime = 0;
    minTime = 0;
    totalSteps = 0;
    maxSteps = 0;
    minSteps = 0;

    for (int i = 0; i < N; i++) {
        a = rand() % 90000 + 10001;
        b = rand() % 90000 + 10001;

        start = clock();

        for (int j = 0; j < REPEAT; j++) {
            result = gcd(a, b);
        }

        end = clock();

        elapsedTime =
            (double)(end - start) / CLOCKS_PER_SEC / REPEAT;

        totalTime += elapsedTime;

        if (elapsedTime > maxTime) maxTime = elapsedTime;
        if (i == 0 || elapsedTime < minTime) minTime = elapsedTime;

        steps = gcdSteps(a, b);
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

    for (int i = 0; i < N; i++) {

        do {
            a = rand() % 90000 + 10001;
            b = rand() % 90000 + 10001;
        } while (gcd(a, b) != 1);

        start = clock();

        for (int j = 0; j < REPEAT; j++) {
            result = gcd(a, b);
        }

        end = clock();

        elapsedTime =
            (double)(end - start) / CLOCKS_PER_SEC / REPEAT;

        totalTime += elapsedTime;

        if (elapsedTime > maxTime) maxTime = elapsedTime;
        if (i == 0 || elapsedTime < minTime) minTime = elapsedTime;

        steps = gcdSteps(a, b);
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

    for (int i = 0; i < N; i++) {

        int common = rand() % 10000 + 10001;
        int x = rand() % 3;
        int y = rand() % 3;

        a = common * (1 << x);
        b = common * (1 << y);

        start = clock();

        for (int j = 0; j < REPEAT; j++) {
            result = gcd(a, b);
        }

        end = clock();

        elapsedTime =
            (double)(end - start) / CLOCKS_PER_SEC / REPEAT;

        totalTime += elapsedTime;

        if (elapsedTime > maxTime) maxTime = elapsedTime;
        if (i == 0 || elapsedTime < minTime) minTime = elapsedTime;

        steps = gcdSteps(a, b);
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

    printf("\n\nBINARY GCD\n");
    {
    int a, b;
    int result;

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

    for (int i = 0; i < N; i++) {
        a = rand() % 90000 + 10001;
        b = rand() % 90000 + 10001;

        start = clock();

        for (int j = 0; j < REPEAT; j++) {
            result = BinaryGCD(a, b);
        }

        end = clock();

        elapsedTime =
            (double)(end - start) / CLOCKS_PER_SEC / REPEAT;

        totalTime += elapsedTime;

        if (elapsedTime > maxTime) maxTime = elapsedTime;
        if (i == 0 || elapsedTime < minTime) minTime = elapsedTime;

        steps = BinaryGCDSteps(a, b);
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

    for (int i = 0; i < N; i++) {

        do {
            a = rand() % 90000 + 10001;
            b = rand() % 90000 + 10001;
        } while (BinaryGCD(a, b) != 1);

        start = clock();

        for (int j = 0; j < REPEAT; j++) {
            result = BinaryGCD(a, b);
        }

        end = clock();

        elapsedTime =
            (double)(end - start) / CLOCKS_PER_SEC / REPEAT;

        totalTime += elapsedTime;

        if (elapsedTime > maxTime) maxTime = elapsedTime;
        if (i == 0 || elapsedTime < minTime) minTime = elapsedTime;

        steps = BinaryGCDSteps(a, b);
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

    for (int i = 0; i < N; i++) {

        int common = rand() % 10000 + 10001;
        int x = rand() % 3;
        int y = rand() % 3;

        a = common * (1 << x);
        b = common * (1 << y);

        start = clock();

        for (int j = 0; j < REPEAT; j++) {
            result = BinaryGCD(a, b);
        }

        end = clock();

        elapsedTime =
            (double)(end - start) / CLOCKS_PER_SEC / REPEAT;

        totalTime += elapsedTime;

        if (elapsedTime > maxTime) maxTime = elapsedTime;
        if (i == 0 || elapsedTime < minTime) minTime = elapsedTime;

        steps = BinaryGCDSteps(a, b);
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
