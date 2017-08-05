#include<stdio.h>
#include<conio.h>

struct node{
    int data;
    struct node *next;
};

int main()
{
int i=0,noe,flag;
struct node *temp,*start,*link,*temp2;
printf("Enter the no of elements u want to enter in a linked list");
scanf("%d",&noe);
temp=(struct node*)malloc(sizeof(struct node));
link=temp;
start=temp;
printf("Enter the %d element",i);
scanf("%d",&temp->data);
i++;
while(i!=noe)
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the %d element",i);
    scanf("%d",&temp->data);
    link->next=temp;
    link=temp;
    i++;
}
link->next=start; //change this condition to Null to stop loop

//detecting a loop
temp=start;
temp2=start;
while(temp&&temp2&&temp2->next)
{
temp=temp->next;
temp2=temp2->next->next;
if(temp2==temp)
    {
     flag=1;
     break;
    }
}
if(flag==1)
    printf("loop detected");
else
    printf("No loop detected");

return 0;
}
