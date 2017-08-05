#include<stdio.h>
#include<stdlib.h>


struct stack
{
 int data;
 struct stack * next;
};

void push(struct stack ** root,int data)
{
 //code for head
 struct stack * temp=(struct stack*)malloc(sizeof(struct stack));
 if (*root==NULL)
 {
  temp->data=data;
  temp->next=NULL;
 }
 else
 {
     temp->data=data;
     temp->next=*root;
 }

 *root=temp;
}

void pop(struct stack** root)
{
    struct stack * temp=*root;
    *root=temp->next;
    free(temp);
}

printstack(struct stack * head)
{
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
}

int getpeek(struct stack* head)
{
    return head->data;
}

int main()
{
    struct stack* head=NULL;
    push(&head,5);
    push(&head,12);
    push(&head,15);
    push(&head,20);
    printstack(head);
    printf("%d",getpeek(head));
    return 0;
}

