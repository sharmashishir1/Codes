#include<stdio.h>
#include<stdlib.h>

struct tnode
{
    int data;
    struct tnode * left;
    struct tnode * right;
};

struct tnode * newnode(int data)
{
    struct tnode * temp=(struct tnode *)malloc(sizeof(struct tnode));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

void printtree(struct tnode * root)
{
    if(root==NULL)
        return;
    printtree(root->left);
    printf("%d \t",root->data);
    printtree(root->right);
}

int maximum(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int height(struct tnode * root)
{
    if(root==NULL)
        return 0;
    else
    {
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+(maximum(lh,rh));
    }
}

treediameter(struct tnode * root,int *hght)
{
    int lh=0;
    int rh=0;
    if(root==NULL)
    {
     *hght=0;
     return 0;
    }
    //int lh=height(root->left);
    //int rh=height(root->right);
    int ld=treediameter(root->left,&lh);
    int rd=treediameter(root->right,&rh);
    *hght=maximum(lh,rh)+1;
    return maximum(1+lh+rh,maximum(ld,rd));

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
    //root->right->right->right=newnode(120);
    printtree(root);
    int height;
    printf("\n Diameter of tree is : %d",treediameter(root,&height));
    return 0;
}
