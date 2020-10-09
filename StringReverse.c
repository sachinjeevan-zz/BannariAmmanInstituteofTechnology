#include<stdio.h>
int main()
{
    char str[1000],temp;
    scanf("%[^\n]s",str);
    int first=0,last;
    for(last=0;str[last+1]!='\0';last++);
    while(first<last)
    {
        temp = str[first];
        str[first] = str[last];
        str[last] = temp;
        first++;
        last--;
    }
    printf("%s",str);
}