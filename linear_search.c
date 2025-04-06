#include<stdio.h>
#define SIZE 5

int linear_search(int arr[SIZE], int key);
int comparisons;

int main()
{
    int arr[SIZE] = {10, 20, 30, 40, 50};
    int key;

    printf("Enter the Key to Search : \n");
    scanf("%d", &key);

    int res = linear_search(arr, key);

    if(res == -1)
    {
        printf("Key Not Found!\n");
    }
    else
    {
        printf("Key Found at Index : %d\n", res);
        printf("Comparisons : %d\n", comparisons);
    }

    return 0;
}

int linear_search(int arr[SIZE], int key)
{
    for(int index = 0; index < SIZE; index++)
    {
        comparisons++;
        
        if(key == arr[index])
        {
            return index;
        }
    }

    return -1;
}