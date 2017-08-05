#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {

    temp = *begin;
    //printf("%c",temp);
    *begin++ = *end;
    *end-- = temp;
  }
}

void reverseWords(char * str)
{

    int length=strlen(str);
    printf("%s",str);
    //int i=0;
    //int state=0;
    int start=0;
    int end=0;
    while(str[start]!='\0')
    {
        if(str[start]== ' ')
        {
            //start=i;
            end=start+1;
            while(str[end]!=' ' || str[end]=='\0')
            {
                end++;
                //i++;
            }
            reverse(&str[start+1],&str[end-1]);
            start=end;
        }
        //i++;
    }

}

int main()
{
    char str[]="  My name is shishir sharma";
    //code to reverse words in string
    reverseWords(str);
    //code to reverse complete string
    printf("%s \n",str);

    int i=0;int k=0;
    while(str[i]==' ')
        i++;
    while(str[i]!='\0')
    {
        if(str[i]== ' ')
        {
            while(str[i]==' ')
                i++;
            str[k]=' ';
            k++;
        }
        else
        {
            str[k]=str[i];
            k++;
            i++;
        }

    }
    str[k]='\0';

    printf("%s \n",str);
    int end=strlen(str)-1;
    reverse(&str[0],&str[end]);
    printf("%s",str);
    return 0;
}
