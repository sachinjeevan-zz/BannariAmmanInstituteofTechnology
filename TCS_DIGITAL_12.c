/*
Check if a key is present in every segment of size k in an array Given an array arr[]
and size of array is n and one another key x, and give you a segment size k. The task
is to nd that the key x present in every segment of size k in arr[].
Examples:
/
Input :
arr[] = { 3, 5, 2, 4, 9, 3, 1, 7, 3, 11, 12, 3}
x = 3
k = 3
Output : Yes
There are 4 non-overlapping segments of size k in the array, {3, 5, 2}, {4, 9, 3}, {1, 7, 3}
and {11, 12, 3}. 3 is present all segments.
Input : arr[] = { 21, 23, 56, 65, 34, 54, 76, 32, 23, 45, 21, 23, 25}
x = 23
k = 5
Output :Yes
There are three segments and last segment is not full {21, 23, 56, 65, 34}, {54, 76, 32,
23, 45} and {21, 23, 25}. 23 is present all window.
Input :
arr[] = { 5, 8, 7, 12, 14, 3, 9}
x = 8
k = 2
Output : No
Sample Input
12
3 5 2 4 9 3 1 7 3 11 12 3
3 3
Sample Output
Yes
*/
#include<stdio.h>
int kSegment(int arr[],int N,int x,int k)
{
    int i=0,flag;
    while(i<N)
    {
        flag=0;
        for(int j=i;j<N&&j<i+k;j++)
        {
            if(arr[j]==x)
                flag=1;
        }
        if(flag==0)
            return 0;
        i = i+k;
    }
    return 1;
}
int main()
{
    int N,x,k;
    scanf("%d %d %d",&N,&x,&k);
    int arr[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(kSegment(arr,N,x,k)==1)
        printf("YES");
    else
    {
        printf("NO");
    }
    

}