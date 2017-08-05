#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int i,noe,k,j=0,group,l=0;;
    int a[10];
    struct node *temp,*ptemp,*start,*temp2;
    temp=(struct node*)malloc(sizeof(struct node));
    start=temp;
    printf("Enter th no of elements u want to enter in a linked list");
    scanf("%d",&noe);
    printf("Enter the size of group for reversal");
    scanf("%d",&group);
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
    //time for fianl manipulation
    k=noe/group;
    i=0;
    temp=start;
    ptemp=start;
    while(i<k)
    {
        //copying the elements in array
        for(l=0;l<group;l++)
        {
            a[l]=temp->data;
            temp=temp->next;
        }
        //copying back to ll
        for(l=--l;l>=0;l--)
        {
            ptemp->data=a[l];
            ptemp=ptemp->next;
        }
    i++;
    }

  temp=start;
  while(temp!=NULL)
  {
      printf("%d \t",temp->data);
      temp=temp->next;
  }

    return 0;
}
