#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int i,noe,k,j=0,l=0;;
    struct node *temp,*ptemp,*start,*temp2;
    temp=(struct node*)malloc(sizeof(struct node));
    start=temp;;
    printf("Enter th no of elements u want to enter in a linked list");
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
    //time for fianl manipulation
 ptemp=start;
 temp=ptemp->next;
 while(temp!=NULL)
 {
     if((temp->data)>(ptemp->data))
     {
         temp=temp->next;
         ptemp->next=temp;
         continue;
     }
     else
     {
         temp=temp->next;
         ptemp=ptemp->next;
     }

 }


//printing the elements of linked list
  temp=start;
  while(temp!=NULL)
  {
      printf("%d \t",temp->data);
      temp=temp->next;
  }

    return 0;
}
