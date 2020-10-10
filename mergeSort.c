#include<stdio.h>
void merge(int arr[],int start,int mid,int end)
{
    int N=mid-start+1,M=end-mid;
    int L[N],R[M],k=0;
    for(int i=start;i<=mid;i++)
    {
        L[k++] = arr[i];
    }
    k=0;
    for(int i=mid+1;i<=end;i++)
    {
        R[k++] = arr[i];
    }
    int i=0,j=0;
    while(i<N && j<M)
    {
        if(L[i]<R[j])
        {
            arr[start++] = L[i++];
        }
        else
        {
            arr[start++]=R[j++];
        }
    }
    while(i<N)
    {
        arr[start++] = L[i++];
    }
    while(j<M)
    {
        arr[start++] = R[j++];
    }
    

}
void mergeSort(int arr[],int start,int end)
{
    int mid = (start+end)/2;
    if(start<end)
    {
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
void merged(int arr[],int start,int mid,int end)
{
    int N=mid-start+1,M=end-mid;
    int L[N],R[M],k=0;
    for(int i=start;i<=mid;i++)
    {
        L[k++] = arr[i];
    }
    k=0;
    for(int i=mid+1;i<=end;i++)
    {
        R[k++] = arr[i];
    }
    int i=0,j=0;
    while(i<N && j<M)
    {
        if(L[i]>R[j])
        {
            arr[start++] = L[i++];
        }
        else
        {
            arr[start++]=R[j++];
        }
    }
    while(i<N)
    {
        arr[start++] = L[i++];
    }
    while(j<M)
    {
        arr[start++] = R[j++];
    }
    

}
void mergeSortd(int arr[],int start,int end)
{
    int mid = (start+end)/2;
    if(start<end)
    {
        mergeSortd(arr,start,mid);
        mergeSortd(arr,mid+1,end);
        merged(arr,start,mid,end);
    }
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
    mergeSort(arr,0,N-1);
    mergeSortd(arr,K,N-1);
    for(int i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
    
}