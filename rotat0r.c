#include <stdio.h>

void print_noms(const int noms[], int len)
{
    for (int i = 0; i < len; i++)
    {
       printf("%d", noms[i]);
       if (i == len - 1)
          printf("\n");
       else
          printf(" ");
    }
}

void reverse_noms(int noms[], int len)
{
    for (int i = 0; i < len/2; i++)
    {
        int tmp = noms[i];
        noms[i] = noms[len - 1 - i];
        noms[len - 1 - i] = tmp;
    }
}

void rotate_noms(int noms[], int len, int num_rotate_positions)
{
    //int tmp = noms[0];
    //int i = 0;
    //for ( ;; i = ( i + num_rotate_positions) % len)
    //{
    //    int next_num = (i + num_rotate_positions) % len;
    //    if (next_num != 0)
    //        noms[i] = noms[next_num];
    //    else
    //        break;
    //    printf("Partial: ");
    //    print_noms(noms, 10);
    //}
    //noms[i] = tmp;

    num_rotate_positions = num_rotate_positions % len;
    reverse_noms(noms, num_rotate_positions);
    printf("Partial: ");
    print_noms(noms, 10);

    reverse_noms(noms + num_rotate_positions, len - num_rotate_positions);
    printf("Partial: ");
    print_noms(noms, 10);

    reverse_noms(noms, len);
    printf("Partial: ");
    print_noms(noms, 10);
}

void reset_nums(int nums[], int len)
{
    for (int i = 0 ; i < len; i++)
        nums[i] = i+1;
}

int main()
{
    int len = 10;
    int nums[len];
    reset_nums(nums, len);
    print_noms(nums, len);
    printf("\n");

    int rotate_tries[] = { 3, 0, 1, 13};
    for (int try = 0; try < 4; try++)
    {
        reset_nums(nums, len);
        printf("Rotate x %d\n", rotate_tries[try]);
        rotate_noms(nums, len, rotate_tries[try]);
        print_noms(nums, len);
    }

    printf("REVV\n");
    reset_nums(nums, len);
    reverse_noms(nums, len);
    print_noms(nums, len);
} 

