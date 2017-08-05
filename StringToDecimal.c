
//Adobe: code to convert number from string to decimal
#include<stdio.h>
#include<string.h>

int main()
{

    char givenstring[]="123456789";
    int length=strlen(givenstring);
    int finalnum=0;
    int i;
    for( i=0;i<length;i++)
    {
        finalnum=(finalnum*10)+(givenstring[i]-'0');
    }
    printf("Given String : %s \nObtained Num: %d",givenstring,finalnum);
    return 0;
}
