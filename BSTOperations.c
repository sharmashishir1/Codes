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
}


struct tnode *insertelement(struct tnode * root,int data)
{
    if(root==NULL)
        return newnode(data);
    else if(data<root->data)
        root->left=insertelement(root->left,data);
    else if(data>root->data)
       root->right= insertelement(root->right,data);
    return root;
}


void printtree(struct tnode * root)
{
    if(root==NULL)
        return;
    printtree(root->left);
    printf("%d \t",root->data);
    printtree(root->right);
}

struct tnode * returnminvalue(struct tnode *root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;

}


struct tnode * deletenode(struct tnode * root, int data)
{
    if(root==NULL)
        return;
    else if(root->data>data)
        root->left=deletenode(root->left,data);
    else if(root->data<data)
       root->right=deletenode(root->right,data);
    else
    {
        //cases where root==data
        //case for one or no child nodes
        if(root->left==NULL)
        {
            struct tnode * temp=root->right;
            free (root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct tnode * temp=root->left;
            free (root);
            return temp;
        }
            //case for both the child nodes
            struct tnode * temp= returnminvalue(root->right);
            free(root);
            temp->right=deletenode(root->right,temp->data);
    return root;
    }

}



int main ()
{
   struct tnode * root=NULL;
    root=insertelement(root,50);
    insertelement(root,40);
    insertelement(root,60);
    insertelement(root,30);
    insertelement(root,45);
    insertelement(root,55);
    insertelement(root,7);
    printtree(root);
    deletenode(root,7);
    deletenode(root,55);
    printf("\n");
    printtree(root);
    return 0;
}


