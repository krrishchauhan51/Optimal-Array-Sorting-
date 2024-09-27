#include<stdio.h>
#include<stdbool.h>
int bubbleSortSwaps(int arr[],int n,bool ascending)


{
    int swaps =0;
    int temp;
    bool swapped;
    for(int i=0;i<n-1;i++)
    {
        swapped=false;
        for (int j=0;j<n-1;j++)
        {
            if(ascending)
            {
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    swaps++;
                    swapped=true;

                }
            }
            else
            {
                if (arr[j] < arr[j+1])
                {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swaps++;
                    swapped=true;

                }
            }
        }
        if(!swapped)
        {
            break;
        }
    }
    return swaps;   
}
int main() 
{
    int n;
   printf( "enter size of the array : ");
   scanf("%d",&n);
   if(n>1000)
    {
       printf("please enter a smaller array.\n ");
        return 1;
    }
    int arr[n],arrCopy[n];
    printf("enter elements of the array : ");
    for(int i = 0;i < n; i++)
    {
        scanf("%d", &arr[i] );
        arrCopy[i] = arr[i];
    }
    int ascendingSwaps = bubbleSortSwaps(arr,n,true);
    for(int i =0 ; i < n;i++)
    {
        arr[i] = arrCopy[i];
    }
 int descendingSwaps = bubbleSortSwaps (arr, n,false);
 if(ascendingSwaps < descendingSwaps )
 {
    printf("Sorted the array in ascending order with %d swaps.\n",ascendingSwaps);
 }
 else
{
    printf("Sorted the array in descending order with %d swaps.\n",descendingSwaps);
}

 printf("Sorted array: ");
 for(int i = 0; i< n; i++)
 { 
    printf("%d ", arr[i]);
 }
 printf("\n");
 return 0;
}