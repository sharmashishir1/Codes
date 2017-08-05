#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
    struct node * random;
};


struct node * newnode (int data)
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->random=NULL;
    return temp;

}


struct node * copytree(struct node * root1,struct node * root2)
{
    if(root1==NULL)
        return NULL;
    else
    {
        root2=newnode(root1->data);
        root2->random=root1->random;
        root2->left=copytree(root1->left,root2->left);
        root2->right=copytree(root1->right,root2->right);
        return root2;
    }
}

void printtree(struct node * root)
{
    if(root==NULL)
        return;
    printtree(root->left);
    printf(" %d ",root->data);
    if(root->random)
        printf(" Random data: %d ",root->random->data);
    printtree(root->right);

}

int main()
{
    struct node * root1;
    struct node * root2;
    root1=newnode(10);
    root1->left=newnode(5);
    root1->left->left=newnode(1);
    root1->left->right=newnode(8);
    root1->right=newnode(15);
    root1->right->left=newnode(12);
    root1->right->right=newnode(20);
    root1->random=root1->left;
    root1->right->random=root1->right->left;
    root2=copytree(root1,root2);
    printtree(root1);
    printf("\n");
    printtree(root2);
    return 0;
}
