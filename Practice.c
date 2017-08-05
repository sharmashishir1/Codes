#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct gnode
{
    void *date;
    struct gnode* next;
};

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

 void printlist(struct node* temp)
{
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

reversell(struct node** head)
{
    struct node *prev=NULL;
    struct node *current=*head;
    struct node *next;
    while(current!=NULL)
    {
        //prev=current;
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}

struct node * mergell(struct node* l1, struct node *l2)
{
    struct node *fhead,*temp,*ttemp;
    if(l1->data>l2->data)
        {
            ttemp=fhead=l2;
            l2=l2->next;
        }
    else
    {
        ttemp=fhead=l1;
        l1=l1->next;
    }

    while((l1!=NULL)&&(l2!=NULL))
    {
        if(l1->data<l2->data)
        {
            ttemp->next=l1;
            ttemp=ttemp->next;
            l1=l1->next;
        }
        else
        {
            ttemp->next=l2;
            ttemp=ttemp->next;
            l2=l2->next;
        }
    }
    while(l1!=NULL)
    {
        ttemp->next=l1;
        ttemp=ttemp->next;
        l1=l1->next;
    }
    while(l2!=NULL)
    {
        ttemp->next=l2;
        ttemp=ttemp->next;
        l2=l2->next;
    }

    return fhead;
};



struct node * recursivemerge(struct node *l1,struct node *l2)
{
    struct node * result=NULL;
    if(l1==NULL)
        return l2;
    else if(l2==NULL)
        return l1;
    else if(l1->data<l2->data)
    {
        result=l1;
        result->next=recursivemerge(l1->next,l2);
    }
    else if(l2->data<l1->data)
    {
        result=l2;
        result->next=recursivemerge(l1,l2->next);
    }
    return result;
};



struct node * reversecount(struct node *head)
{
    if(head==NULL)
        return;
    struct node *prev=NULL;
    struct node *next=NULL;
    struct node *current=head;
    int count=0;

    while(current!=NULL&&count<3)
    {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
            count++;

    }
    if(next!=NULL)
        head->next=reversecount(next);

    return prev;

}


struct node  *newNode(int key)
{
    struct node *temp =(struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}


void detectAndRemoveLoop(struct node * head)
{
    struct node *p1,*p2,*prev; int k=1;
    p1=p2=head;
    while(k==1)
    {
        if(p1==p2)
        {
            prev->next=NULL;
            prev->next=NULL;
            k=0;
        }
        else
        {
            prev=p1;
        p1=p1->next;
        p2=p2->next->next;
        }

    }
}


void rotatelinkedlist(struct node ** head,int k)
{
    int i;
   struct node * start =*head;
    for(i=0;i<k;i++)
    {

    struct node * temp =*head;
    struct node* prev=NULL;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        temp->next=start;
        prev->next=NULL;
        start=temp;

    }

    *head=start;
}


int main()
{
    struct node* list1=createlist(10);
    pushnode(list1,12);
    pushnode(list1,13);
    pushnode(list1,15);
    pushnode(list1,18);
    pushnode(list1,25);
    pushnode(list1,30);
    printf("\nPrinting the first list\n");
    printlist(list1);
    printf("\n");

//code for generic node
//struct node *gnode=(struct node *)malloc(sizeof(gnode));
//gnode->data=(char *)malloc(sizeof(char));
//gnode->next=NULL;
//gnode->data='A';
//printf("%c\n",gnode->data);


  //code for rotating a linkedlist
//  rotatelinkedlist(&list1,4);
//  printlist(list1);
//    printf("\n");

    //code for loop detection and removal
//     struct node *head = newNode(50);
//    head->next = newNode(20);
//    head->next->next = newNode(15);
//    head->next->next->next = newNode(4);
//    head->next->next->next->next = newNode(10);
//
//    /* Create a loop for testing */
//    head->next->next->next->next->next = head->next->next;
//
//    detectAndRemoveLoop(head);
//    printlist(head);

    //code for reversing the linkedlist
    //reversell(&head);
    //printf("\nReversing the linkedlist \n");
    //struct node* list2=createlist(11);
    //printf("\nPrinting the Second list\n");
    //printlist(list2);
    //struct node *  finalhead = mergell(list1,list2);
   // struct node * finalrhead=recursivemerge(list1,list2);
   // printf("\nPrinting the FINAL list\n");
   // printlist(finalhead);
    //printf("\nPrinting the recursive FINAL list\n");
    //printlist(finalrhead);
    //struct node* finallist=reversecount(list1);
    //printf("\n updated list\n");
    //printlist(finallist);
    return 0;
}
