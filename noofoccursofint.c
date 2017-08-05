#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};

int main()
{
    int i=0,count=0,num,noe,noo;
    struct node *temp,*start,*link;
    printf("Enter the no of elements u ant to enter in a linked list");
    scanf("%d",&noe);
    temp=(struct node*)malloc(sizeof (struct node));
    start=temp;
    link=temp;
    printf("Enter the %d element",i);
    scanf("%d",&temp->data);
    i++;
    while(i!=noe)
    {
        temp=(struct node *)malloc(sizeof (struct node));
        printf("Enter the %d element",i);
        scanf("%d",&temp->data);
        link->next=temp;
        link=temp;
        i++;
    }
    link->next=NULL;
 //printing the elements entered by user

 temp=start;
 while(temp!=NULL)
 {
    printf("%d\t",temp->data);
    temp=temp->next;
 }

///finding the no of occurs of given number
printf("\nEnter the no for which u want to count the no of occurrence\n");
scanf("%d",&noo);
temp=start;

while(temp!=NULL)
{
    if(noo==temp->data)
    {
        count++;
    }
    temp=temp->next;
    }


printf("the no of occurrence of %d are %d",noo,count);
return 0;
}
