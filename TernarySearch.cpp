#inlcude<bits/stdc++.h>
using namespace std;

int tarnarySearch(int a[],int target,int l,int h)
{
    if(l<h)
    {
        int mid1=l+(h-l)/3;
        int mid2=h-(h-l)/3;
        if(a[mid1]==target)
            return mid1;
        if(a[mid2]==target)
            return mid2;
        if(a[mid1]>target)
            return tarnarySearch(a,target,l,mid1-1);
        else if(a[mid2]<target)
            return tarnarySearch(a,target,mid2+1,h);
        else
            return tarnarySearch(a,target,mid1+1,mid2-1);
    }
    return -1;
}
