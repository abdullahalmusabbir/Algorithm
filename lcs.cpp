#include<bits\stdc++.h>
using namespace std;

int main()
{
    char s1[]="ABCB",s2[]="BDCAB",res[10];
    int m,n,i,j;
    m=strlen(s1);
    n=strlen(s2);
    int lcs[m+1][n+1];
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                lcs[i][j]=0;
            }
            else
            {
                if(s1[i-1]==s2[j-1])
                {
                    lcs[i][j]=lcs[i-1][j-1]+1;
                }
                else if(lcs[i-1][j]>lcs[i][j-1])
                {
                    lcs[i][j]=lcs[i-1][j];
                }
                else
                {
                    lcs[i][j]=lcs[i][j-1];
                }
            }
            printf("%d ",lcs[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",lcs[m][n]);

    i=m,j=n;
    int idx=lcs[m][n];
    res[idx]='\0';
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            res[idx-1]=s1[i-1];
            i--;
            j--;
            idx--;
        }
        else if(lcs[i-1][j]>lcs[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    printf("%s\n",s1);
    printf("%s\n",s2);
    printf("%s\n",res);
}
