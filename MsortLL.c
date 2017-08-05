#include<stdio.h>
#include<stdlib.h>

struct node
{

int data;
struct node * next;
};

void printlist(struct node* temp)
{
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

struct node * createlist(int data)
{
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}


void pushnode(struct node * head, int item)
{
    while(head->next!=NULL)
    {
        head=head->next;
    }
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=NULL;
    head->next=temp;
}

void mergesplit(struct node **list1,struct node **list2, struct node *temp)
{
    if(temp==NULL)
    {
    *list1=NULL;
    *list2=NULL;
    }
    else
    {
    struct node *p1,*p2;
    p1=p2=temp;
    while(p2!=NULL && p2->next->next!=NULL)
    {
        p1=p1->next;
        p2=p2->next->next;
    }
    *list1=temp;
    *list2=p1->next;
    p1->next=NULL;
    }
}

struct node * mergell(struct node * list1,struct node * list2)
{
    if(list1==NULL)
        return;
    else
    {


    struct node *head,*temp;
    if(list1->data<list2->data)
       {
         head=temp=list1;
         list1=list1->next;
       }
    else
    {
        head=temp=list2;
        list2=list2->next;
    }
        while(list1->next!=NULL && list2->next!=NULL)
        {
            if(list1->data<list2->data)
            {
                temp->next=list1;
                temp=temp->next;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                temp=temp->next;
                list2=list2->next;
            }
        }
        while(list1!=NULL)
        {
            temp->next=list1;
            list1=list1->next;
            temp=temp->next;
        }

        while(list2!=NULL)
        {
            temp->next=list2;
            list2=list2->next;
            temp=temp->next;
        }

            return head;
            }
}

void mergesort(struct node ** head)
{
    struct node * temp=*head;
if(temp==NULL || temp->next==NULL)
    return;
    struct node *list1,*list2;
    mergesplit(&list1,&list2,temp);

    mergesort(&list1);
    mergesort(&list2);
   *head= mergell(list1,list2);
}


int main()
{
    struct node* list1=createlist(10);
    pushnode(list1,15);
    pushnode(list1,11);
    pushnode(list1,1);
//    pushnode(list1,9);
//    pushnode(list1,20);
//    pushnode(list1,12);
    printf("\nPrinting the first list\n");
    printlist(list1);
    printf("\n");
    //code for merge sort
    mergesort(&list1);
    printf("printing list after merge sort");
    printf("\n");
    printlist(list1);
    return 0;
}
