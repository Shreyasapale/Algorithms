#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int arr[20];
int n;

void printArray(int start, int end)
{
    printf("\n");
    for (int i = start; i <= end; i++)
    {
        printf("  %d", arr[i]);
    }
}

void insertionSort()
{
    // int swaps = 0;

    // printf("\n Initial Array : \n");
    // displayArray();
    for (int i = 1; i < n; i++)
    {
        // int currentSwap = 0;
        int currentNum = arr[i];
        int j = i - 1;
        while (arr[j] > currentNum && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
            // currentSwap++;
        }
        arr[j + 1] = currentNum;

        // printf("\n\n Pass : %d   Swap : %d \n", i, currentSwap);
        // displayArray();
        // swaps += currentSwap;
    }
    // printf("\n\nTotal Swaps = %d", swaps);
    // printf("\n\n Final Array : \n");
    // displayArray();
}

int binarySearch(int start, int end, int key)
{
    if (start <= end)
    {
        printf("\nThe array to be searched is : ");
        printArray(start, end);

        int mid = start + (end - start) / 2;
        printf("\nMid element is %d : ", arr[mid]);
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            binarySearch(start, mid - 1, key);
        }
        else
        {
            binarySearch(mid + 1, end, key);
        }
    }
    else
        return -1;
}

int main()
{
    int val;
    printf("\nBINARY SEARCH \n");
    printf("Enter the number of elements present in the array : \n (The number should be less than 20) \n ");
    scanf("%d", &n);
    printf("\nEnter the elements : \n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the element to be searched in the array : ");
    scanf("%d", &val);
    printf("\nThe array is : ");
    printArray(1, n);
    insertionSort();
    printf("\nThe Sorted array is : ");
    printArray(1, n);
    printf("\n");

    int index = binarySearch(1, n, val);
    if (index == -1)
    {
        printf("The element %d is not present in the array", val);
        return 0;
    }
    return 0;
}