/*
There is a range given n and m in which we have to find the count all the prime pairs
whose difference is 6. We have to find how many sets are there within a given range.
Output:
Output consists of single line, print the count prime pairs in given range. Else print"No
Prime Pairs".
Constraints:
2<=n<=1000
n<=m<=2000
Sample Input:
4
30
Output:
6
*/
#include<stdio.h>
#include<stdlib.h>
int* SOE(int n)
{
    int* arr = (int*)malloc(sizeof(int)*(n+1));
    arr[0] = arr[1] = 0;
    for(int i=2;i<=n;i++)
    {
        arr[i]=1;
    }

    for(int i=2;i*i<=n;i++)
    {
        if(arr[i]==1)
        {
            for(int j=i*i;j<=n;j=j+i)
            {
                arr[j] = 0;
            }
        }
    }
    return arr;
    
}
int main()
{
    int *arr = SOE(2000);
    int t,N,M;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&N,&M);
        for(int i=N;i+6<=M;i++)
        {
            if(arr[i]==1 && arr[i+6]==1)
            {
                printf("(%d,%d) ",i,i+6);
            }
        }
        printf("\n");
    }
}