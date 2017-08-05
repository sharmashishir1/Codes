#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,num,k=1,count;
    printf("enter the number");
    scanf("%d",&num);
    while(k==1)
    {   count=0;
        for(i=1;i<=num;i++)
        {
            if(num%i==0)
            {
                count++;
                if(count==2&&i==num)
                {
                 k=0;
                 break;
                        }
                else if(count>2)
                    break;
             }

     }
    num++;
    }
num=num--;
printf("the next prime number is %d",num);
     return 0;
}
