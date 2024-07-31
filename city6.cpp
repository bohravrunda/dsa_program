#include<iostream>
#include<string>
#define max 20
using namespace std;
typedef struct node
{
  struct node*next;
  string vertex;
  int time;
}node;

node*G1[max];

void read_matrix(int G[max][max],string v[],int n)
{
   char ch;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
       cout<<"if path is present bet "<<v[i]<<" and "<<v[j]<<" press y or else n  :  ";
       cin>>ch;
       if(ch=='y')
       {
         cout<<"\nenter time to reach in hrs: ";
         cin>>G[i][j];
       }
       else if(ch=='n')
       {
         G[i][j]=0;
       }
      } 
   }      
}

void display_matrix(int G[max][max],int n)
{
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
       
           cout<<G[i][j]<<" ";
           
        }   
        cout<<endl;
    }    
}

int get_idx(string s1,int n)
{
   for(int i=0;i<n;i++)
   {
      if(G1[i]->vertex==s1)
         return i;
   }
   
   return -1;
}

void insert(string city1,string city2,int fcost,int n)
{
    node*source,*dest;
   dest= new node;
   dest->next=NULL;
   dest->vertex=city2;
   dest->time=fcost;
   int idx=get_idx(city1, n);
   source=G1[idx];
   while(source->next!=NULL)
   {
      source=source->next;
   }
    source->next=dest;
   
}

void read_list(int n)
{
    string city1,city2;
    int fcost;
    int flight;
    for(int i=0;i<n;i++)
    {
       G1[i]=new node;
       G1[i]->next=NULL;
       cout<<"\nenter city name:";
       cin>>G1[i]->vertex;
    }
    cout<<"\nenter no. of flights:\n";
    cin>>flight;
    for(int i=0;i<flight;i++)
    {
       cout<<"\nenter source city: ";
       cin>>city1;
       cout<<"\nenter destination city: ";
       cin>>city2;
       cout<<"\nenter time to reach in hrs: ";
       cin>>fcost;
       insert(city1,city2,fcost,n);
       
       
       
    }
}

void display_list(int n)
{
   node*p;
   for(int i=0;i<n;i++)
   {
      p=G1[i];
      while(p!=NULL)
      {
         cout<<p->vertex<<"->";
         p=p->next;
      }
      cout<<"NULL"<<endl;
   }
}

int main()
{
   int n;
   cout<<"\nenter no. of cities:";
   cin>>n;
   int ch;
   while(true)
   {
     cout<<"\n1:ADJANCENCY MATRIX";
     cout<<"\n2:ADJANCENCY LIST";
     cout<<"\n3:EXIT";
     cout<<"\nenter choice: ";
     cin>>ch;
     if(ch==1)
     {
   
        string v[20];
        cout<<"\nEnter cities name:\n";
       for(int i=0;i<n;i++)
      {
         cin>>v[i];
      }
       int G[max][max];
       read_matrix(G, v,n);
       cout<<"\nADJACENT MATRIX IS:\n";
        display_matrix( G,n);
   }
   
   else if(ch==2)
   {
      read_list(n);
      cout<<"\nADJANCENCY LIST IS:\n";
      display_list(n);
      
   }
   
   else
   {
      cout<<"\nwrong choice";
      break;
   }
   return 0;
}
}
