#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int target,int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        if(a[mid]==target)
            return mid;
        if(a[mid]>target)
            return binarySearch(a,target,l,mid-1);
        else
            return binarySearch(a,target,mid+1,h);
    }
    return -1;
}

