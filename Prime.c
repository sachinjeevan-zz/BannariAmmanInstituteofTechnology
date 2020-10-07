/*
Write a program that will find the sum of all prime no. in a given range. 
The range will be specied. The first line contains, N1 which is a positive integer, 
will contain the lower bound of the range. The second line N2, which is also a 
positive integer, will contain the upper bound of the range. The program should 
consider all the prime no. within the range, excluding the upper and lower bound 
in the output in integer format to stdout. Other than the integer number ,
no other extra information should be printed to stdout. 

Example: input “7” and “24”, here N1=7 and N2=34, expected output is 83 
Sample Input Sample Output 
7 24             83 

*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int isPrime(int N)
{
    if(N<=1)
        return 0;
    if(N>=4 && (N%2==0 || N%3==0))
        return 0;
    int k=1;
    int a=6*k-1,b=6*k+1;
    while(a<=sqrt(N) || b<=sqrt(N))
    {
        if(N%a==0 || N%b==0)
            return 0;
        k++;
        a = 6*k-1;
        b = 6*k+1;
    }
    return 1;
}
int* SOE(int N)
{
    int* arr = (int*)malloc(sizeof(int)*(N+1));
    arr[0]=arr[1]=0;
    for(int i=2;i<=N;i++)
        arr[i] = i;
    for(int i=2;i*i<=N;i++)
    {
        if(arr[i]!=0)
        {
            for(int j=i*i;j<=N;j+=i)
                arr[j]=0;
        }
    }
    for(int i=2;i<=N;i++)
    {
        arr[i]=arr[i-1]+arr[i];
    }
    return arr;
}
int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    int* arr = SOE(100000);
    M++;
    N--;
    printf("%d",arr[N]-arr[M-1]);
}