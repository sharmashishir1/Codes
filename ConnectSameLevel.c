#include<stdio.h>
#include<stdlib.h>

 struct tnode
{
   int data;
   struct tnode * left;
   struct tnode * right;
   struct tnode * nextright;
};

//stack operations

struct qnode
{
    int level;
    struct tnode * treenode;
    struct qnode * next;
};

struct queueTNode
{
    struct qnode * front;
    struct qnode * rear;
};

struct queueTNode * createQueue()
{
    struct queueTNode * temp=(struct queueTNode *)malloc(sizeof(struct queueTNode));
    temp->front=NULL;
    temp->rear=NULL;
    return temp;
}

void pushitem(struct queueTNode * tqueueTNode, struct tnode * ttnode, int level)
{
    struct qnode * tqnode=(struct qnode *)malloc(sizeof(struct qnode));
    tqnode->treenode=ttnode;
    tqnode->level=level;

    //case for pushing first stack node
    if(tqueueTNode->rear==NULL)
    {
        tqnode->next=NULL;
        tqueueTNode->front=tqueueTNode->rear=tqnode;
    }
    else
    {
        tqnode->next=tqueueTNode->rear;
        tqueueTNode->rear=tqnode;
    }

}


struct qnode * popitem(struct queueTNode * tqueueTNode)
{
    if(tqueueTNode->front==NULL)
        return;
    struct qnode * temp=tqueueTNode->front;
    tqueueTNode->front=tqueueTNode->front->next;
    return temp;
}

int getlevelfornextfront(struct queueTNode * tqueueTNode)
{
   return tqueueTNode->front->level;
}

void ConnectingSameLevels(struct queueTNode * tqueueTNode,struct tnode * root, int level)
{
    if(level==0)
    {
        root->nextright=NULL;
    }
    if(root==NULL)
        return NULL;
    //creating queue
    //tqueueTNode=createQueue();
    struct tnode * troot=root;
    while(troot!=NULL)
    {
        pushitem(tqueueTNode,troot->left,level+1);
        pushitem(tqueueTNode,troot->right,level+1);

    }

    while(tqueueTNode->front!=NULL)
    {
        struct qnode * tqnode=popitem(tqueueTNode);
        if(getlevelfornextfront==tqnode->level)
        {
            tqueueTNode->front->next=tqnode;
        }
        else
            tqueueTNode->front->next=NULL;
    }

}



struct tnode * newTNode(int data)
{
    struct tnode * temp=(struct tnode * )malloc(sizeof(struct tnode));
    temp->data=data;
    temp->nextright=temp->left=temp->right=NULL;
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

int main()
{
    struct tnode *root=newTNode(50);
    root->left=newTNode(30);
    root->left->left=newTNode(10);
    root->left->right=newTNode(40);
    root->right=newTNode(80);
    root->right->left=newTNode(60);
    root->right->right=newTNode(100);
    printtree(root);
    printf("\n Code for connecting same level \n");
    struct queueTNode * tqueueTNode=createQueue();
    ConnectingSameLevels(tqueueTNode, root, 0);
    printf("Code ends here");
    return 0;
}

