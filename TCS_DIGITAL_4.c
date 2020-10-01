/*
Write a program to print all the combinations of the given word with or without
meaning (when unique characters are given).
Sample Input:
abc
Output:
abc
acb
bac
bca
cba
cab
*/
#include<stdio.h>
#include<string.h>
int isSafe(char ans[],int layer,char ch)
{
    for(int i=0;i<layer;i++)
    {
        if(ans[i]==ch)
            return 0;
    }
    return 1;
}
void solve(char str[],char ans[],int n,int layer)
{
    if(layer!=n)
    {
        for(int i=0;i<n;i++)
        {
            if(isSafe(ans,layer,str[i])==1)
            {
                ans[layer] = str[i];
                solve(str,ans,n,layer+1);
            }
        }
    }
    else
    {
        ans[layer]='\0';
        printf("%s\n",ans);
    }
    
}
int main()
{
    char str[1000],ans[1000];
    scanf("%s",str);
    int n = strlen(str);
    solve(str,ans,n,0);
}