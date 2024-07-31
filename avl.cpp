#include<iostream>
#include<string.h>
using namespace std;
struct avl
{
   char keyword;
   char mean[30];
   int bf;
   avl*l,*r;
   
};
class avlop
{
   avl*root;
   
   public:
   
   avl*insert(avl*T,char k,char m[30])
   {
       int bal;
       
       if(T==NULL)
       {
          T=new avl;
          T->keyword=k;
          strcpy(T->mean,m);
          T->l=NULL;
          T->r=NULL;
          T->bf=0;
          
       }
       
       else
       {
          if(k<T->keyword)
          {
             T->l=insert(T->l,k,m);
             bal=bal_fact(T);
             cout<<"\n node "<<T->keyword<<" BF "<<bal;
             if(bal==2)
             {
                if(k<T->l->keyword)
                {
                   T=ll(T);
                }
                else
                {
                  T=lr(T);
                }
             }
          }
          
          else
          {
             T->r=insert(T->r,k,m);
             bal=bal_fact(T);
             cout<<"\n node "<<T->keyword<<" BF "<<bal;
             if(bal==-2)
             {
                if(k>T->r->keyword)
                {
                   T=rr(T);
                }
                else
                {
                  T=rl(T);
                }
             }
          }      
           T->bf=ht(T);
       }
       
       return T;
       
      
   }
   
   void create()
   {
      root=NULL;
    int n;
    char m[30],k;
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
   
   int ht(avl*T)
   {
      int hl,hr;
      if(T==NULL)
          return 0;
     else
     {
        hl=ht(T->l);
        hr=ht(T->r);
        if(hl>hr)
        {
           return hl+1;
           
        }
        return hr+1;
     }
   }
   
   int bal_fact(avl*T)
   {
      int hl,hr;
      hl=ht(T->l);
      hr=ht(T->r);
      return hl-hr;
   }
   
   avl*ll(avl*T)
   {
      avl*temp;
      temp=T->l;
      T->l=temp->r;
      temp->r=T;
      temp->bf=ht(temp);
      T->bf=ht(T);
      cout<<"\nLL rotation done";
      return temp;
      
      
   }
   
   avl*rr(avl*T)
   {
      avl*temp;
      temp=T->r;
      T->r=temp->l;
      temp->l=T;
      temp->bf=ht(temp);
      T->bf=ht(T);
      cout<<"\nRR rotation done";
      return temp;
      
      
   }
   
   avl*rl(avl*T)
   {
      T->r=ll(T->r);
      T=rr(T);
      cout<<"\nRL done";
      return T;
   }
   
   avl*lr(avl*T)
   {
      T->l=rr(T->l);
      T=ll(T);
            cout<<"\nLR done";
      return T;
   }
  void display_asc(avl*T)
  {  
     if(T!=NULL)
     {
       display_asc(T->l);
       cout<<"\nkeyword: "<<T->keyword<<"\t\tmeaning: "<<T->mean;
       display_asc(T->r);
     }
  }
  
   void display_des(avl*T)
  {  
     if(T!=NULL)
     {
       display_des(T->r);
       cout<<"\nkeyword: "<<T->keyword<<"\t\tmeaning: "<<T->mean;
       display_des(T->l);
     }
  }
  
  avl*find_min(avl*T)
  {
     while(T->l!=NULL)
     {
        T=T->l;

     }
     return T;
  }
  
  avl*del(avl*T,char data)
  {
     avl*temp;
     
     
     if(T==NULL)
     {
        return T;
     }
     else if(data<T->keyword)
     {
        T->l=del(T->l,data);
        
     }
     else if(data>T->keyword)
     {
        T->r=del(T->r,data);
        
     }
     else
     {
        if(T->l==NULL && T->r==NULL)
        {
           delete T;
           return NULL;
        }
        else if(T->l==NULL)
        {
          temp=T;
          T=T->r;
          delete temp;
        }
        else if(T->r==NULL)
        {
          temp=T;
          T=T->l;
          delete T;
        }
        else
        {
        temp=find_min(T->r);
        T->keyword=temp->keyword;
        T->r=del(T->r,temp->keyword);
        }
     }
   
   return T;  
  }
  
  avl*update(avl*T,char data)
  {
     char m[30];
     while(T->keyword!=data)
     {
        if(data>T->keyword)
            T=T->r;
        else
            T=T->l;
        if(T==NULL)
        {
           cout<<"\nnot found";
           return T;
        }
        
     }
     if(T->keyword==data)
     {
       cout<<"enter new meaning for "<<data<<" :";
     cin>>m;
     strcpy(T->mean,m);
     }
     return T;
  }
  
  avl*search(avl*T,char b,int &c)
  {
     c++;
     if(T==NULL)
     {
       return NULL;
     }
     if(T->keyword==b)
     {
       return T;
     }
     if(b<T->keyword)
  {
     return search(T->l,b,c);
  }
  return search(T->r,b,c);
  }
  
  
  void menu()
  {
     int ch;
     char c;
 
 do
 {
    cout<<"\n1:create\n2:display_asc \n3:display_des \n4:delete \n5:update \n6:search \n7:exit ";
    cout<<"\nenter your choice:";
    
    cin>>ch;
    
    switch (ch)
  {  
    case 1:
         create();
         
         break;
    case 2:
        cout<<"\nAscending order";
        display_asc(root);
        break;
    
    case 3:
        cout<<"\nDescending order";
        display_des(root);
        break;
    case 4:
          char keyword;
          cout<<"\nenter the keyword to delete";
           cin>>keyword;
          root=del(root,keyword);
          display_asc(root);
          break;
   case 5:
        {
         char keyword;
         cout<<"\nenter keyword to update: ";
         cin>>keyword;
         root=update(root,keyword);
         cout<<"\nafter upadating "<<keyword;
         display_asc(root);
         
       }
       break;
   case 6:
         {
           char keyword;
           cout<<"\nenter keyword to search: ";
           cin>>keyword;
           int c=0;
           if(search(root,keyword,c)!=NULL)
           {
              cout<<"\ntotal comparisions to search keyword "<<keyword<<" is "<<c;
           }
           else
           {
           cout<<"\nnot found";
           }
         }
         break;
   
   
    
   case 7:
        cout<<"\n EXIT ";
        break;
        
    default:
          cout<<"\nwrong choice";     
  }
  cout<<"\ndo you want to continue";
  cin>>c;
  }while(c=='y');
  }
  
  
};

int main()
{  
   avlop a;
   a.menu();
   return 0;
}
