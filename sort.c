#include<stdio.h>
int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    int arr[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    qsort(arr,N,sizeof(int),cmpfunc);
    for(int i=0;i<K;i++)
        printf("%d ",arr[i]);
    for(int i=N-1;i>=K;i--)
        printf("%d ",arr[i]);
}
