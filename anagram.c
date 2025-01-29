#include<stdio.h>
#include<string.h>

int main ()
{
    char s[80],t[80];
    char temp;
    int n,m,i,j;

    gets(s);
    gets(t);

    n=strlen(s);
    m=strlen(t);

    if(n!=m)
    {
        printf("Not anagram\n");
        return 0;
    }

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(s[i]>s[j])
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
            if (t[i]>t[j])
            {
                temp=t[i];
                t[i]=t[j];
                t[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(s[i]!= t[i])
        {
            printf("String are not a anagram\n",s,t);
            return 0;
        }
    }
    printf("String is anagram\n");
    return 0;
}

