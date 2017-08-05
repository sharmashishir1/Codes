#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main()
{
int a[10];
int i=0,count=0,noe;
//Creating the linked list
printf("Enter the no of elements of linked list");
scanf("%d",&noe);
struct node *temp,*start,*link;
temp=(struct node *)malloc(sizeof(struct node));
link=temp;
start=temp;
printf("Enter the %d element",i);
scanf("%d",&temp->data);
i++;
while(i!=noe)
{
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the %d element",i);
    scanf("%d",&temp->data);
    link->next=temp;
    link=temp;
    i++;
}
link->next=NULL;
//displaying contents before reversing
temp=start;
while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        }

//copying the elements in a array(stack)
i=0;
temp=start;
while(temp!=NULL)
{
    a[i]=temp->data;
    i++;
    temp=temp->next;
    }
//again copying the elements in reverse order from stack
i--;
temp=start;
while(temp!=NULL)
{
    temp->data=a[i];
    i--;
    temp=temp->next;
    }
//displaying the contents of linked list
temp=start;
while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        }
return 0;
}
