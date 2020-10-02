/*
Up and Down Sequences
From the sequence 1 3 1 4 5 2 we can extract the subsequences 1 4 5 2, 1 3 2 and 3 4 2.
These lists are called “up and down sequences” , as all the numbers to left of the
maximum value (the up part) are in strictly ascending order , and those to the right of the
maximum are in descending order (the down part).Note that there must be at least one
number to the left of the maximum value(the up part) and at least one number to the right
of the subsequences(the down part).
A maximal up and down subsequences is one with the maximal length. Note that there 
may be more than one maximal up and down subsequences in a given sequences .In the
sequence 1 4 3 6 2 1 , the two subsequences 1 4 3 2 1 and 1 4 6 2 1 are both maximal up
and down subsequences .
A maximal subsequences like 1 4 3 2 1 may have up and down subsequences of its own
which have the same maximum value (4). These are 1 4 3; 1 4 2; 1 4 3 2; 1 4 3 1; 1 4 2 1;
and 1 4 3 2 1 (a total of 7 ).This includes the full subsequences also.
A similar enumeration shows that 1 4 6 2 1 has 9 up and down subsequences that have 6
as the maximum value.
Given a list of numbers, write a program to count the number of up and down
subsequences with the same maximum value that could be formed from any one maximal
subsequences .
Input
The first line contains the number of integers in the sequences (N)
The second line contains the N integer (not necessarily positive , and not necessarily
distinct) delimited by commas
Output
One integer representing the total number of up and down sequences that could be
formed from the given sequence.
Constraints
The number of integers in the input sequences < 30.
Example 1
Input
4
-1,2,3,4
Output
0
Explanation
There are 4 integers in the input (N==4). The numbers in the sequences are -1,2,3 and 4.
The sequences is in the increasing order and hence cannot have a “down” part
Of the sequences. As there is no maximal up and down subsequences the result is 0.
Example 2
Input
5
1 5 4 3 2
Output
7
Explanation
N=5
The maximal up and down sequences is 1 5 4 3 2.This has 7 up and down sequences with
the maximal element 5 (the same as the maximal subsequences).There are
1,5,4,3,2;1,5,4;1,5,3;
1,5,2;1,5,4,3;1,5,4,2;1,5,3,2
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int N;
    scanf("%d",&N);
    int arr[N],rev[N],up[N],down[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
        rev[N-i-1] = arr[i];
        up[i] = down[i] = 1;
    }
    int i = 1,j=0;
    while(i<N)
    {
        while(j<i)
        {
            if(arr[i]>arr[j])
            {
                if(up[j]+1>up[i])
                    up[i] = up[j]+1;
            }
            if(rev[i]>rev[j])
            {
                if(down[j]+1>down[i])
                    down[i] = down[j]+1;
            }
            j++;
        }
        i++;
        j=0;
    }
    int max = 0,ans;
    for(int i=1;i<N-1;i++)
    {
        int l = up[i]-1;
        int r = down[N-i-1]-1;
        if(l>0 && r>0)
        {
            ans = (pow(2,l)-1)*(pow(2,r)-1);
            if(ans>max)
                max = ans;
        }
    }
    printf("%d",max);
}