#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int source;
    int dest;
    int weight;
};
typedef struct node node;
void printArray(node *graph, int e)
{
    int i;
    printf("\n _______________________________________________");
    printf("\n|               |               |               |");
    printf("\n|     Source    |  Destination  |    Weight     |");
    printf("\n|_______________|_______________|_______________|\t");
    printf("\n|               |               |               |");

    for (i = 1; i <= e; i++)
    {
        printf("\n|\t%d\t|\t%d\t|\t%d\t| ", graph[i].source, graph[i].dest, graph[i].weight);
    }
    printf("\n|_______________|_______________|_______________|\n");
}
struct node *insertionSort(node *graph, int e)
{
    struct node temp;
    for (int i = 1; i <= e; i++)
    {
        temp = graph[i];
        int j = i - 1;
        while (j > 0 && temp.weight <= graph[j].weight)
        {
            graph[j + 1] = graph[j];
            j -= 1;
        }
        graph[j + 1] = temp;
    }
    printf("\nAfter sorting the edges : ");
    printArray(graph, e);
    return graph;
}
int findset(int x, int parent[])
{
    // printf("\nIn findset %d",x);
    if (x != parent[x])
    {
        return findset(parent[x], parent);
    }
    return parent[x];
}
void link(int x, int y, int parent[], int rank[])
{
    // printf("\nInserting edge from %d to %d", x, y);
    if (rank[x] > rank[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
    }
    if (rank[x] == rank[y])
    {
        rank[y] += 1;
    }
}
void kruskals(node *graph, node *output, int v, int e)
{
    // printf("\nIn kruskals e=%d v=%d",v,e);
    // printf("\nIn kruskals2");
    int parent[v], rank[v], count = 1;
    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    for (int i = 1; i <= e; i++)
    {
        //  printf("\nin for");
        int u, v;
        u = graph[i].source;
        v = graph[i].dest;
        printf("\nFor edge %d to %d",u,v);
        if (findset(u, parent) != findset(v, parent))
        {
            link(findset(u, parent), findset(v, parent), parent, rank);
            output[count] = graph[i];
            count++;
        }
        printArray(output, count - 1);
    }
    printf("\nFinal Output ");
    printArray(output, count - 1);
}
int main()
{
    int v, e;
    printf("\n KRUSKAL'S MINIMUM COST SPANNING TREE\n");

    printf("\nEnter the no of vertices : ");
    scanf("%d", &v);
    printf("\nEnter the no of edges : ");
    scanf("%d", &e);
    node *graph = malloc(e * sizeof(node));
    node *output = malloc(e * sizeof(node));
    // printf("\nEnter the nodes which are to be connected along with their weights");
    for (int i = 1; i <= e; i++)
    {
        printf("\nFor Edge %d : \n", i);
        printf("Enter the Vertex 1 : ");
        scanf("%d", &graph[i].source);
        printf("Enter the Vertex 2 : ");
        scanf("%d", &graph[i].dest);
        printf("Enter the weight of the vertex : ");
        scanf("%d", &graph[i].weight);
        // printf("Enter the source, destination, weight of the node : ");
        // scanf("%d %d %d", &graph[i].source, &graph[i].source, &graph[i].weight);
    }
    printArray(graph, e);
    graph = insertionSort(graph, e);
    kruskals(graph, output, v, e);
}

//?Input :
// 9
// 14
// 1 
// 2
// 4
// 2
// 3
// 8
// 3 
// 4
// 7
// 4
// 5
// 9
// 5
// 6
// 10
// 6 
// 4
// 14
// 6
// 3
// 4
// 6
// 7
// 2
// 7
// 9
// 6
// 7
// 8
// 1
// 8
// 9
// 7
// 8
// 2
// 11
// 8 
// 1 
// 8
// 9
// 3
// 2