#include <stdio.h>
#include <stdlib.h>
struct object
{
    int objNo;
    int profit;
    int weight;
    float ratio;
};

int num_objects;

void printtable(struct object objectArray[])
{

    printf("\n _______________________________________________________________");
    printf("\n|               |               |               |               |");
    printf("\n|   Object No.  |     Profit    |    Weight     |    Ratio      |");
    printf("\n|_______________|_______________|_______________|_______________|\t");
    printf("\n|               |               |               |               |");
    for (int i = 0; i < num_objects; i++)
    {
        struct object currentobj = objectArray[i];
        printf("\n|\t%d\t|\t%d\t|\t%d\t|\t%.3f\t|", currentobj.objNo, currentobj.profit, currentobj.weight, currentobj.ratio);
    }
    printf("\n|_______________|_______________|_______________|_______________|\n");
}

int main()
{
    int *arr;
    int max_weight;
    printf("\nEnter the number of objects : ");
    scanf("%d", &num_objects);
    struct object objectArray[20];
    printf("\nEnter the following details : \n");

    // todo taking inputs
    for (int i = 0; i < num_objects; i++)
    {
        objectArray[i].objNo = i + 1;
        printf("\nObject %d : \n", i + 1);
        printf("Profit : ");
        scanf("%d", &objectArray[i].profit);
        printf("Weight : ");
        scanf("%d", &objectArray[i].weight);
        objectArray[i].ratio = (float)objectArray[i].profit / objectArray[i].weight;
    }

    printf("\nEnter the maximum weight : ");
    scanf("%d", &max_weight);
    printf("\n\n\nThe ratios are : ");
    printtable(objectArray);

    // todo sorting according to ratios
    for (int i = 0; i < num_objects; i++)
    {
        int current_ratio = objectArray[i].ratio;
        for (int j = i + 1; j < num_objects; j++)
        {
            if (objectArray[j].ratio > current_ratio)
            {
                struct object tempObj = objectArray[j];
                objectArray[j] = objectArray[i];
                objectArray[i] = tempObj;
            }
        }
    }
    printf("\n\n\nThe table after sorting the ratios is : ");
    printtable(objectArray);

    arr = (int *)malloc(sizeof(int) * num_objects);
    // int arr[20];
    int i = 0;
    int total_weight = 0;
    int total_price = 0;
    printf("\n _______________________________________________________________________________________________________________");
    printf("\n|               |               |               |                  |                    |                       |");
    printf("\n|   Object No.  |     Profit    |    Weight     |      Ratio       |    Total weight    |      Total profit     |");
    printf("\n|_______________|_______________|_______________|__________________|____________________|_______________________|");
    printf("\n|               |               |               |                  |                    |                       |");
    while (i < num_objects && total_weight < max_weight)
    {
        float fract;
        struct object currentobj = objectArray[i];
        if (total_weight + currentobj.weight <= max_weight)
        {
            arr[i] = currentobj.objNo;
            total_weight += currentobj.weight;
            total_price += currentobj.profit;
            printf("\n|\t%d\t|\t%d\t|\t%d\t|\t%f   |\t    %d   \t|   \t  %d\t\t|", currentobj.objNo, currentobj.profit, currentobj.weight, currentobj.ratio, total_weight, total_price);
        }
        else
        {
            fract = (max_weight - total_weight) / (float)currentobj.weight;
            arr[i] = currentobj.objNo;
            total_weight = total_weight + (int)(currentobj.weight * fract);
            total_price = total_price + (int)(currentobj.profit * fract);
            printf("\n|\t%d\t|\t%d\t|\t%d\t|\t%f   |\t    %d   \t|   \t  %d\t\t|", currentobj.objNo, currentobj.profit, currentobj.weight, currentobj.ratio, total_weight, total_price);
            break;
        }
        i++;
    }
    printf("\n|_______________|_______________|_______________|__________________|____________________|_______________________|\n");

    printf("\nFinal Result : \n");
    printf("The objects are :\n");
    for (int j = 0; j <= i; j++)
    {
        printf("\t%d", arr[j]);
    }
    printf("\nFinal Weight : %d", total_weight);
    printf("\nFinal Profit : %d", total_price);

    return 0;
}
