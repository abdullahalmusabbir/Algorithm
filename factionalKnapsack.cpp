#include<bits/stdc++.h>
using namespace std;
struct item {
    int value;
    int weight;
};
bool compare(item a, item b)
{
    double ratio1 = double(a.value/a.weight);
    double ratio2 = double (b.value/ b.weight);
    return ratio1>ratio2;
}
double fractionalknapsack (item items[], int n, int capacity)
{
    sort(items, items+n, compare);
  double profitcounting = 0;
    int weightcounting = 0;
    for(int i=0;i<n;i++)
    {
        if(weightcounting + items[i].weight <= capacity)
        {
            profitcounting += items[i].value;
             weightcounting+= items[i].weight;
        }
        else
        {
          double remainingweight  = capacity - weightcounting;
            profitcounting += items[i].value * (double)(remainingweight/items[i].weight);
            break;
        }
    }
    return profitcounting;
}
int main()
{
    int n,capacity;
    cout<<"how many number's of item: "<<endl;
    cin>>n;
    item items[n];
    cout<<"ENter Item's value and weight: "<<endl;
    for(int i =0;i<n;i++)
    {
       cin>> items[i].value>>items[i].weight;
    }
    cout<<"Enter Max capacity: ";
    cin>>capacity;
    double max_profit = fractionalknapsack(items,n,capacity);
    cout<<"Max Profit: "<< max_profit<<endl;
}
