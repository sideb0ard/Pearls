#include <stdio.h>
#include <stdbool.h>

int sort_int_array(int *array, int len)
{ // returns 0 on success, 1 for error

    int tmp;
    bool tainted;

    while (1)
    {
        tainted = false;
        for (int i = 0; i < (len - 1); i++)
        {
            if (array[i] > array[i+1])
            {
                tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
                tainted = true;
            }
        }
        if (!tainted)
            break;
    }

    printf("SOrrted mate!\n");
    return 0;
}

//int recur_sort_array(int *array, int start, int end)
//{
//    int len = end - start;
//    if (len < 1)
//        return -1;
//    else if (len == 1)
//        return 0;
//    else
//    {
//    }
//}

int bin_search_int_array(int *array, int start, int end, int num_to_search_for)
{ // returns position of num_to_search_for in array or -1 if not found

    printf("BIN SEARCH! Looking for %d in range %d - %d\n", num_to_search_for, start, end);

    if (start > end)
        return -1;

    int mid = ((end - start) / 2) + start;

    if (num_to_search_for == array[mid])
        return mid;
    else if (num_to_search_for < array[mid])
        return bin_search_int_array(array, start, mid, num_to_search_for);
    else if (num_to_search_for > array[mid])
        return bin_search_int_array(array, mid + 1, end, num_to_search_for);

    return -1;
}


void print_int_array(int *array, int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%d", array[i]);
        if (i == (len-1))
            printf("\n");
        else
            printf(" ");
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return 1; // numpty

    const int nums_len = 10;
    //int nums[nums_len] = { 49, 26, 41, 36, 9, 101, 15, 148, 7, 75};
    int nums[nums_len] = { 49, 26, 41, 36, 9, 101, 15, 148, 7, 75};
    //int nums[nums_len] = { 1, 3 };
    print_int_array(nums, nums_len);

    sort_int_array(nums, nums_len);
    print_int_array(nums, nums_len);

    int nom;
    sscanf(argv[1], "%d", &nom);
    printf("Searching for %d..\n", nom);
    int result_position = bin_search_int_array(nums, 0, nums_len, nom);
    if (result_position == -1)
        printf("NUM:%d not found\n", nom);
    else
        printf("FOUND yer NUM:%d at position %d\n", nom, result_position);

}

