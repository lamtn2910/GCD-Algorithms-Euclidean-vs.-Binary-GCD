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

    srand(time(NULL));

    totalTime = 0;
    maxTime = 0;
    minTime = 0;

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

        printf("(%d,%d) %.15f\n", a, b, elapsedTime);
    }

    printf("=> %.15f\n", totalTime / N);
    printf("Average time: %.15f\n", totalTime / N);
    printf("Max time: %.15f\n", maxTime);
    printf("Min time: %.15f\n\n", minTime);


    totalTime = 0;
    maxTime = 0;
    minTime = 0;

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

        printf("(%d,%d) %.15f\n", a, b, elapsedTime);
    }

    printf("=> %.15f\n", totalTime / N);
    printf("Average time: %.15f\n", totalTime / N);
    printf("Max time: %.15f\n", maxTime);
    printf("Min time: %.15f\n\n", minTime);


    totalTime = 0;
    maxTime = 0;
    minTime = 0;

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

        printf("(%d,%d) %.15f\n", a, b, elapsedTime);
    }

    printf("=> %.15f\n", totalTime / N);
    printf("Average time: %.15f\n", totalTime / N);
    printf("Max time: %.15f\n", maxTime);
    printf("Min time: %.15f\n", minTime);

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


    totalTime = 0;
    maxTime = 0;
    minTime = 0;

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

        printf("(%d,%d) %.15f\n", a, b, elapsedTime);
    }

    printf("=> %.15f\n", totalTime / N);
    printf("Average time: %.15f\n", totalTime / N);
    printf("Max time: %.15f\n", maxTime);
    printf("Min time: %.15f\n\n", minTime);


    totalTime = 0;
    maxTime = 0;
    minTime = 0;

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

        printf("(%d,%d) %.15f\n", a, b, elapsedTime);
    }

    printf("=> %.15f\n", totalTime / N);
    printf("Average time: %.15f\n", totalTime / N);
    printf("Max time: %.15f\n", maxTime);
    printf("Min time: %.15f\n\n", minTime);


    totalTime = 0;
    maxTime = 0;
    minTime = 0;

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

        printf("(%d,%d) %.15f\n", a, b, elapsedTime);
    }

    printf("=> %.15f\n", totalTime / N);
    printf("Average time: %.15f\n", totalTime / N);
    printf("Max time: %.15f\n", maxTime);
    printf("Min time: %.15f\n", minTime);

    }
    return 0;
}
