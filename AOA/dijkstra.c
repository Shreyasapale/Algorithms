#include <stdio.h>
#include <conio.h>
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
int extractmin(struct node nodearray[])
{
    int min = 0;
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
        for (int i = 2; i <= num_nodes; i++)
        {
            if (nodearray[i].parent != -1 && nodearray[i].status == 0)
            {
                if (min == 0)
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
void dijshortest(struct node nodearray[])
{

    nodearray[1].distance = 0;
    for (int i = 1; i <= num_nodes; i++)
    {
        int u = extractmin(nodearray);
        printf("\n");
        printf("\n\nNODE %d : ", u);
        solution[i] = u;
        for (int j = 1; j <= num_nodes; j++)
        {
            if (a[u][j] != 0)
            {
                printf("\n");
                printf("\nPath %d to %d ", u, j);
                if (nodearray[j].distance > (nodearray[u].distance + a[u][j]))
                {
                    printf("\nFor %d : ", j);
                    printf("\nInitial distance : %d \n ", nodearray[j].distance);
                    nodearray[j].distance = nodearray[u].distance + a[u][j];
                    nodearray[j].parent = u;
                    printf("New Distance = %d \nParent = %d", nodearray[j].distance, u);
                }
                else
                {
                    printf("\nThere is no change :\nDistance : %d \nParent is %d", nodearray[j].distance, nodearray[j].parent);
                }
            }
        }
        nodearray[u].status = 1;
    }
    printf("\n\nFinal Shortest Distance for : ");
    for (int i = 1; i <= num_nodes; i++)
    {
        printf("\n %d  : %d", i, nodearray[i].distance);
    }
    printf("\n");
    printf("\nQueue S : ");
    for (int i = 1; i <= num_nodes; i++)
    {
        printf(" %d ", solution[i]);
    }
}
// struct node* initialise(struct node nodearray[])
// {

//     for (int i = 1; i <= num_nodes; i++)
//     {
//         nodearray[i].nodeNo = i;
//         nodearray[i].parent = -1;
//         nodearray[i].distance = 9999;
//         nodearray[i].status = 0;
//     }
//     return nodearray;
// }
int main()
{
    printf("\n\Single source shortest path: Dijkstra Algorithmn");
    struct node nodearray[10];
    printf("\nEnter the number of nodes : ");
    scanf("%d", &num_nodes);
    printf("\nEnter the adjacency matrix :\n");
    for (int i = 1; i <= num_nodes; i++)
    {
        for (int j = 1; j <= num_nodes; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 1; i <= num_nodes; i++)
    {
        nodearray[i].nodeNo = i;
        nodearray[i].parent = -1;
        nodearray[i].distance = 9999;
        nodearray[i].status = 0;
    }
    dijshortest(nodearray);
    return 0;
}

//*inputs :
//    1   2   3   4   5
// 1
// 2
// 3
// 4
// 5

// 0 10 5 0 0
// 0 0 2 1 0
// 0 3 0 9 2
// 0 0 0 0 4
// 7 0 0 6 0
