/*
Write a program to find the count of numbers which consists of unique digits.
Input:
Input consist of two Integer lower and upper value of an range
Output:
Output consists of single line, print the count of unique digits in given range. Else
Print"No Unique Number"
*/
#include<stdio.h>
// check for whether a number consist of unique digits or not
int uniqueDigits_method1(int num)
{
    int hash[10] = {0};
    while(num!=0)
    {
        int rem  = num%10;
        if(hash[rem]==1)
            return 0;
        hash[rem] = 1;
        num=num/10;
    }
    return 1;
}
int uniqueDigits_method2(int num)
{
    short int x=0,y;
    while(num!=0)
    {
        int k = num%10;
        y = 1 << k;
        if((x&y)!=0)
            return 0;
        x = x|y;
        num=num/10;
    }
    return 1;
}
int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int count = 0;
    for(int i=N;i<=M;i++)
    {
        if(uniqueDigits_method2(i))
            count++;
    }
    printf("%d",count);
}