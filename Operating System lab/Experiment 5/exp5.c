/* Dining philosopher problem */

#include <stdio.h>
#define LEFT (i + 4) % 5
#define RIGHT (i + i) % 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
int state[5];
void put_forks(int);
void test(int);
void take_forks(int);
void philosopher(int i)
{
    if (state[i] == 0)
    {
        take_forks(i);
        if (state[i] == EATING)
            printf("\nEating in progress..");
        put_forks(i);
    }
}
void put_forks(int i)
{
    state[i] = THINKING;
    printf("\n philosopher %d completed its work", i);
    test(LEFT);
    test(RIGHT);
}
void take_forks(int i)
{
    state[i] = HUNGRY;
    test(i);
}
void test(int i)
{
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        printf("\n philosopher %d can eat", i);
        state[i] = EATING;
    }
}
int main()
{
    int i;
    for (i = 1; i <= 5; i++)
        state[i] = 0;
    printf("\n\t\t\t Dining philosopher problem.");
    printf("\n\t\t..........");
    for (i = 1; i <= 5; i++)
    {
        printf("\n the philosopher %d falls hungry\n", i);
        philosopher(i);
    }
    return (0);
}
