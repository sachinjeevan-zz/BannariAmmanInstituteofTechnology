/*
Given an Array A consisting of 0's and 1's  of length N. The goodness of a subarray is defined as difference between number of 1's  and number of 0's  present in the subarray.Output the length of longest subarray with maximum value of goodness.

Input:

The first line of Input contains Integer N.

The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of array A.

Output:

Print length of Longest subarray with maximum goodness value.

Constraints:

1 ≤ N ≤ 

0 ≤ A[i] ≤ 1

SAMPLE INPUT 
14
1 1 1 1 0 0 1 1 0 0 0 1 0 0
SAMPLE OUTPUT 
8
*/
#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]==0)
			arr[i] = -1;
	}
	int loc_max=arr[0],glob_max=arr[0];
	int orig_start=0,orig_end=0,start=0,end=0;
	for(int i=1;i<N;i++)
	{
		if(loc_max+arr[i]>=arr[i])
		{
			loc_max=loc_max+arr[i];
		}
		else
		{
			start = i;
			loc_max = arr[i];
		}
		if(loc_max>=glob_max)
		{
			orig_start = start;
			orig_end = i;
			glob_max=loc_max;
		}
	}
	printf("%d",orig_end-orig_start+1);
}