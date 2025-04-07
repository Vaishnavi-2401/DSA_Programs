#include<stdio.h>
#define SIZE 5

int binary_search(int arr[SIZE], int key);
int comparisons;

int main()
{
    int arr[SIZE] = { 10, 20, 30, 40, 50};
    int key;

    printf("Enter the Key to Search : \n");
    scanf("%d", &key);

    int index = binary_search(arr, key);

    if(index == -1)
    {
        printf("Key Not Found!\n");
    }
    else
    {
        printf("Key Found at Index : %d\n", index);
        printf("Comparisons : %d\n", comparisons);
    }

    return 0;
}

int binary_search(int arr[SIZE], int key)
{
    int left = 0, mid, right = SIZE - 1;

    while(left <= right)
    {
        mid = (left + right) / 2;

        comparisons++;

        if(key == arr[mid])
        {
            return mid;
        }
    
        if(key < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        } 
    }
    
    return -1;
}