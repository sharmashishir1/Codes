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

int maximumno(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}


int calheight(struct tnode * root)
{
    if(root==NULL)
        return 0;
    else
    {
        return 1+maximumno(calheight(root->left),calheight(root->right));
    }
}

int maximumWidth(struct tnode * tree,int level)
{
    if(tree==NULL)
        return 0;
    if(level==1)
        return 1;
    return maximumWidth(tree->left,level-1)+maximumWidth(tree->right,level-1);
}

int getmaxwidth(struct tnode * root)
{
    int maxwidth=0; int tempwidth=0;int i;
    int height=calheight(root);
    for(i=1;i<=height;i++)
    {
        tempwidth=maximumWidth(root,i);
        if(tempwidth>maxwidth)
            maxwidth=tempwidth;
    }
    return maxwidth;
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
    printf("\n MAx width of tree is : %d \n",getmaxwidth(root));
    return 0;
}
