#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    printf("Enter size: ");
    scanf("%d",&n);
    int M[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            M[i][j]=0;
        }
    }
    printf("Enter Edges: ");
    scanf("%d",&e);

    for(int i=0;i<e;i++)
    {
        int k,l;
        printf("Enter egdes number %d: ",i+1);
        scanf("%d%d",&k,&l);
        M[k][l]=1;
    }

    printf("Adjacency Matrix: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf(" %d",M[i][j]);
        }
        printf("\n");
    }
}
