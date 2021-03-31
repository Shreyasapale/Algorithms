#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int nodeNo;
    int distance;
    int parent;
    int status;
};
int a[10][10];
int solution[10];
int num_nodes;

void printProcess(struct node nodeArray[], int num_nodes)
{
    struct node currentNode;

    printf("\n _______________________________________________________________");
    printf("\n|               |               |               |               |");
    printf("\n|   Node No.    |     Key       |    Parent     |   Status      |");
    printf("\n|_______________|_______________|_______________|_______________|\t");
    printf("\n|               |               |               |               |");
    for (int i = 1; i <= num_nodes; i++)
    {
        currentNode = nodeArray[i];
        printf("\n|\t%d\t|\t%d\t|\t%d\t|\t%d\t|", currentNode.nodeNo, currentNode.distance, currentNode.parent, currentNode.status);
    }
    printf("\n|_______________|_______________|_______________|_______________|\n");
}

int extractmin(struct node nodearray[])
{
    int min = 1;
    int flag = 0;
    for (int i = 1; i <= num_nodes; i++)
    {
        if (nodearray[i].parent != -1)
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= num_nodes; i++)
        {
            if (nodearray[i].status != 1)
            {
                if (min == 1)
                    min = i;
                else if (nodearray[min].distance > nodearray[i].distance)
                {
                    min = i;
                }
            }
        }
        return min;
    }
}
int isnotEmpty(struct node nodearray[], int num_nodes)
{
    for (int i = 1; i <= num_nodes; i++)
    {
        if (nodearray[i].status == 0)
        {
            return 1;
        }
    }
    return 0;
    // * if queue is empty 0 is returned else 1 is returned
}

int checkElem(struct node nodearray[], int elem, int num_nodes)
{
    for (int i = 1; i <= num_nodes; i++)
    {
        if (nodearray[i].nodeNo == elem && nodearray[i].status == 0)
        {
            return 1;
        }
    }
    return 0;
    // * if queue contains that element 1 is returned else 0 is returned
}

void PrimsMST(struct node nodearray[], int num_nodes)
{
    // printf("\nI am here in prims");
    printProcess(nodearray, num_nodes);

    nodearray[1].distance = 0;

    while (isnotEmpty(nodearray, num_nodes))
    {
        int currentNodeNo = extractmin(nodearray);
        printf("\n");
        printf("\n\nNODE %d : ", currentNodeNo);
        for (int j = 1; j <= num_nodes; j++)
        {
            if (a[currentNodeNo][j] != 0)
            {
                printf("\n");
                printf("\nPath %d to %d ", currentNodeNo, j);
                if (checkElem(nodearray, j, num_nodes) && a[currentNodeNo][j] < nodearray[j].distance)
                {
                    printf("\nFor %d : ", j);
                    printf("\nInitial distance : %d \n ", nodearray[j].distance);
                    nodearray[j].distance = a[currentNodeNo][j];
                    nodearray[j].parent = currentNodeNo;
                    printf("New Distance = %d \nParent = %d", nodearray[j].distance, currentNodeNo);
                }

                // else
                // {
                //     printf("\nThere is no change :\nDistance : %d \nParent is %d", nodearray[j].distance, nodearray[j].parent);
                // }
            }
            // printProcess(nodearray, num_nodes);
        }

        nodearray[currentNodeNo].status = 1;
        printProcess(nodearray, num_nodes);

        // printf("\n %d is the status so %d node is done ", nodearray[currentNodeNo].status);
    }

    // printf("\n\nFinal Shortest Distance for : ");
    // for (int i = 1; i <= num_nodes; i++)
    // {
    //     printf("\n %d  : %d", i, nodearray[i].distance);
    // }
}

int main()
{
    printf("\nPRIM'S MINIMUM COST SPANNING TREE\n");

    printf("\nEnter the number of nodes : ");
    scanf("%d", &num_nodes);
    struct node *nodearray = (struct node *)malloc(sizeof(struct node) * num_nodes);
    printf("\nEnter the adjacency matrix :\n");
    for (int i = 1; i <= num_nodes; i++)
    {
        for (int j = 1; j <= num_nodes; j++)
        {
            scanf("%d", &a[i][j]);
            // printf(" %d", a[i][j]);
        }
    }

    for (int i = 1; i <= num_nodes; i++)
    {
        nodearray[i].nodeNo = i;
        nodearray[i].parent = -1;
        nodearray[i].distance = 9999;
        nodearray[i].status = 0;
    }

    // printf("\nThis the info :  ");
    // for (int i = 1; i <= num_nodes; i++)
    // {
    //     printf("\n  %d\t%d\t%d\t%d", nodearray[i].nodeNo, nodearray[i].parent, nodearray[i].distance, nodearray[i].status = 0);
    // }
    PrimsMST(nodearray, num_nodes);
    return 0;
}

//*inputs :


//9

//  0 4 0 0 0 0 0 8 0
//  4 0 8 0 0 0 0 11 0
//  0 8 0 7 0 4 0 0 2
//  0 0 7 0 9 14 0 0 0
//  0 0 0 9 0 10 0 0 0
//  0 0 4 14 10 0 2 0 0
//  0 0 0 0 0 2 0 1 6
//  8 11 0 0 0 0 1 0 7
//  0 0 2 0 0 0 0 7 0
