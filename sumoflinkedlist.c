#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int i,noe,k,j=0,l=0,sum1,sum2,sum3;
    int a[10];
    struct node *temp,*ptemp,*start,*temp2,*start2;
    temp=(struct node*)malloc(sizeof(struct node));
    start=temp;
    //fisrt linkedlist
    printf("Enter the no of elements u want to enter in First linked list");
    scanf("%d",&noe);
    printf("Enter the %d element",j);
    scanf("%d",&temp->data);
    j++;
    while(j<noe)
    {
        temp2=(struct node*)malloc(sizeof(struct node));
        temp->next=temp2;
        temp=temp2;
        printf("enter the %d element",j);
        scanf("%d",&temp->data);
             j++;
    }
    temp->next=NULL;
    //entering the second linkedlist
    j=0;
    temp=(struct node*)malloc(sizeof(struct node));
    start2=temp;
    printf("Enter the no of elements u want to enter in second linked list");
    scanf("%d",&noe);
    printf("Enter the %d element",j);
    scanf("%d",&temp->data);
    j++;
    while(j<noe)
    {
        temp2=(struct node*)malloc(sizeof(struct node));
        temp->next=temp2;
        temp=temp2;
        printf("enter the %d element",j);
        scanf("%d",&temp->data);
             j++;
    }
    temp->next=NULL;
    //time for final manipulation
   //obtaining the number for first linked list
//sum for first linked list
temp=start;
i=0;
while(temp!=NULL)
{
    a[i]=temp->data;
    temp=temp->next;
    i++;
}
i--;
sum1=0;
while(i>=0)
{
    sum1=sum1*10+a[i];
    i--;
}

//sum for second linkedlist

temp=start2;
i=0;
while(temp!=NULL)
{
    a[i]=temp->data;
    temp=temp->next;
    i++;
}
i--;
sum2=0;
while(i>=0)
{
    sum2=sum2*10+a[i];
    i--;
}


//final sum
sum3=sum1+sum2;
printf("\nthe final sum is %d\n",sum3);

//creating the final linked list

struct node *start3;
    i=0;
    while(sum3>0)
    {
        a[i]=sum3%10;
        sum3=sum3/10;
        i++;
    }
k=0;
temp=(struct node *)malloc(sizeof(struct node));
start3=temp;
while(k<i)
{
    temp->data=a[k];
    temp2=(struct node*)malloc(sizeof(struct node));
    temp->next=temp2;
    ptemp=temp;
    temp=temp2;
    k++;
}
ptemp->next=NULL;

   //printing the linked list
  temp=start3;
  while(temp!=NULL)
  {
      printf("%d \t",temp->data);
      temp=temp->next;
  }

    return 0;
}
