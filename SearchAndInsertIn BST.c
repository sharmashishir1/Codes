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
    temp->left=temp->right=NULL;
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

struct tnode * searchtree(struct tnode * root,int data)
{
    if(root==NULL || root->data==data)
        return root;
    if(root->data>data)
       return searchtree(root->left,data);
    if(root->data<data)
       return searchtree(root->right,data);
}

struct tnode * insertnode(struct tnode * root,int data)
{
    if(root==NULL)
        return newnode(data);
    else if(root->data>data)
        root->left=insertnode(root->left,data);
    else if(root->data<data)
        root->right=insertnode(root->right,data);
        return root;
}

struct tnode * getminvaluenode(struct tnode * root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}

struct tnode * deletenode(struct tnode * root,int data)
{
    if(root==NULL)
        return;
    else if(root->data<data)
        root->right=deletenode(root->right,data);
    else if(root->data>data)
        root->left=deletenode(root->left,data);
    else
    {
        //case for no or 1 child
        if(root->right==NULL)
        {
            struct tnode * temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            struct tnode * temp=root->right;
            free(root);
            return temp;
        }
        //case for two children
        else
        {
            struct tnode * temp=getminvaluenode(root->right);
            root->data=temp->data;
            return deletenode(root->right,temp->data);
        }

        return root;
    }
}

void printkthsmallest(struct tnode * root,int i)
{
    static int k=0;
    if(root==NULL)
        return;
    printkthsmallest(root->left,i);
    k++;
    if(k==i)
        printf("Kth smallest element is : %d",root->data);
    printkthsmallest(root->right,i);
}


int main()
{
    struct tnode * root=newnode(100);
    insertnode(root,80);
    insertnode(root,90);
    insertnode(root,170);
    insertnode(root,180);
    insertnode(root,120);
    insertnode(root,150);
    insertnode(root,20);
    printtree(root);
    struct tnode * searchnode=searchtree(root,120);
    if(searchnode!=NULL)
    printf("\n element found : %d \n",searchnode->data);
    deletenode(root,20);
    printtree(root);
    printf("\n\n");
    printkthsmallest(root,5);
    return 0;
}
