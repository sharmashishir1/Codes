#include<stdio.h>
#include<stdlib.h>

struct qNode
{
    int data;
    struct qNode* next;
};

struct queue
{
    struct qNode* front;
    struct qNode* rear;
};


struct queue * createQueue()
{
 struct queue *head=(struct queue*)malloc(sizeof(struct queue));
 head->front=NULL;
 head->rear=NULL;
 return head;
};

void enqueue(struct queue* tqueue,int data)
{
    struct qNode * tqnode=(struct qNode*)malloc(sizeof(struct qNode));
    tqnode->data=data;
    tqnode->next=NULL;
    if(tqueue->rear==NULL)
    {
        tqueue->front=tqueue->rear=tqnode;
        return;
    }
    tqueue->rear->next=tqnode;
    tqueue->rear=tqnode;
}

int dequeue(struct queue* tqueue)
{
   if(tqueue->front==NULL)
   {
       printf("Queue is empty.");
       return;
   }
   struct qNode * temp=tqueue->front;
   tqueue->front=tqueue->front->next;
   free(temp);
}

void printQueue(struct queue * head)
{
    struct qNode *temp=head->front;
    while(temp!=NULL)
    {
     printf("Element : %d\n",temp->data);
     temp=temp->next;
    }
}

int main()
{
    struct queue* head=createQueue();
    enqueue(head,10);
    enqueue(head,15);
    enqueue(head,20);
    enqueue(head,25);
    printf("Printing Queue: \n");
    printQueue(head);
    dequeue(head);
    dequeue(head);
    printf("Printing queue after dequeue operation\n");
    printQueue(head);
    return 0;
}

