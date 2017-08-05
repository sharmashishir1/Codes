#include<stdio.h>>
#include<stdlib.h>

struct tnode
{
    int data;
    struct tnode * left;
    struct tnode * right;
};

struct tnode * newnode(int data)
{
    struct tnode * temp=(struct tnode *)malloc (sizeof(struct tnode));
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
    printf("Element : %d \n",root->data);
    printtree(root->right);
}

int printancestors(struct tnode * root,int data)
{
    if(root==NULL)
        return 0;
    if(root->data==data)
        return 1;
    if(printancestors(root->left,data)||printancestors(root->right,data))
    {
        printf("Element : %d \t",root->data);
        return 1;
    }
    return 0;


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
    printancestors(root,100);
    return 0;
}

