#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define REPEAT 1000000

unsigned int BinaryGCD(unsigned int a, unsigned int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    int Count2 = 0;
    while (a % 2 == 0 && b % 2 == 0)
    {
        a /= 2;
        b /= 2;
        Count2++;
    }
    while (a % 2 == 0)
    {
        a /= 2;
    }
    do
    {
        while (b % 2 == 0)
        {
            b /= 2;
        }
        if (a > b)
        {
            unsigned int temp = a;
            a = b;
            b = temp;
        }
        b -= a;
    } while (b != 0);
    return a * (1 << Count2);
}

int checkGCD(int a, int b) {
    return BinaryGCD(a, b);
}

int main() {
    int a, b;
    int result;

    clock_t start, end;

    double elapsedTime;
    double totalTime;

    srand(time(NULL));

    totalTime = 0;

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

        printf("(%d,%d) %.15f\n", a, b, elapsedTime);
    }

    printf("=> %.15f\n\n", totalTime / N);


    totalTime = 0;

    for (int i = 0; i < N; i++) {

        do {
            a = rand() % 90000 + 10001;
            b = rand() % 90000 + 10001;
        } while (checkGCD(a, b) != 1);

        start = clock();

        for (int j = 0; j < REPEAT; j++) {
            result = BinaryGCD(a, b);
        }

        end = clock();

        elapsedTime =
            (double)(end - start) / CLOCKS_PER_SEC / REPEAT;

        totalTime += elapsedTime;

        printf("(%d,%d) %.15f\n", a, b, elapsedTime);
    }

    printf("=> %.15f\n\n", totalTime / N);


    totalTime = 0;

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

        printf("(%d,%d) %.15f\n", a, b, elapsedTime);
    }

    printf("=> %.15f\n", totalTime / N);

    return 0;
}
