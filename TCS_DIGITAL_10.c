/*
Mooshak Mouse Mooshak the mouse has been placed in a maze.There is a huge
chunk of cheese somewhere in the maze. The maze is represented as a two
dimensional array of integers, where 0 represents walls.1 repersents paths where
mooshak can move and 9 represents the huge chunk of cheese.
Mooshak starts in the top left corner at 0. Write a method is Path of class Maze Path to
determine if Mooshak can reach the huge chunk of cheese. The input to is Path
consists of a two dimensional array gnd for the maze matrix. the method should
return 1 if there is a path from Mooshak to the cheese.and 0 if not Mooshak is not
allowed to leave the maze or climb on walls.
EX: 8 by 8(8*8) matrix maze where Mooshak can get the cheese.
1 0 1 1 1 0 0 1
1 0 0 0 1 1 1 1
1 0 0 0 0 0 0 0
1 0 1 0 9 0 1 1
1 1 1 0 1 0 0 1
1 0 1 0 1 1 0 1
1 0 0 0 0 1 0 1
1 1 1 1 1 1 1 1
Input Format
The input to is Path consists of a two dimensional array size and the values for the
maze matrix
Output Format
return 1 if there is a path and 0 if not 
*/
#include<stdio.h>
#include<stdlib.h>
int isPath(int **maze, int M, int N, int i,int j)
{
    if(maze[i][j]==9)
        return 1;
    else
    {
        maze[i][j] = -1;
        if(i-1>=0 && maze[i-1][j]>0)
        {
            if(isPath(maze,M,N,i-1,j)==1)
            {
                return 1;
            }
            
            
        }
        if(j-1>=0 && maze[i][j-1]>0)
        {
            if(isPath(maze,M,N,i,j-1)==1)
             {
                return 1;
            }
        }
        if(i+1<M && maze[i+1][j]>0)
        {
            if(isPath(maze,M,N,i+1,j)==1)
             {
                return 1;
            }
        }
        if(j+1<N && maze[i][j+1]>0)
        {
            if(isPath(maze,M,N,i,j+1)==1)
             {
                return 1;
            }
        }
        maze[i][j] = 1;
    }
    
}
int main()
{
    int M,N;
    scanf("%d %d",&M,&N);
    int **mat = (int**)malloc(sizeof(int*)*M);
    for(int i=0;i<M;i++)
    {
        mat[i] = (int*)malloc(sizeof(int)*N);
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    
   if(isPath(mat,M,N,0,0)==1)
   {
       printf("YES");
   }
   else
   {
       printf("NO");
   }
   
}