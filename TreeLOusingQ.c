#include<stdio.h>
#include<stdlib.h>

struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
};

struct qnode
{
    struct tnode * link;
    struct qnode * next;
};

struct queue
{
    struct qnode * front;
    struct qnode *rear;
};

struct queue* createqueue()
{
    struct queue * tqueue=(struct queue *)malloc(sizeof(struct queue));
    tqueue->front=tqueue->rear=NULL;
    return tqueue;
};

void pushqnode(struct tnode * ttemp,struct queue * qtemp)
{
    //creating qnode
    struct qnode * tempqnode=(struct qnode *)malloc(sizeof(struct qnode));
    //adding qnode data
    tempqnode->link=ttemp;
    tempqnode->next=NULL;

    //managing the queue now
    if(qtemp->front==NULL)
    {
        qtemp->front=qtemp->rear=tempqnode;
    }
    else
    {
        qtemp->rear->next=tempqnode;
        qtemp->rear=tempqnode;
    }

}


void popqnode(struct queue * tqueue)
{
    if(tqueue->front==NULL)
        return;
    struct qnode * temp=tqueue->front;
    tqueue->front=tqueue->front->next;
    free(temp);
}

struct tnode * gettoptreenode(struct queue * tqueue)
{
    if(tqueue->front==NULL)
        return;
    return tqueue->front->link;
};


struct tnode * newnode(int data)
{
    struct tnode * temp=(struct tnode *)malloc(sizeof(struct tnode));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void printtree(struct tnode * root)
{
    if(root==NULL)
        return;
    printtree(root->left);
    printf("%d \t",root->data);
    printtree(root->right);
}

printlevelorder(struct tnode *root)
{
    struct tnode * temp=root;
    struct queue* tqueue=createqueue();
    while(temp!=NULL)
    {
        printf("%d \t",temp->data);
        pushqnode(temp->left,tqueue);
        pushqnode(temp->right,tqueue);
        temp=gettoptreenode(tqueue);
        popqnode(tqueue);
    }

}


int main()
{
    struct tnode *root=newnode(50);
    root->left=newnode(30);
    root->left->left=newnode(10);
    root->left->right=newnode(40);
    root->right=newnode(80);
    root->right->left=newnode(60);
    root->right->right=newnode(100);
    printtree(root);
    printf("\n");
    printlevelorder(root);
    return 0;
}
