#include <stdio.h>
#include <conio.h>
#include <math.h>
#define INT_MAX 9999
int Adjacency_Matrix[10][10];
int a[10][10];
int Parent_matrix[10][10];

// int extractmin(struct node nodearray[])
// {
//     int min = 0;
//     int flag = 0;
//     for (int i = 1; i <= num_nodes; i++)
//     {
//         if (nodearray[i].parent != -1)
//         {
//             flag = 1;
//         }
//     }
//     if (flag == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         for (int i = 2; i <= num_nodes; i++)
//         {
//             if (nodearray[i].parent != -1 && nodearray[i].status == 0)
//             {
//                 if (min == 0)
//                     min = i;
//                 else if (nodearray[min].distance > nodearray[i].distance)
//                 {
//                     min = i;
//                 }
//             }
//         }
//         return min;
//     }
// }
// void dijshortest(struct node nodearray[])
// {

//     nodearray[1].distance = 0;
//     for (int i = 1; i <= num_nodes; i++)
//     {
//         int u = extractmin(nodearray);
//         printf("\n");
//         printf("\n\nNODE %d : ", u);
//         solution[i] = u;
//         for (int j = 1; j <= num_nodes; j++)
//         {
//             if (a[u][j] != 0)
//             {
//                 printf("\n");
//                 printf("\nPath %d to %d ", u, j);
//                 if (nodearray[j].distance > (nodearray[u].distance + a[u][j]))
//                 {
//                     printf("\nFor %d : ", j);
//                     printf("\nInitial distance : %d \n ", nodearray[j].distance);
//                     nodearray[j].distance = nodearray[u].distance + a[u][j];
//                     nodearray[j].parent = u;
//                     printf("New Distance = %d \nParent = %d", nodearray[j].distance, u);
//                 }
//                 else
//                 {
//                     printf("\nThere is no change :\nDistance : %d \nParent is %d", nodearray[j].distance, nodearray[j].parent);
//                 }
//             }
//         }
//         nodearray[u].status = 1;
//     }
//     printf("\n\nFinal Shortest Distance for : ");
//     for (int i = 1; i <= num_nodes; i++)
//     {
//         printf("\n %d  : %d", i, nodearray[i].distance);
//     }
//     printf("\n");
//     printf("\nQueue S : ");
//     for (int i = 1; i <= num_nodes; i++)
//     {
//         printf(" %d ", solution[i]);
//     }
// }

void printtable(int num_nodes)
{
    // printf("\n _______________________________________________________________________________");
    // printf("\n|               |               |               |               |               |");
    // printf("\n|   Time Slot   |     Job No.   |    Profit     |   Deadline    |  Total Profit |");
    // printf("\n|_______________|_______________|_______________|_______________|_______________|\t");
    // printf("\n|               |               |               |               |               |");
    printf("\n");
    for (int i = 0; i <= num_nodes; i++)
    {
        printf(" _______");
    }
    printf("\n|");
    for (int i = 0; i <= num_nodes; i++)
    {
        printf("       |");
    }
    printf("\n|       |");
    for (int i = 0; i < num_nodes; i++)
    {
        printf("   %c   |", i + 65);
    }
    printf("\n|");
    for (int i = 0; i <= num_nodes; i++)
    {
        printf("_______|");
    }
    printf("\n|");
    for (int i = 0; i <= num_nodes; i++)
    {
        printf("       |");
    }

    for (int i = 1; i <= num_nodes; i++)
    {
        printf("\n|   %c   |", i + 64);
        for (int j = 1; j <= num_nodes; j++)
        {
            printf(" %4d  |", a[i][j]);
        }
    }
    printf("\n|");
    for (int i = 0; i <= num_nodes; i++)
    {
        printf("_______|");
    }
}

int mindist(int initial, int new1, int new2)
{
    int new_distance;
    if (new1 == INT_MAX || new2 == INT_MAX)
    {
        return initial;
    }
    new_distance = new1 + new2;
    if (new_distance < initial)
    {
        return new_distance;
    }
    else
    {
        return initial;
    }
}
int mindistbool(int i, int j, int k)
{
    // a[i][j] = mindist(a[i][j], a[i][k], a[k][j]);

    int new_distance;
    if (a[i][k] == INT_MAX || a[k][j] == INT_MAX)
    {
        return 0;
    }
    if (a[i][k] + a[k][j] < a[i][j])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void floydWrshl(int num_nodes)
{
    for (int i = 1; i < num_nodes; i++)
    {
        for (int j = 1; j < num_nodes; j++)
        {
            if (i == j)
            {
                a[i][j] = 0;
            }
        }
        // printtable(num_nodes);
    }
    printf("\nInitial Matrix");
    printtable(num_nodes);

    for (int k = 1; k <= num_nodes; k++)
    {
        for (int i = 1; i <= num_nodes; i++)
        {
            if (i == k)
            {
                // printf("\nI == K , i = %d , k = %d  SKIP", i, k);
                continue;
            }
            for (int j = 1; j <= num_nodes; j++)
            {
                if (j == k)
                {
                    // printf("\nJ == K , j = %d , k = %d SKIP", j, k);

                    continue;
                }
                if (i == j || i == k || j == k)
                {
                    // printf("\nI == J , i = %d , j = %d SKIP", i, j);

                    continue;
                }
                // a[i][j] = mindist(a[i][j], a[i][k], a[k][j]);
                printf("\n\na[%d][%d] = %d \na[%d][%d] = %d + %d = %d", i, j, a[i][j], i, j, a[i][k], a[k][j], a[i][k] + a[k][j]);
                if (mindistbool(i, j, k))
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
                printf("\n a[%d][%d] = %d", i, j, a[i][j]);
            }
        }
        printtable(num_nodes);
    }
}
int main()
{
    int num_nodes;
    printf("\nAll pair shortest path: Floyd Warshall Algorithm\n");
    printf("\nEnter the number of Vertices : ");
    scanf("%d", &num_nodes);

    //todo inputs
    printf("\nEnter the adjacency matrix :\n");
    for (int i = 1; i <= num_nodes; i++)
    {
        for (int j = 1; j <= num_nodes; j++)
        {
            int edge;
            scanf("%d", &edge);
            a[i][j] = edge;
            Adjacency_Matrix[i][j] = edge;
        }
    }
    floydWrshl(num_nodes);
    printf("\n\n\nFinal Shortest paths for all pairs : ");
    printtable(num_nodes);

    return 0;
}

//*inputs :

// 0 3 8 9999 -4
// 9999 0 9999 1 7
// 9999 4 0 9999 9999
// 2 9999 -5 0 9999
// 9999 9999 9999 6 0
