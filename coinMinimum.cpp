#include<bits\stdc++.h>
using namespace std;

void coin (int n,int c,int w[])
{
    int dp[n+1][c+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=c;j++)
        {
            if(j==0)
            {
                dp[i][j]=0;
            }
            else if(i==0)
            {
                dp[i][j]=j;
            }
            else
            {
                if(w[i]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j],dp[i][j-w[i]]);
                }
            }
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    printf("Minimum profit: %d\n",dp[n][c]);
}

int main()
{
    int n;
    printf("Enter the item number: ");
    scanf("%d",&n);
    int w[n];
    printf("Enter the wight: ");
    for(int i=0;i<=n;i++)
        scanf("%d",&w[i]);
    int c;
    printf("Enter the capacity: ");
    scanf("%d",&c);
    coin(n,c,w);
}
