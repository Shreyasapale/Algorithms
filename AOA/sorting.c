#include <stdio.h>
#include <conio.h>
#include <math.h>

int arr[20];
int n;

void displayArray()
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("  %d", arr[i]);
    }
}

void printArray()
{
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("  %d", arr[i]);
    }
}

void customDisplay(int start, int end)
{
    printf("\n");
    for (int i = start; i <= end; i++)
    {
        printf("  %d", arr[i]);
    }
}

void swap(int i, int j)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void selectionSort()
{
    int min;
    int swaps = 0;
    printf("\n Initial Array : \n");
    displayArray();
    for (int i = 0; i < n; i++)
    {
        int currentSwap = 0;
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(min, i);
            swaps++;
            currentSwap++;
        }
        printf("\n\n Pass : %d   Swap : %d \n", i + 1, currentSwap);
        displayArray();
    }
    printf("\n\nTotal Swaps = %d", swaps);
}
void insertionSort()
{
    int swaps = 0;

    printf("\n Initial Array : \n");
    displayArray();
    for (int i = 1; i < n; i++)
    {
        int currentSwap = 0;
        int currentNum = arr[i];
        int j = i - 1;
        while (arr[j] > currentNum && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
            currentSwap++;
        }
        arr[j + 1] = currentNum;

        printf("\n\n Pass : %d   Swap : %d \n", i, currentSwap);
        displayArray();
        swaps += currentSwap;
    }
    printf("\n\nTotal Swaps = %d", swaps);
    printf("\n\n Final Array : \n");
    displayArray();
}

void merge(int p, int q, int r)
{
    int i, j;
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    for (i = 1; i <= n1; i++)
        L[i] = arr[p + i - 1];
    for (j = 1; j <= n2; j++)
        R[j] = arr[q + j];
    L[n1 + 1] = 99999;
    R[n2 + 1] = 99999;
    i = 1;
    j = 1;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
    // printArray();
}

void mergeSort(int p, int r)
{
    int q;
    if (p < r)
    {
        q = floor((p + r) / 2);
        mergeSort(p, q);
        mergeSort(q + 1, r);
        printf("\n Before Merging : ");
        customDisplay(p, q);
        customDisplay(q + 1, r);
        merge(p, q, r);
        printf("\n After Merging : ");
        printArray();
    }
}

int partition(int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(i, j);
        }
    }
    swap(i + 1, r);
    printArray();
    return i + 1;
}
void QuickSort(int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(p, r);
        QuickSort(p, q - 1);
        QuickSort(q + 1, r);
    }
}

int main()
{
    int choice;

    // printf("\nEnter the elements : \n");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    do
    {

        printf("\n___________________________\n");
        printf("\n  1.Selection Sort");
        printf("\n  2.Insertion Sort");
        printf("\n  3.Merge Sort");
        printf("\n  4.Quick Sort");
        printf("\n  5.Enter new array : ");
        printf("\n___________________________");
        printf("\nEnter your option : ");

        scanf("%d", &choice);
        printf("Enter the number of elements present in the array : \n (The number should be less than 20) \n ");
        scanf("%d", &n);
        switch (choice)
        {
        case 1:
            printf("\nEnter the elements : \n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            selectionSort();
            break;

        case 2:
            printf("\nEnter the elements : \n");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            insertionSort();
            break;

        case 3:
            printf("\nEnter the elements : \n");
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("\n Initial Array : ");
            printArray();
            mergeSort(1, n);
            break;

        case 4:
            printf("\nEnter the elements : \n");
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("\n Initial Array :");
            printArray();
            QuickSort(1, n);
            break;

        case 5:
            printf("\nEnter the elements of the array : \n");

            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

        default:
            break;
        }

    } while (choice < 4);
    return 0;
}
