#include <stdio.h>
#define SIZE 5

void swap(int *a, int *b);
int partition(int arr[], int low, int high) ;
void quick_sort(int arr[], int low, int high);
void display(int arr[SIZE]);

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;   

    for(int j = low; j < high; j++) 
    {
        if(arr[j] < pivot) 
        {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quick_sort(int arr[], int low, int high) 
{
    if(low < high) 
    {
        int pivot_index = partition(arr, low, high);

        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

void display(int arr[SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%4d", arr[i]);
    }

    printf("\n");
}

int main() 
{
    int arr[SIZE] = {10, 50, 20, 30, 40};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sort : ");
    display(arr);

    quick_sort(arr, 0, n - 1);

    printf("After Sort : ");
    display(arr);

    return 0;
}