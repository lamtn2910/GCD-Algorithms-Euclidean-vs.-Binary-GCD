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

int checkGCD(int a, int b) {
    return gcd(a, b);
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
            result = gcd(a, b);
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
            result = gcd(a, b);
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
            result = gcd(a, b);
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