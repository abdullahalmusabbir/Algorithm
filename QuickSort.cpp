#include<bits/stdc++.h>
using namespace std;

int partitions(int a[],int l,int h)
{
    int pivot=a[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[h]);
    return i+1;
}

void quickSort(int a[],int l,int h)
{
    if(l<h)
    {
        int pi=partitions(a,l,h);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,h);
    }
}

int main ()
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
    quickSort(arr,0,n-1);
    printf("\nSorted Array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }


}
