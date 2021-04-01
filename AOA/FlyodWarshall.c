#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INTEGER_MAX 9999
int Adjacency_Matrix[10][10];
int a[10][10];
int Parent_matrix[10][10];

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

void printparent(int num_nodes)
{
    char parent;
    // printf("\n _______________________________________________________________________________");
    // printf("\n|               |               |               |               |               |");
    // printf("\n|   Time Slot   |     Job No.   |    Profit     |   Deadline    |  Total Profit |");
    // printf("\n|_______________|_______________|_______________|_______________|_______________|\t");
    // printf("\n|               |               |               |               |               |");
    printf("\n");
    for (int i = 0; i <= num_nodes; i++)
    {
        printf(" ____");
    }
    // printf("\n|");
    // for (int i = 0; i <= num_nodes; i++)
    // {
    //     printf("    |");
    // }
    printf("\n|    |");
    for (int i = 0; i < num_nodes; i++)
    {
        printf(" %c  |", i + 65);
    }
    printf("\n|");
    for (int i = 0; i <= num_nodes; i++)
    {
        printf("____|");
    }
    printf("\n|");
    for (int i = 0; i <= num_nodes; i++)
    {
        printf("    |");
    }

    for (int i = 1; i <= num_nodes; i++)
    {
        printf("\n| %c  |", i + 64);
        for (int j = 1; j <= num_nodes; j++)
        {
            parent = Parent_matrix[i][j];
            if (parent == -1)
            {
                parent = '-';
            }
            else
            {
                parent = parent + 64;
            }
            printf(" %c  |", parent);
        }
    }
    printf("\n|");
    for (int i = 0; i <= num_nodes; i++)
    {
        printf("____|");
    }
    printf("\n");
}

void displaypath(int source, int destination)
{
    int initialdestination = destination;
    int i = 1;
    // int sourceindex = source - 64;
    // int destinationindex = destination - 64;
    int sourceindex = source;
    int destinationindex = destination;
    int path[10];
    path[1] = destinationindex;

    while (Parent_matrix[sourceindex][destinationindex] != sourceindex)
    {
        i++;
        path[i] = Parent_matrix[sourceindex][destinationindex];
        destinationindex = Parent_matrix[sourceindex][destinationindex];
    }
    path[++i] = sourceindex;
    printf("\nThe Path from %c to %c is : ", source + 64, destination + 64);
    for (int j = i; j > 1; j--)
    {
        printf(" %c ->", path[j] + 64);
    }
    printf(" %c", destination + 64);

    printf("\nThe shortest distance for %c to %c : %d", source + 64, destination + 64, a[sourceindex][destination]);
}

int mindistbool(int i, int j, int k)
{
    // a[i][j] = mindist(a[i][j], a[i][k], a[k][j]);

    int new_distance;
    if (Adjacency_Matrix[i][k] == INTEGER_MAX || Adjacency_Matrix[k][j] == INTEGER_MAX)
    {
        return 0;
    }
    if (Adjacency_Matrix[i][k] + Adjacency_Matrix[k][j] < a[i][j])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void changeMatrix(int k, int num_nodes)
{

    for (int i = 1; i <= num_nodes; i++)
    {
        for (int j = 1; j <= num_nodes; j++)
        {
            Adjacency_Matrix[i][j] = a[i][j];
        }
        // printtable(num_nodes);
    }
}

void floydWrshl(int num_nodes)
{
    printf("\nInitial Matrix");
    printtable(num_nodes);

    for (int k = 1; k <= num_nodes; k++)
    {
        changeMatrix(k, num_nodes);
        printf("\n For Node  %c ", k + 64);
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
                printf("\n\na[%d][%d] init = %d \na[%d][%d] = %d + %d ", i, j, a[i][j], i, j, Adjacency_Matrix[i][k], Adjacency_Matrix[k][j]);
                if (mindistbool(i, j, k))
                {
                    a[i][j] = Adjacency_Matrix[i][k] + Adjacency_Matrix[k][j];
                    Parent_matrix[i][j] = Parent_matrix[k][j];
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
    char destination, source;
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
            if (edge == INTEGER_MAX || edge == 0)
            {
                Parent_matrix[i][j] = -1;
            }
            else
            {
                Parent_matrix[i][j] = i;
            }
        }
    }
    floydWrshl(num_nodes);
    printf("\n\n\nFinal Shortest distance for all pairs : ");
    printtable(num_nodes);

    printf("\n\n\nFinal Parent Matrix is : ");
    printparent(num_nodes);

    printf("\nEnter the vertices to see the path : ");
    printf("\nEnter Start Index : ");
    scanf("%d", &source);

    // scanf("%c %c", &source, &destination);
    printf("Enter Destination Index : ");
    scanf("%d", &destination);

    displaypath(source, destination);

    return 0;
}

//*inputs :

// 0 3 8 9999 -4
// 9999 0 9999 1 7
// 9999 4 0 9999 9999
// 2 9999 -5 0 9999
// 9999 9999 9999 6 0
