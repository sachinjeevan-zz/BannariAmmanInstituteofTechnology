/*
Maximum size square sub-matrix with all 1s
Only allowed to code in C/C++/Java
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
For example, consider the below binary matrix
*/
#include<stdio.h>
int min(int a,int b,int c)
{
    return (a<b&&a<c)?a:b<c?b:c;
}
int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    int mat[M][N];
    int dp[M][N],max=0;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&mat[i][j]);
            if(i==0 || j==0)
                dp[i][j] = mat[i][j];
            else
            {
                if(mat[i][j]==1)
                    dp[i][j] = min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]) + 1;
                else
                    dp[i][j] = 0;
            }
            if(dp[i][j]>max)
                max = dp[i][j];
            
        }
    }
    printf("%d",max);

}