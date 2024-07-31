#include<iostream>
using namespace std;
struct bstnode
{  
   bstnode*r;
   bstnode*l;
   int data;
};

bstnode*insert(bstnode*T, int x)
{
   if(T==NULL)
      {
        T=new bstnode;
        T->data=x;
        T->r=NULL;
        T->l=NULL;
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

bstnode*create()
{
  int i,x,n;
  bstnode*root=NULL;
  cout<<"enter no. of nodes";
  cin>>n;
  cout<<"enter tree values";
  for(i=0;i<n;i++)
  {
    cin>>x;
    root=insert(root,x);
  }
  return root;
}

void inorder(bstnode*T)
{
   if(T!=NULL)
   {
     inorder(T->l);
     cout<<T->data<<" ";
     inorder(T->r);
     
   }
}

bstnode*find_min(bstnode*T)
{
  while(T->l!=NULL)
       T=T->l;
  return T;
}

bstnode*find_max(bstnode*T)
{
  while(T->r!=NULL)
       T=T->r;
  return T;
}

int ht(bstnode*T)
{
  int hl,hr;
  if(T==NULL)
    return 0;
  if(T->l==NULL  && T->r==NULL)
     return 0;
  hl=ht(T->l);
  hr=ht(T->r);
  if(hl>hr)
      return hl+1;
  return hr+1;
}

bstnode*find(bstnode*T,int x)
{
   while(T!=NULL)
   {
      if(T->data==x)
         return T;
      if(x>T->data)
         T=T->r;
      else
         T=T->l;
   }
    return NULL;

}



int main()
{

  bstnode*T,*p;
  int x,y,ch;
  char c;
  do
  {
  cout<<"\n1:create tree \n2:insert  \n3:min  \n4:max  \n5:no. of nodes in longest path  \n6:find node";
  cout<<"\n\nenter choice";
  cin>>ch;
  switch(ch)
  {
     case 1: 
            T=create();
            inorder(T);
            break;
    case 2:
          cout<<"\nenter value:";
          cin>>x;
          insert(T,x);
          inorder(T);
          break;
   case 3:
         p=find_min(T);
         cout<<"\nmin="<<p->data;
           break;
   case 4:
         p=find_max(T);
         cout<<"\nmax="<<p->data;
        break;
  case 5:
        y=ht(T)+1;
        cout<<"\nno. of nodes in longest path"<<y;
        break;
  case 6:
        cout<<"\nenter value to search";
        cin>>x;
        p=find(T,x);
        if(p==NULL)
           cout<<"\nnode not found";
        else
           cout<<"\nnode found";
       break;
  default:
      cout<<"\nwrong choice";
      
 }
 cout<<"\ndo you want to continue press y:" ;
 cin>>c;
 }while(c=='y');
 return 0;
}


