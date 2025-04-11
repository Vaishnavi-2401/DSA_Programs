#include<stdio.h>
#define SIZE 5
#define SWAP(a, b) int temp = a; a = b, b = temp;

void selection_sort(int arr[SIZE]);
void display(int arr[SIZE]);

int main()
{
    int arr[SIZE] = {30, 10, 50, 40, 20};

    printf("Before Sort : ");
    display(arr);

    selection_sort(arr);

    printf("After Sort : ");
    display(arr);

    return 0;
}

void selection_sort(int arr[SIZE])
{
    int sel_pos, pos;
    int iterations = 0, comparisons = 0;

    for(sel_pos = 0; sel_pos < SIZE - 1; sel_pos++)
    {
        iterations++;

        for(pos = sel_pos + 1; pos < SIZE; pos++)
        {
            comparisons++;

            if(arr[sel_pos] > arr[pos])
            {
                SWAP(arr[sel_pos],arr[pos]);
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