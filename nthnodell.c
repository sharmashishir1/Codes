#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int i,nod,nnode,count=0;
    struct node *temp,*link,*start;
    printf("Enter the no of data items you want to enter");
    scanf("%d",&nod);
    i=0;

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

 // finding the nth node

 printf("\nEnter the nth node which you want to find out \n");
 scanf("%d",&nnode);
 temp=start;
 while(temp!=NULL)
        {
            if(count==nnode)
            {
                printf("the nth node is %d",temp->data);
                break;
                }
        count++;
        temp=temp->next;
        }

return 0;

}
