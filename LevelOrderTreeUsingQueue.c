#include<stdio.h>

struct node
{
    int data;
    struct node * left,*right;
};

struct node* newnode(int item)
{
    struct node*tempnode=(struct node*)malloc(sizeof(struct node));
    tempnode->data=item;
    tempnode->left=NULL;
    tempnode->right=NULL;
    return tempnode;
};

//prototype dec
struct node** createqueue(int *front,int *rear);
struct node * dequeueelement(struct node ** que,int *front);

void traversalusingqueue(struct node *root)
{
    int front=0,rear=0;
    struct node** que= createqueue(&front,&rear);
    while(root!=NULL)
    {
        printf("%d",root->data);
        insertintoqueue(root->left,que,&rear);
        insertintoqueue(root->right,que,&rear);
        root=dequeueelement(que,&front);
    }
}


struct node** createqueue(int *front,int *rear)
{
    struct node** Queue=(struct node**)malloc(sizeof(struct node*)*500);
   // *front=*rear=0;
    return Queue;
};

void insertintoqueue(struct node* tempnode,struct node** que,int *rear)
{
    que[*rear]=tempnode;
    (*rear)++;
}

struct node * dequeueelement(struct node ** que,int *front)
{
    struct node * tempnode=que[*front];
    (*front)++;
    return tempnode;
};

int main()
{
    struct node* root=newnode(4);
    root->left=newnode(2);
    root->left->left=newnode(1);
    root->left->right=newnode(3);
    root->right=newnode(6);
    root->right->left=newnode(5);
    root->right->right=newnode(7);
    traversalusingqueue(root);


}
