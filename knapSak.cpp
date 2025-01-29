#include<bits\stdc++.h>
using namespace std;

void knapsack(int n,int c,int w[],int v[])
{
    int dp[n+1][c+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=c;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else
            {
                if(w[i-1]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]]);
                }
            }
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("Maximum profit: %d\n",dp[n][c]);
}

int main()
{
    int n;
    printf("Enter the item number: ");
    scanf("%d",&n);
    int w[n],v[n];
    printf("Enter the weight: ");
    for(int i=0;i<=n;i++)
        scanf("%d",&w[i]);
    printf("Enter the value: ");
    for(int i=0;i<=n;i++)
        scanf("%d",&v[i]);
    int c;
    printf("Enter the capacity: ");
    scanf("%d",&c);
    knapsack(n,c,w,v);
}
