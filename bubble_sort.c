#include<stdio.h>
#define SIZE 5
#define SWAP(a, b)  int temp = a; a = b; b = temp;

void bubble_sort(int arr[SIZE]);
void display(int arr[SIZE]);

int main()
{
    int arr[SIZE] = {50, 40, 30, 20, 10};

    printf("Before Sort : ");
    display(arr);

    bubble_sort(arr);

    printf("After Sort : ");
    display(arr);

    return 0;
}

void bubble_sort(int arr[SIZE])
{
    int iterations = 0, comparisons = 0;
    int itr, pos;

    for(itr = 0; itr < SIZE -1; itr++)
    {
        iterations++;

        for(pos = 0; pos < SIZE - 1 - itr; pos++)
        {
            comparisons++;

            if(arr[pos] > arr[pos + 1])
            {
                SWAP(arr[pos], arr[pos + 1]);
            }
        }
    }

    printf("Iterations : %d\n", iterations);
    printf("Comparisons : %d\n", comparisons);
}

void display(int arr[SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%4d", arr[i]);
    }

    printf("\n");
}