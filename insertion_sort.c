#include<stdio.h>
#define SIZE 5

void insertion_sort(int arr[SIZE]);
void display(int arr[SIZE]);

int main()
{
    int arr[SIZE] = {40, 10, 50, 30, 20};

    printf("Before Sort : ");
    display(arr);

    insertion_sort(arr);

    printf("After Sort : ");
    display(arr);

    return 0;
}

void insertion_sort(int arr[SIZE])
{
    int i, j, temp;

    for(i = 1; i < SIZE; i++)
    {
        temp = arr[i];

        for(j = i - 1; j >= 0 && temp < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = temp;
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