#include<stdio.h>
#define SIZE 5

void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right);
void display(int arr[SIZE]);

void merge(int arr[], int left, int mid, int right) 
{
    int i = left;      
    int j = mid + 1;   
    int k = 0;         
    int temp[100];     

    while(i <= mid && j <= right) 
    {
        if(arr[i] < arr[j]) 
        {
            temp[k++] = arr[i++];
        } 
        else 
        {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) 
    {
        temp[k++] = arr[i++];
    }

    while(j <= right) 
    {
        temp[k++] = arr[j++];
    }

    for(i = left, k = 0; i <= right; i++, k++) 
    {
        arr[i] = temp[k];
    }
}

void merge_sort(int arr[], int left, int right) 
{
    if(left < right) 
    {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);       
        merge_sort(arr, mid + 1, right);   
        merge(arr, left, mid, right);    
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
    int arr[SIZE] = {50, 10, 20, 40, 30};
    int left = 0;
    int right = SIZE - 1;

    printf("Before Sort : ");
    display(arr);

    merge_sort(arr, left, right);

    printf("After Sort : ");
    display(arr);

    return 0;
}