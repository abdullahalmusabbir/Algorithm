#include<bits/stdc++.h>
using namespace std;

int main()
{
    int V,INF=9999999;
    printf("Enter the Vertex number: ");
    scanf("%d",&V);
    int G[V][V]={
        {0,9,75,0,0},
        {9,0,95,19,42},
        {75,95,0,51,66},
        {0,19,51,0,31},
        {0,42,66,31,0}};
    int no_edge;
    int selected[V];
    memset(selected,false,sizeof(selected));
    no_edge=0;
    selected[0]=true;
    int x;
    int y;
    printf("Edge \n:\nWeight \n");
    while(no_edge<V-1)
    {
        int mins=INF;
        x=0;
        y=0;
        for(int i=0;i<V;i++)
        {
            if(selected[i])
            {
                for(int j=0;j<V;j++)
                {
                    if(!selected[j] && G[i][j])
                    {
                        if(mins>G[i][j])
                        {
                            mins=G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n",x,y,G[x][y]);
        selected[y]=true;
        no_edge++;
    }
}
