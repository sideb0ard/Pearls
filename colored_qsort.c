#include <stdio.h>

#define PIVOT "\x1b[37m"
#define LOWERCOLOR "\x1b[38;5;226m"
#define UPPERCOLOR "\x1b[38;5;200m"
#define GREYRCOLOR "\x1b[38;5;124m"
#define ENDCOLOR "\x1b[38;5;47m"
#define RESET "\x1b[0m"

void print_nums(int *nums, int numnumbs)
{
    for (int i = 0; i < numnumbs; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void print_nums_bold(int *nums, int numnumbs, int pivot, int lower, int upper)
{
    for (int i = 0; i < numnumbs; ++i)
    {
        if (i == lower)
            printf(LOWERCOLOR);
        else if (i == upper)
            printf(LOWERCOLOR);
        else if (i == pivot)
            printf(PIVOT);

        printf("%d ", nums[i]);

        printf(RESET);
    }
    printf("\n");
}

void print_nums_gray(int *nums, int numnumbs, int pivot, int inspected)
{
    for (int i = 0; i < numnumbs; ++i)
    {
        if (i == inspected)
            printf(GREYRCOLOR);
        else if (i == pivot)
            printf(PIVOT);

        printf("%d ", nums[i]);

        printf(RESET);
    }
    printf("\n");
}

void swap(int *nums, int pos1, int pos2)
{
    //printf("Swopping pos %d (%d) with pos %d (%d)\n",
    //        pos1, nums[pos1], pos1, nums[pos2]);
    int tmp = nums[pos1];
    nums[pos1] = nums[pos2];
    nums[pos2] = tmp;
}

void bin_sort(int *nums, int lower, int upper)
{
    printf("LOWER:%d UPPER:%d\n", lower, upper);
    if (lower >= upper)
        return;

    int m = lower;
    for (int i = lower + 1; i < upper; ++i)
    {
        print_nums_gray(nums, 10, lower, i);
        if (nums[i] < nums[lower])
        {
            swap(nums, ++m, i);
            print_nums_bold(nums, 10, lower, m, i);
        }
    }
    swap(nums, lower, m);
    print_nums_bold(nums, 10, m, lower, -1);

    bin_sort(nums, lower, m);
    bin_sort(nums, m + 1, upper);
}

int main()
{
    //int nums[] = { 10, 9, 13, 36, 42, 4, 71, 7, 0, 5};
    //int nums[] = { 103, 41, 41, 7, 93, 234, 56, 2, 99, -2568};
    int nums[] = { 3, 8, 2, 5, 1, 4, 7, 6 };
    print_nums(nums, 8);
    printf("\n");
    bin_sort(nums, 0, 8);
    printf("\n");
    print_nums(nums, 8);
}
