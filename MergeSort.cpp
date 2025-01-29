#include<bits/stdc++.h>
using namespace std;

void merges (int a[],int l,int h,int n)
{
    int n1=n-l+1;
    int n2=h-n;
    int L[n1],M[n2];
    for(int i=0;i<=n1;i++)
        L[i]=a[l+i];
    for(int j=0;j<=n2;j++)
        M[j]=a[n+1+j];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<=M[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=M[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;

    }
    while(j<n2)
    {
        a[k]=M[j];
        j++;
        k++;
    }
}

void mergeSort(int a[],int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,h);
        merges(a,l,h,m);
    }
}

int main()
{
    int n;
    printf("Enter Array Size: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter Array Element:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nGiven Arrray: ");

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    mergeSort(arr,0,n-1);
    printf("\nSorted Array: ");
    for (int i=0;i<n;i++)
    {
       printf("%d ",arr[i]);
    }
}
