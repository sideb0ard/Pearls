#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int nums_len = 10;
static int nums[] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};

bool is_bigger(int numone, int numtwo)
{
    return numtwo > numone ? true : false;
}

int max(int one, int two)
{
    if (one > two)
        return one;
    return two;
}

long get_time_ns()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    return ts.tv_nsec;
}

void linear_find()
{
    long starttime = get_time_ns();
    int maxsofar = 0;
    int maxendinghere = 0;
    for (int i = 0; i < nums_len; ++i)
    {
        maxendinghere = max(maxendinghere + nums[i], 0); 
        maxsofar = max(maxsofar, maxendinghere);
    }
    long endtime = get_time_ns();
    long duration = endtime - starttime;
    printf("Linear// Max:%d - took%lu ms\n", maxsofar, duration);
}

void quad_find1()
{
    long starttime = get_time_ns();
    int maxsofar = 0;
    int start, end = 0;
    for (int i = 0; i < nums_len; ++i)
    {
        int sum = 0;
        for (int j = i; j < nums_len; ++j)
        {
            sum += nums[j];
            if (is_bigger(maxsofar, sum))
            {
                start = i;
                end = j;
                maxsofar = sum;
            }
        }
    }
    long endtime = get_time_ns();
    long duration = endtime - starttime;
    printf("QUAD1//MAX: %d (Found between %d and %d) - took:%lu\n", maxsofar, start, end, duration);
}

void cube_find()
{
    long starttime = get_time_ns();
    int maxsofar = 0;
    int start, end = 0;
    for (int i = 0; i < nums_len; ++i)
    {
        for (int j = i; j < nums_len; ++j)
        {
            int sum = 0;
            for (int k = i; k <= j; ++k)
                sum += nums[k];

            if (is_bigger(maxsofar, sum))
            {
                start = i;
                end = j;
                maxsofar = sum;
            }
        }
    }
    long endtime = get_time_ns();
    long duration = endtime - starttime;
    printf("CUBE//MAX: %d (Found between %d and %d) - took:%lu\n", maxsofar, start, end, duration);
}

void candidate()
{
    int sum;
    int max = nums[0];
    for (int i = 0; i < nums_len; ++i)
    {
        sum = nums[i];
        for (int j = i+1; j < nums_len; ++j)
        {
            sum = sum + nums[j];
            if (sum > max)
                max = sum;
        }
    }
    printf("MAX:%d\n", max);
}
            


int main()
{
    cube_find();
    quad_find1();
    linear_find();
    candidate();
}
