#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isPalindrome(char *str, int length)
{
    //get reverse of this string
    char * rev=(char *)malloc(sizeof(char)* length);
    rev[length]='\0';
    int i,k;
    k=length-1;
    for(i=0;i<length;i++,k--)
        rev[k]=str[i];
    return strcmp(str,rev);
}

void printpalindrome(char *str, int length)
{
    int fstart,fend,flength=0;
    int k,startindex,endindex;
    for( k=1;k<length;k++)
    {

        for( startindex=0;startindex<length;startindex++)
        {
            int index=0;
            char * tstr=(char *)malloc(sizeof(char)*(k+1));
            for( endindex=startindex;index<k;endindex++,index++)
                {
                   tstr[index]=str[endindex];

                }
                tstr[index]='\0';
                //code to check weather the obtained string is palindrome or not
                //printf("%d \n",isPalindrome(tstr,index+1));
                if(isPalindrome(tstr,index)==0 && flength<k)
                       {
                           fstart=startindex;
                           fend=startindex+index-1;
                           flength=k;

                       }

        }
    }
    int fi;
    for(fi=fstart;fi<=fend;fi++)
      printf("%c",str[fi]);
    printf("\nLength: %d",flength);

}

//code starts for Dynamic programming solution
void longestPalindromeUsingDP(char * str, int length)
{
    int i,j;
    int start,end;
    //creating 2d array dynamically
    int ** array=(int *)malloc(sizeof(int *)*length);
    for(i=0;i<length;i++)
            array[i]=(int *)calloc(length,sizeof(int));


    printf("\n\nDynamic Programming Starts here \n");
    //making palindromes of length as true
    for(i=0;i<length;i++)
        array[i][i]=1;

    //checking palindromes of length 2
    int k=0;
    for(i=1;i<length;i++)
    {
        if(str[i-1]==str[i])
            array[k][i]=1;
        k++;
    }

    //code for true in case where length is more than 2
    for(i=2;i<length;i++)
    {
        int di=i;
        for(j=0;di<length;j++,di++)
        {
            if(str[di]==str[j] && array[j+1][di-1]==1)
            {

                array[j][di]=1;
                start=j;
                end=i+1;

            }

        }
    }
    //printing the final output
    for( i=0;i<length;i++)
        {for(j=0;j<length;j++)
            printf("%d  ",array[i][j]);
        printf("\n");
        }
    for(i=start;i<=end;i++)
        printf("%c",str[i]);
}



int main()
{

    printf("Program for longest palindrome substring\n\n");
    char str[]="abshdnitinitin";
    int length=strlen(str);
    printpalindrome(str,length);
    longestPalindromeUsingDP(str, length);
    return 0;
}
