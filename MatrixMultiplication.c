
//Adobe: Code to multiply two matrices

#include<stdio.h>

int main()
{
    int a[2][3];
    int i,j;
    int k=1;
    for( i=0;i<2;i++)
        for( j=0;j<3;j++)
            a[i][j]=k++;
    int b[3][2];
    for(i=0;i<3;i++)
        for(j=0;j<2;j++)
            b[i][j]=k++;

    int c[2][2];
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            c[i][j]=0;
    //main code for multiplication
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<3;k++)
                c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
        }

    }

    //printing the final matrix
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
            printf("%d \t",c[i][j]);
        printf("\n");
    }

    return 0;
}
