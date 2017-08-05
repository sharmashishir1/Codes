#include<stdlib.h>
#include<string.h>

void reverse(int * arr, int start, int end, int * i)
{
    if(start==end)
        return;
    int temp=arr[start];
    int index=*i;
    reverse(arr,start+1,end,&index);
    //printf("%d", index);
    arr[index]=temp;
    *i=index+1;;
}

int checkpalindrome(char *str)
{
    int length=strlen(str);
    int begin=0;
    int end=length-1;
    while(begin<end)
    {
        if(str[begin]!=str[end])
            return 0;
        begin++;
        end--;
    }
    return 1;
}

int main()
{
    int a[5]={1,2,3,4,5};
    int j=0;
    int i;
    for( i=0;i<5;i++)
        printf("%d \t",a[i]);
    reverse(a,0,5,&j);
    int k;
    for( k=0;k<5;k++)
        printf("%d \t",a[k]);
    printf("\n------code for palindrome check----\n");
    char str[]="Shishir";
    //printf("--%d--",checkpalindrome(str));
    if(!checkpalindrome(str))
        printf("String is not a palindrome");
    else
        printf("String is a palindrome");

    return 0;
}
