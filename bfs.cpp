#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;

int visited[5];

int BFS(int G[5][5], int v)
{
    queue<int> Q;
    Q.push(v);  // push for enqueue
    visited[v] = 1;
    printf("%d ", v+1);

    while(!Q.empty())
    {
        v = Q.front(); // front to see, pop for dequeue
        Q.pop();

        for(int j=0; j<5; j++)
        {
            if(G[v][j]==1 && visited[j]==0)
            {
                Q.push(j);
                printf("%d ", j+1);
                visited[j] = 1;
            }
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

    BFS(G, 0);
}
