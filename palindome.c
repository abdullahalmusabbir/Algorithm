#include<stdio.h>

int main ()
{
    char s[80],t[80];
    int i,j,n,c=0;

    gets(s);

    n=strlen(s);

    i=0;
    j=n-1;
    while (j>=0)
    {
        t[i]=s[i];
        i++;
        j--;
    }
    for(i=0;i<n;i++)
    {
        if(s[i]==t[i])
        {
            c++;
        }
    }
    if(c==n)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
    return 0;
}
