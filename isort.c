#include <stdio.h>
#define SIZE 50
// printing the array
void printarr(int *arr, int l)
{
    for (int i = 0; i < l; i++)
    {
        if (i == l - 1)
            printf("%d\n", *(arr + i));
        else
            printf("%d,", *(arr + i));
    }
}
// shifting the elements to the right by one and taking the last element and putting it in the first place
void shift_element(int *arr, int i)
{
    int temp = *(arr + i);
    for (int k = 0; k < i; k++)
    {
        *(arr + i - k) = *(arr + i - k - 1);
    }
    *(arr) = temp;
}
// sorting the array using insertion sort
void insertion_sort(int *arr, int l)
{
    for (int i = 1; i < l; i++)
    {
        int j = i;
        int count = 0;
        while ((*(arr + i) < *(arr + j - 1)) && (j > 0))
        {
            j--;
            count++;
        }
        // printarr(arr, l);
        if (i != j)
            shift_element((arr + j), count);
    }
}
int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", (arr + i));
    }
    insertion_sort(arr, SIZE);
    printarr(arr, SIZE);
    return 0;
}