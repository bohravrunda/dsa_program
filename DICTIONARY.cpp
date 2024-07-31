#include<iostream>
#include<string.h>
#define max 20
using namespace std;
struct dic
{
  char keyword;
  char mean[max];
  dic*r;
  dic*l;
};

class dicop
{
  public:
  dic*root;
  
  dic*insert(dic*T,char x,char y[max])
  {
    if(T==NULL)
    {
      T=new dic;
      T->keyword=x;
      strcpy(T->mean,y);
      T->l=NULL;
      T->r=NULL;
      return T;
    }
      if(x>T->keyword)
        {
             T->r=insert(T->r,x,y);
      
           }
               return T;
    
      if(x<T->keyword)
          {
              T->l=insert(T->l,x,y);
      
          }
           return T;
     
  }
  
  void create()
  {
    root=NULL;
    int n;
    char m[max],k;
    cout<<"\nenter total words: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cout<<"\nenter keyword: ";
      cin>>k;
      cout<<"\nenter meaning: ";
      cin>>m;
      root=insert(root,k,m);
      
    }
    
    
    
  }
  
  dic*find_min(dic*T)
  {
    if(T==NULL)
    
      return NULL;
    
    while(T->l!=NULL)
    {
      T=T->l;  
      
    }
    return T;
  }
  
  dic*del(dic*T,char x)
  {
    dic*temp;
    if(T==NULL)
    { 
      cout<<"\nelement not found";
      return T;
    }
    if(x>T->keyword)
    {
      T->r=del(T->r,x);
      return T;
      
    }
    if(x<T->keyword)
    {
      T->l=del(T->l,x);
      return T;
      
    }
    if(T->l==NULL && T->r ==NULL)
    {
       delete T;
       return NULL;
    }
    
    if(T->l==NULL)
    {
       temp=T;
       T=T->r;
       delete(temp);
       return T;
       
    }
    
    if(T->r==NULL)
    {
       temp=T;
       T=T->l;
       delete(temp);
       return T;
       
    }
    
    temp=find_min(T->r);
    T->keyword=temp->keyword;
    T->r=del(T->r,temp->keyword);
    return T;
    
 }
 
 void inorder(dic*T)
 { 
   if(T!=NULL)
 {
   inorder(T->l);
   cout<<T->keyword<<":"<<T->mean<<endl;
   inorder(T->r);
 }
 }
 
 void reverseinorder(dic*T)
 {
  if(T!=NULL)
  {
   reverseinorder(T->r);
   cout<<T->keyword<<":"<<T->mean<<endl;
   reverseinorder(T->l);
 }
 }
 
 dic*update(dic*T,char b)
 {
   char m[max];
   while(T->keyword!=b)
   {
     if(b<T->keyword)
     {
       T=T->l;
     }
     else
     {
       T=T->r;
     }
     
     if(T==NULL)
     {
       cout<<"\nnot found";
       return T;
     }
   }
   
   if(T->keyword==b)
   {
     cout<<"enter new meaning for "<<b<<" :";
     cin>>m;
     strcpy(T->mean,m);
     
   }
   
   return T;
 }
 
 dic*search(dic*T,char x,int &count)
 {
   count++;
   if(T==NULL)
       return NULL;
   if(x==T->keyword)
      return T;
  if(x<T->keyword)
  {
     return search(T->l,x,count);
  }
  return search(T->r,x,count);
 }
 
 void menu()
 {int ch;
  char ans;
 
 do
 {
     
    cout<<"\n1:create \n2:delete keyword \n3:update meaning \n4:display acsending  \n5:display decending \n6:no. of comparism \n7:exit ";
    cout<<"\nenter your choice:";
    
    cin>>ch;
    
    switch (ch)
  {  
    case 1:
         create();
         break;
         
    case 2: 
         {
         char keyword;
         cout<<"\nenter keyword to del: ";
         cin>>keyword;
         root=del(root,keyword);
         cout<<"\nafter deleting "<<keyword<<" ";
         inorder(root);
         }
         
         break;
         
   case 3:
        {
         char keyword;
         cout<<"\nenter keyword to update: ";
         cin>>keyword;
         root=update(root,keyword);
         cout<<"\nafter upadating "<<keyword;
         inorder(root);
         }
         
         break;
         
   case 4:
       
        cout<<"\nacsending order :\n";
        inorder(root);
        
        break;
       
  case 5:
        
        cout<<"\ndesending order :\n";
        reverseinorder(root);
        
        break;
        
  case 6:
       { char keyword;
        cout<<"\nenter keyword to search : ";
        cin>>keyword;
        int count =0;
        if(search(root,keyword,count)!=NULL)
        {
          cout<<"\nkeyword is found after "<<count<<" comparisons"<<endl;
         
        }
        else
          {cout<<"\nnot found";
          }
      }
          
        break;
   case 7:
      cout<<"\nexit program";
      break;
  default:
     cout<<"\nwrong choice";
     
        
 
  
  }cout<<"\ndo you want to continue: ";
  cin>>ans;
         
 }while(ans=='y');
 }
};

int main()
{
  dicop d;
  d.menu();
  return 0;
}
