/*
Bastin once had trouble finding the numbers in a string. The numbers are distributed
in a string across various test cases. There are various numbers in each test case you
need to find the number in each test case. Each test case has various numbers in
sequence. You need to find only those numbers which do not contain 9. For eg, if the
string contains "hello this is alpha 5051 and 9475".You will extract 5051 and not 9475.
You need only those numbers which are consecutive and you need to help him find
the numbers. Print the largest number.
Note: Use long long for storing the numbers from the string.
Input:
The first line consists of T test cases and next T lines contain a string.
Output:
For each string output the number stored in that string if various numbers are there print
the largest one. If a string has no numbers print -1.
Constraints:
1<=T<=100
1<=|S|<=10000
Example:
Input:
1
This is alpha 5057 and 97
Output:
5057
*/
#include<stdio.h>
int main()
{
    char str[1000];
    scanf("%[^\n]s",str);
    long long int ans=0,max=0,flag=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]!=' ')
        {
            if(str[i]>=48 && str[i]<=57)
            {
                if(str[i]=='9')
                    flag=1;
                ans = ans*10+(str[i]-48);
            }
            else
            {
                if(flag==0 &&(ans>max))
                    max = ans;
                ans = 0;
                flag=0;
            }
            
        }
    }
    if(flag==0 && ans>max)
    {
        max = ans;
    }
    printf("%lld",max);
}