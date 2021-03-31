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

void printtable(struct node arr[], int n)
{

    printf("\n _______________________________________________");
    printf("\n|               |               |               |");
    printf("\n|     Node      |   Distance    |     Parent    |");
    printf("\n|_______________|_______________|_______________|\t");
    printf("\n|               |               |               |");
    for (int i = 1; i <= n; i++)
    {
        char parent;
        struct node currentNode = arr[i];
        parent = currentNode.parent + 64;
        if (currentNode.parent == -1)
        {
            parent = '-';
        }
        printf("\n|\t%c\t|\t%d\t|\t%c\t|", currentNode.nodeNo + 64, currentNode.distance, parent);
    }
    printf("\n|_______________|_______________|_______________|\n");
}

struct node *initialise(struct node nodearray[])
{

    for (int i = 1; i <= num_nodes; i++)
    {
        nodearray[i].nodeNo = i;
        nodearray[i].parent = -1;
        nodearray[i].distance = 9999;
        nodearray[i].status = 0;
    }
    return nodearray;
}

void blmnFord(struct node nodearray[], int num_nodes)
{
    nodearray[1].distance = 0;
    for (int i = 1; i < num_nodes; i++)
    {
        for (int sourceindex = 1; sourceindex <= num_nodes; sourceindex++)
        {
            for (int destinationindex = 1; destinationindex <= num_nodes; destinationindex++)
            {
                if (a[sourceindex][destinationindex] != 0)
                {
                    if (nodearray[destinationindex].distance > (nodearray[sourceindex].distance + a[sourceindex][destinationindex]))
                    {
                        nodearray[destinationindex].distance = nodearray[sourceindex].distance + a[sourceindex][destinationindex];
                        nodearray[destinationindex].parent = sourceindex;
                        printtable(nodearray, num_nodes);
                    }
                }
            }
        }
    }
}

int main()
{
    printf("\nSingle Source Shortest Path: Bellman-Ford Algorithm\n");
    printf("\nEnter the number of nodes : ");
    scanf("%d", &num_nodes);
    struct node *nodearray = (struct node *)malloc(sizeof(struct node) * num_nodes);
    printf("\nEnter the adjacency matrix :\n");
    for (int i = 1; i <= num_nodes; i++)
    {
        for (int j = 1; j <= num_nodes; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    nodearray = initialise(nodearray);

    // for (int i = 1; i <= num_nodes; i++)
    // {
    //     nodearray[i].nodeNo = i;
    //     nodearray[i].parent = -1;
    //     nodearray[i].distance = 9999;
    //     nodearray[i].status = 0;
    // }
    blmnFord(nodearray, num_nodes);
    return 0;
}

// ? input

// 7

// 0 6 5 5 0 0 0
// 0 0 0 0 -1 0 0
// 0 -2 0 0 1 0 0
// 0 0 -2 0 0 -1 0
// 0 0 0 0 0 0 3
// 0 0 0 0 0 0 3
// 0 0 0 0 0 0 0