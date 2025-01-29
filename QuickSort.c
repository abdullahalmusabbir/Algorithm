#include<stdio.h>
quickSort(int arr[],int left,int right)
{
    if(left<right)
    {
       int j=partition(arr,left,right);
        quickSort(arr,left,j-1);
        quickSort(arr,j+1,right);
    }
}
int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left + 1;  // Incremented i to start from the next element
    int j = right;

    while (i <= j)
    {
        while (i <= right && arr[i] < pivot)
        {
            i++;
        }

        while (j >= left && arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    // Swap pivot element with arr[j]
    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    return j;
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
