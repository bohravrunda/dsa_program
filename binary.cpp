#include<iostream>
#include<cstdio>
using namespace std;
typedef struct dnode
{  int data;
    struct dnode*next,*prev;
}dnode;
dnode*create();
void print(dnode*head);
dnode*add(dnode*head1,dnode*head2);
void ones(dnode*head);
void twos(dnode*head);
int main()
{ dnode*head1,*head2,*head3;
   cout<<"1st binary no.";
   head1=create();
   print(head1);
   cout<<"2st binary no.";
   head2=create();
   print(head2);
   cout<<"addition";
   head3=add(head1,head2);
   print(head3);
   cout<<"ones compement";
   ones(head1);
   print(head1);
   cout<<"twos compement";
   ones(head2);
   print(head2);
   
}
dnode*create()
{  int x;
   dnode*head,*p;
   head=NULL;
   cout<<"\nbinary no. is";
   while((x=getchar())!='\n')
   {   if(head==NULL)
        {head=p=new dnode;
         p->next=p->prev=NULL;
         }
        else
        {p->next=new dnode;
         (p->next)->prev=p;
         p=p->next;
         p->next=NULL;
         }
         if(x=='1')
         {p->data=1;
         }
         else
         {p->data=0;
         }
   }return(head);
          
 }
 void print(dnode*head)
 {  cout<<"\nbinary no. is: ";
     dnode*p;
     p=head;
     while(p!=NULL)
     {cout<<p->data<<" ";
     p=p->next;
     }
}
dnode*add(dnode*head1,dnode*head2)
{    int sum=0,carry=0,x=0,y=0;
     dnode*head;
     head=NULL;
     while(head1->next!=NULL)
     {head1=head1->next;
     }
     while(head2->next!=NULL)
     {head2=head2->next;
     }
     while(head1!=NULL || head2!=NULL)
     {   if(head1!=NULL)
           {x=head1->data;
            head1=head1->prev;
            }
             if(head2!=NULL)
           {x=head2->data;
            head2=head2->prev;
            }
            sum=(x+y+carry)%2;
            carry=(x+y+carry)/2;
             if(head==NULL)
        {head=new dnode;
         head->next=head->prev=NULL;
         }
        else
        {head->prev=new dnode;
         (head->prev)->next=head;
         head=head->prev;
         head->prev=NULL;
         }
         head->data=sum;
         }
head->prev=new dnode;
         (head->prev)->next=head;
         head=head->prev;
         head->prev=NULL;
         head->data=carry;        
 
 }
 void ones(dnode*head)
 {dnode*p;
  p=head;
  
  while(p!=NULL)
  {if(p->data==1)
     {p->data=0;
     }
     else
     {p->data=1;
     }
     p=p->next;
     
 }}
void twos(dnode*head)
{ dnode*p;
  p=head;
  while(p->next!=NULL)
  { p=p->next;}
   if(p->data=='0' && p!=NULL)
    {p=p->prev;
    }
    if(p!=NULL)
    {p=p->prev;
    }
    while(p!=NULL)
    {if(p->data==1)
    {p->data=0;
    }
    else
    {p->data=1;
    }
    p=p->next;}
    }
