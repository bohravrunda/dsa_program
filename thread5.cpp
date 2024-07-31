#include<iostream>
using namespace std;
struct TBT
{
  int data;
  int lbit,rbit;
  TBT*l,*r;
  
};

class tree
{
   public:
   int n=0;
   TBT*in[20];
   TBT*insert(TBT*T,int x)
   {
       if(T==NULL)
       {
         T=new TBT;
          T->data=x;
          T->l=NULL;
          T->r=NULL;
          return T;
       }
       
      if(x>T->data)
      {
         T->r=insert(T->r,x);
         return T;
      }
      T->l=insert(T->l,x);
         return T;
      
      
      
      
   }
   
   TBT*create()
   {
      int n,i,x;
      TBT*root;
      root=NULL;
      cout<<"\nenter no of nodes: ";
      cin>>n;
      for(i=0;i<n;i++)
      {
         cout<<"\nenter data: ";
         cin>>x;
         root=insert(root,x);
         
      }
      return root;
   }
   
   void inorder(TBT*T)
   {  if(T!=NULL)
     {
        inorder(T->l);
        cout<<T->data<<" ";
        inorder(T->r);
      }
        
   }
   
  void inorderseq(TBT*T)
   {
     if(T!=NULL)
     {  inorderseq(T->l);
        in[n++]=T;
        if(T->l==NULL)
        {
           T->lbit=0;
         
        }
        else
       {
          T->lbit=1;
       }
       if(T->r==NULL)
       {
          T->rbit=0;
         
       }
       else
       {
         T->rbit=1;
       }
       inorderseq(T->r);
      }
   }
   
   void threading(TBT*T)
   {
      int i;
      TBT*root,*q;
      root=new TBT;
      root->data=0;
      root->lbit=root->rbit=1;
      root->r=root;
      root->l=T;
      q=in[0];
      q->l=root;
      cout<<"\nThread to left of "<<q->data<<" is "<<q->l->data;
      if(q->rbit==0)
      {
         q->r=in[1];
         cout<<"\nThread to right of "<<q->data<<" is "<<q->r->data;
      }
      
      q=in[n-1];
      q->r=root;
      cout<<"\nThread to right of "<<q->data<<" is "<<q->r->data;
      if(q->lbit==0)
      {
         q->l=in[n-2];
         cout<<"\nThread to left of "<<q->data<<" is "<<q->l->data;
      }
      
      for(i=1;i<(n-1);i++)
      {
        q=in[i];
        if(q->rbit==0)
      {
         q->r=in[i+1];
         cout<<"\nThread to right of "<<q->data<<" is "<<q->r->data;
      }
      if(q->lbit==0)
      {
         q->l=in[i-1];
         cout<<"\nThread to left of "<<q->data<<" is "<<q->l->data;
      }
        
      }
      
      
     
   }
};

int main()
{
   tree t;
   TBT*h;
   h=t.create();
   cout<<"\nINORDER IS:\n";
   t.inorder(h);
   t.inorderseq(h);
   t.threading(h);
   return 0;
}
