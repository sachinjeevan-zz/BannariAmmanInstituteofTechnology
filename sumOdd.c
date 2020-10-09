#include<stdio.h>
int sn(int a1,int an,int n)
{// 300
    return (n/2.0)*(a1+an);
}
int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    M = M%2==0?M+1:M+2;
    N = N%2==0?N-1:N-2;
    int n = (N-M)/2 +1;
    printf("%d",sn(M,N,n));
}