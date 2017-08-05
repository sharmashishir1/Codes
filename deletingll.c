#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int i,nod;
    struct node *temp,*link,*start;
    printf("Enter the no of data items you want to enter");
    scanf("%d",&nod);
    i=0;
//creating a linked list
    temp=(struct node *)malloc(sizeof(struct node));
    link=temp;
    start=temp;
    printf("Enter the %d data item",i);
    scanf("%d",&temp->data);
    i++;
    while(nod!=i)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            printf("Enter the %d data item",i);
            scanf("%d",&temp->data);
            link->next=temp;
            link=temp;
            i++;
            }
    link->next=NULL;
temp=start;
while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        }

//deleting  a linked list
temp=start;
while(temp!=NULL)
{
    link=temp->next;
    free(temp);
    temp=link;

}
start=NULL;
//again printing the linkedlist
/* temp=start;

while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        }

*/
return 0;

}
