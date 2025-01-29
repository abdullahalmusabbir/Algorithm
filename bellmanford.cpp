#include<bits\stdc++.h>
using namespace std;

struct Edge{
    int src,dest,weight;
};

struct Graph{
    int V,E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

int main()
{
    int V; //= 5;
    printf("Enter the Vertex number: ");
    scanf("%d",&V);

    int E; //= 8;
    printf("Enter the Edge number: ");
    scanf("%d",&E);
    struct Graph* graph = createGraph(V, E);

    for(int i=0;i<E;i++)
    {
        printf("Enter %d Edge Source:",i);
        scanf("%d",&graph->edge[i].src);

        printf("Enter %d Edge Destination :",i);
        scanf("%d",&graph->edge[i].dest);

        printf("Enter %d Edge Weight :",i);
        scanf("%d",&graph->edge[i].weight);
    }

    int dist[V];
    for(int i=0;i<V;i++)
        dist[i]=INT_MAX;
    dist[0]=0;
    for(int i=1;i<=V-1;i++)
    {
        for(int j=0;j<E;j++)
        {
            int u=graph->edge[j].src;
            int v=graph->edge[j].dest;
            int weight=graph->edge[j].weight;
            if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
                dist[v]=dist[u]+weight;
        }
    }
    for(int i=0;i<E;i++)
    {
        int u=graph->edge[i].src;
        int v=graph->edge[i].dest;
        int weight=graph->edge[i].weight;
        if(dist[u]!=INT_MAX && dist[u]+weight<dist[u])
        {
            printf("\nGraph contains negative weight cycle\n");
            break;
        }
    }
    printf("\nVertx distance from Source\n");
    for(int i=0;i<V;++i)
        printf("%d\t%d\n",i,dist[i]);
    return 0;
}
