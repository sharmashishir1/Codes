
//Adobe: Binary to decimal

#include<stdio.h>
#include<math.h>

int main()
{

    int bin=10010;
    //calculate the length of binary num
    int tbin=bin;
    int count=0;
    while(tbin>0)
    {
        if(tbin/10 >= 0)
        count++;
        tbin=tbin/10;
    }
    printf("\nCount= %d \n",tbin);

    //mow calculating the final dec num
    int decnum=0;
    int i=0;
    for(;i<count;i++)
    {
        decnum=decnum+((bin%10)*(pow(2,i)));
        bin=bin/10;

    }
    printf("Decimal Num : %d",decnum);
    return 0;
}
