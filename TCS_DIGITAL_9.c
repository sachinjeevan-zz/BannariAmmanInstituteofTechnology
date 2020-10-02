/*
Generally , In any examination the mark attached to a question is linearly related to the
time taken to solve it. Unfortunately, our universe is neither consistent not fair always ; 
and examinations bodies are no exception to this exception. One institution has designed
a question paper, where this linear relationship is thrown out of the window. As a
judicious programmer, you should help in choosing the questions that would give
maximum score to the candidate within the specified time limit.
The input to your program consists of the first line with two space separated integers.The
first one is the number of questions (n) and the second is the time limit to answer the
questions 2<=n<=20
The next line has space separated n unique integers each giving the individual (score for
the questions. The third and final line has another set of unique n integers , which gives
the time required to solve the questions . You can assume that your program should
output the maximum possible score.
Example 1:
Input
4 30
25 10 40 17
12 20 15 8
Expected output
65
Example 2
Input
3 40
34 22 16
10 30 20
Excepted output
56

*/
#include<stdio.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    int W[N],P[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&P[i]);
    }
     for(int i=0;i<N;i++)
    {
        scanf("%d",&W[i]);
    }
    int dp[N+1][K+1];
    for(int i=0;i<N+1;i++)
    {
        for(int j=0;j<K+1;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else
            {
                if(W[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                {
                    dp[i][j] = max(dp[i-1][j-W[i-1]]+P[i-1],dp[i-1][j]);
                }
                
            }
            
        }
    }
    printf("%d",dp[N][K]);
   
    
}