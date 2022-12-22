#include <stdio.h>
#define SIZE 50
void shift_element(int *arr, int i)
{
    int temp = *(arr + i);
    for (int j = i; j > 0; j--)
    {
        *(arr + j) = *(arr + j - 1);
    }
}
void insertion_sort(int *arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int j = i;
        while (j > 0 && *(arr + j) < *(arr + j - 1))
        {
            shift_element(arr, j);
            j--;
        }
    }
}
int main()
{
    int arr[50] = {0};
    printf("Enter 50 array elements: ");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", *(arr + i));
    }
    insertion_sort(arr, SIZE);
    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
            printf("%d\n", *(arr + i));
        else
            printf("%d,", *(arr + i));
    }
    return 0;
}