#include<stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newnode(int data)
{
    struct node* tempnode=(struct node*)malloc(sizeof(struct node));
    tempnode->data=data;
    tempnode->left=NULL;
    tempnode->right=NULL;
    return tempnode;
};

void printinordertree(struct node* root)
{
    if(root==NULL)
    {
        return ;
    }
    printinordertree(root->left);
    printf("%d",root->data);
    printinordertree(root->right);
}

int caltreeheight(struct node *root)
{
    if(root==NULL)
        return 0;
    int leftheight=caltreeheight(root->left);
    int rightheight=caltreeheight(root->right);
    return (1+max(leftheight,rightheight));

}

int max(int a, int b)
{
    if(a>b)
    return a;
    else
        return b;
}

int main()
{
    struct node* root=newnode(4);
    root->left=newnode(2);
    root->left->left=newnode(1);
    root->left->right=newnode(3);
    root->right=newnode(6);
    root->right->left=newnode(5);
    root->right->right=newnode(7);
    printf("%d",caltreeheight(root));
    printf("\n");
    printinordertree(root);
    return 0;
}
