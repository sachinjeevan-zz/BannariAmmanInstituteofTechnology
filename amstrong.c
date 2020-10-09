#include<stdio.h>
#include<math.h>
int count_digits(int N)
{
    int len=0;
    while(N!=0)
    {
        N/=10;
        len++;
    }
    return len;
}
int isAmstrong(int N)
{
    int dig = count_digits(N);
    int temp = N,rem,sum=0;
    while(temp!=0)
    {
        rem = temp%10;
        sum += pow(rem,dig);
        temp/=10;
    }
    return sum==N?1:0;
}
int main()
{
    int N;
    scanf("%d",&N);
    isAmstrong(N)==1?printf("YES"):printf("NO");
}