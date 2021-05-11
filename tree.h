#include<iostream>
using namespace std;

struct node
{
    int data1;
    int data2;
    struct node *lchild;
    struct node *rchild;
}*root,*curr,*par;

void create(int elt1,int elt2)
{
    struct node *N=new node;
    N->data1=elt1;
    N->data2=elt2;
    N->lchild=N->rchild=NULL;
    root=N;
}
int search_elt(struct node *p,int elt)
{
    if(p==root)
    {
        par=NULL;
        curr=p;
    }
    if(p==NULL)
        cout<<"\n\t\t\tDATABASE IS EMPTY!!\n\t\t\t(Ignore this Message if this is your First Insertion)"<<endl;
    else if(elt==p->data1)
        return 1;
    else if(elt<p->data1)
    {
        if(p->lchild==NULL)
            return 0;
        else
        {
            par=p;
            curr=p->lchild;
            search_elt(p->lchild,elt);
        }
    }
    else if(elt>p->data1)
    {
        if(p->rchild==NULL)
            return 0;
        else
        {
            par=p;
            curr=p->rchild;
            search_elt(p->rchild,elt);
        }
    }
}
void delete_one()
{
    struct node *child;
    if(curr->lchild==NULL && curr->rchild==NULL)
        child=NULL;
    else if(curr->lchild!=NULL)
         child=curr->lchild;
    else
        child=curr->rchild;
    if(par!=NULL)
    {
        if(curr==par->lchild)
            par->lchild=child;
        else
            par->rchild=child;
    }
    else
        root=child;
}
void delete_two()
{
    struct node *ptr,*save;
    ptr=curr->rchild;
    save=curr;
    while(ptr->lchild!=NULL)
    {
        save=ptr;
        ptr=ptr->lchild;
    }
    curr->data1=ptr->data1;
    curr->data2=ptr->data2;
    par=save;
    curr=ptr;
    delete_one();
}
void remove_elt()
{
    if(curr==NULL)
    {
        return;
    }
    if(curr->rchild!=NULL && curr->lchild!=NULL)
    {
        delete_two();
    }
    else
    {
        delete_one();
    }
    delete curr;
}
void insert_elt(struct node *p,int elt1,int elt2)
{
    int val;
    int flag=0;
    val=search_elt(root,elt1);
    if(val==1)
    {
        cout<<"\n\t\t\tINSERTION UNSUCCESSFUL"<<endl;
        return;
    }
    if(p==NULL)
    {
        create(elt1,elt2);
        flag=1;
    }
    if(flag==0)
    {
        if(elt1<p->data1)
        {
            if(p->lchild==NULL)
            {
                struct node *N=new node;
                N->data1=elt1;
                N->data2=elt2;
                N->lchild=N->rchild=NULL;
                p->lchild=N;
            }
            else
            {
                insert_elt(p->lchild,elt1,elt2);
            }
        }
        else if(elt1>p->data1)
        {
            if(p->rchild==NULL)
            {
                struct node *N=new node;
                N->data1=elt1;
                N->data2=elt2;
                N->lchild=N->rchild=NULL;
                p->rchild=N;
            }
            else
            {
                insert_elt(p->rchild,elt1,elt2);
            }
        }
        cout<<"\n\t\t\tINSERTION SUCCESSFUL"<<endl;
    }
}
void display(struct node *ptr)
{
    if(ptr!=NULL)
    {
        display(ptr->lchild);
        display(ptr->rchild);
        cout<<ptr->data1<<" ";
    }
}



