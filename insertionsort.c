#include <stdio.h>

void print_nums(int *nums, int numnumbs)
{
    for (int i = 0; i < numnumbs; ++i)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void swap(int *nums, int pos1, int pos2)
{
}

void insertion_sort(int *nums, int numnumbs)
{
    for (int i = 1; i < numnumbs; ++i)
    {
        for (int j = i; j > 0 && nums[j-1] > nums[j]; --j)
        {
            int tmp = nums[j];
            nums[j] = nums[j-1];
            nums[j-1] = tmp;
        }
    }
}

int main()
{
    int nums[] = { 10, 9, 13, 3, 42, 4, 7, 7, 0, 5};
    print_nums(nums, 10);
    printf("\n");
    insertion_sort(nums, 10);
    printf("\n");
    print_nums(nums, 10);
}
