#include <stdio.h>

void merge(int arr[], int left, int mid, int right) 
{
    int i = left;      
    int j = mid + 1;   
    int k = 0;         
    int temp[100];     

    while (i <= mid && j <= right) 
    {
        if (arr[i] < arr[j]) 
        {
            temp[k++] = arr[i++];
        } 
        else 
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) 
    {
        temp[k++] = arr[i++];
    }

    while (j <= right) 
    {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) 
    {
        arr[i] = temp[k];
    }
}

void merge_sort(int arr[], int left, int right) 
{
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);       
        merge_sort(arr, mid + 1, right);   
        merge(arr, left, mid, right);    
    }
}

void display(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() 
{
    int arr[100], n;

    printf("Enter Number of Elements : ");
    scanf("%d", &n);

    printf("Enter %d elements : \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array:\n");
    display(arr, n);

    merge_sort(arr, 0, n - 1);

    printf("Sorted array:\n");
    display(arr, n);

    return 0;
}