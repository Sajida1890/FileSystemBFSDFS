
#include <stdio.h>
#include <string.h>

#define MAX 100

int graph[MAX][MAX];
char names[MAX][50];
int n;

// BFS function
void BFS(int start, char target[])
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int found = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];

        printf("%s ", names[current]);

        if (strcmp(names[current], target) == 0)
            found = 1;

        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    if (found)
        printf("\nFile found using BFS!\n");
    else
        printf("\nFile not found using BFS!\n");
}

// DFS function
void DFS(int current, int visited[],
         char target[], int *found)
{
    visited[current] = 1;

    printf("%s ", names[current]);

    if (strcmp(names[current], target) == 0)
        *found = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[current][i] == 1 && !visited[i])
        {
            DFS(i, visited, target, found);
        }
    }
}

int main()
{
    int start;
    int visited[MAX] = {0};
    int found = 0;
    char target[50];

    printf("FILE SYSTEM USING BFS AND DFS\n");

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    printf("\nEnter node names:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Node %d: ", i);
        scanf(" %49[^\n]", names[i]);
    }

    printf("\nEnter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter starting node number: ");
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting node!\n");
        return 1;
    }

    printf("Enter file name to search: ");
    scanf(" %49[^\n]", target);

    // Perform BFS
    BFS(start, target);

    // Perform DFS
    printf("\nDFS Traversal: ");

    DFS(start, visited, target, &found);

    if (found)
        printf("\nFile found using DFS!\n");
    else
        printf("\nFile not found using DFS!\n");

    return 0;
}
