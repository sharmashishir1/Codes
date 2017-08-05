#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main()
{
int i,count=0,flag=0,j,k;
struct node n1,n2,n3,n4,n5,b1,b2;
struct node *temp,*start,*temp1,*temp2;
n1.data=3;
n1.next=&n2;
n2.data=4;
n2.next=&n3;
n3.data=5;
n3.next=&n4;
n4.data=6;
n4.next=&n5;
n5.data=7;
n5.next=NULL;
b1.data=1;
b1.next=&b2;
b2.data=2;
b2.next=&n3;
start=&n1;


for(i=0,temp1=&n1;i<5&&count==0;i++)
    {
       for(j=0,temp2=&b1;j<5;j++)
       {
          if(temp1==temp2)
          {
              flag=1;
              k=temp1->data;
              count=1;
          }
          temp2=temp2->next;
          }
       temp1=temp1->next;
       }

if(flag==1)
            printf("the intersection is at node %d",k);
else
    printf("No intersection point is present ");

    return 0;
}
