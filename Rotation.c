#include<stdio.h>

void rotate(int * arr, int length, int k)
{
    //array copied in temp array
    int * tarr=(int *)malloc(sizeof(int)*k);
    int i;
    for( i=0;i<k;i++)
        tarr[i]=arr[i];
    for( i=0;i<length;i++)
        arr[i]=arr[i+k];
    int j=0;
    for( i=length-k;i<length;i++)
        arr[i]=tarr[j++];
}

int gcd(int a,int b)
{

    if(b==0)
        return a;
    return gcd(b,a%b);
}

void leftrotate(int arr[], int d, int n)
{
  int i, j, k, temp;
  for (i = 0; i < gcd(d, n); i++)
  {
    /* move i-th values of blocks */
    temp = arr[i];
    j = i;
    while(1)
    {
      k = j + d;
      if (k >= n)
        k = k - n;
      if (k == i)
        break;
      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
  }
}



int main()
{
    int arr[]={1,2,3,4,5};
    int length=sizeof(arr)/sizeof(int);
    printf("%d -legth \n",length);
    int k=1002;
    if(k>length)
        k=k%length;
    int i;
    for( i=0;i<length;i++)
        printf("%d",arr[i]);
    leftrotate(arr,k,length);

    printf("\n--output--\n");
    for( i=0;i<length;i++)
        printf("%d",arr[i]);
    return 0;
}
