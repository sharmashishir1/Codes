#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int IsBSTCheck(struct node * root,int MINI,int MAXI);

struct node * newnode(int item)
{
    struct node * tempnode=(struct node*)malloc(sizeof(struct node));
    tempnode->data=item;
    tempnode->left=NULL;
    tempnode->right=NULL;
    return tempnode;
};

int IsBSTCheck(struct node * root,int MINI,int MAXI)
{
    if(root==NULL)
        return 1;
    else if(root->data<MINI||root->data>MAXI)
        return 0;
    else
        return((IsBSTCheck(root->left,MINI,root->data))&&(IsBSTCheck(root->right,root->data,MAXI)));
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

    int check = IsBSTCheck(root,-999,999);
    if(check==1)
    printf("Tree is BST.");
    else
    printf("Tree is not  BST.");
    return 0;
}
