#include <stdio.h>

int min1, max1;
int min2, max2;
int arr[20];

void printArray(int start, int end)
{
    printf("\n");
    for (int i = start; i <= end; i++)
    {
        printf("  %d", arr[i]);
    }
}

void minMax(int left, int right, int *max, int *min)
{
    if (left == right)
    {
        printf("\nMin : %d \tMax : %d ", arr[left], arr[left]);
        if (*max < arr[right])
        {
            *max = arr[right];
        }
        if (*min > arr[left])
        {
            *min = arr[left];
        }
    }
    else if (right - left == 1)
    {
        if (arr[right] > arr[left])
        {
            if (*max < arr[right])
            {
                *max = arr[right];
            }
            if (*min > arr[left])
            {
                *min = arr[left];
            }
            printf("\nMin : %d \tMax : %d ", arr[left], arr[right]);

            // *max = arr[right];
            // *min = arr[left];
        }
        else
        {
            if (*max < arr[left])
            {
                *max = arr[left];
            }
            if (*min > arr[right])
            {
                *min = arr[right];
            }
            printf("\nMin : %d \tMax : %d ", arr[right], arr[left]);

            // *max = arr[left];
            // *min = arr[right];
        }
    }
    else
    {
        int mid = (left + right) / 2;
        printf("\nArray is : ");
        printArray(left, mid);
        minMax(left, mid, &max1, &min1);
        printArray(left, mid);
        // printf("\n The array is : \n");
        // printArray(left, mid);
        // printf("\nMin is %d and \n max is %d ", max1, min1);
        printf("\nArray is : ");
        printArray(mid + 1, right);
        minMax(mid + 1, right, &max2, &min2);

        // printf("\n The array is : \n");
        // printArray(left, mid);
        // printf("\nMin is %d and \n max is %d ", max2, min2);
        if (max1 < max2)
        {
            max1 = max2;
        }
        if (min1 > min2)
        {
            min1 = min2;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements present in the array : \n (The number should be less than 20) \n ");
    scanf("%d", &n);
    printf("\nEnter the elements : \n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n The entire array is : ");
    printArray(1, n);
    min1 = max1 = min2 = max2 = arr[1];
    minMax(1, n, &max1, &min1);
    printf("\n\nThe final answer : ");
    printf("\nMin : %d  \nMax : %d ", min1, max1);
    return 0;
}
