#include<bits/stdc++.h>
using namespace std;

int main()
{
    int coins[] = {25,20,10,5};
    int value = 105, i,MAX=100;
    int ans[MAX];


    int size = sizeof(coins)/sizeof(coins[0]);

   int count = 0;

    for(i = 0; i < size; i++)
    {

        while(value >= coins[i])
        {

            value -= coins[i];
            ans[count] = coins[i];
            count++;
        }
        if(value == 0)
            break;

    }

    printf("Total Coins Needed = %d\n",count);

    printf("Coins are:\t");
    for(i = 0; i < count; i++)
        printf("%d ", ans[i]);

    return 0;
}
