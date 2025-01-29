#include<stdio.h>
int visited[5];
int DFS(int G[5][5], int v)
{
    for(int j=0; j<5; j++)
    {
        if(G[v][j]==1 && visited[j]==0)
        {
            visited[j] = 1;
            printf("%d ", j+1);
            DFS(G, j);
        }
    }
}
int main()
{
    int G[5][5] = {
        {0,1,0,0,1},
        {1,0,0,1,0},
        {0,0,0,1,1},
        {0,1,1,0,1},
        {1,1,0,1,0},
    };
    visited[0] = 1;
    printf("1 ");
    DFS(G, 0);
}
