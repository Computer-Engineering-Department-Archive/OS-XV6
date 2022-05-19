#include "types.h"
#include "stat.h"
#include "user.h"

#define N 4

int m1[N][N] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

int m2[N][N] = {
    {100, 101, 102, 103},
    {104, 105, 106, 107},
    {108, 109, 110, 111},
    {112, 113, 114, 115}
};

int m3[N][N] = {0};

void sum1(void *args)
{
    int p = 0, r = N/2;
    for (int i = p; i < r; i++)
    {
        printf(1, "SUM1-%d: ", thread_id());
        for (int j = 0; j < N; j++)
        {
            int sum = m1[i][j] + m2[i][j];
            m3[i][j] = sum;
            // printf(1, "%d, ", sum);
        }
        printf(1, "\n");
    }
}

void sum2(void *args)
{
    int p = N/2, r = N;
    for (int i = p; i < r; i++)
    {
        printf(1, "SUM2-%d: ", thread_id());
        for (int j = 0; j < N; j++)
        {
            int sum = m1[i][j] + m2[i][j];
            m3[i][j] = sum;
            // printf(1, "%d, ", sum);
        }
        printf(1, "\n");
    }
}

void display(int m[N][N]) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf(1, "%d, ", m[i][j]);
        }
        printf(1, "\n");
    }
}

int main()
{
    int tid = thread_creator(sum1, 0);
    int tid2 = thread_creator(sum2, 0);

    thread_join(tid);
    thread_join(tid2);

    display(m3);

    exit();
}