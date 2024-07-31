#include<iostream>
using namespace std;
#define max 15
typedef struct q
{int data[max];
  int f,r;
  }q;
class job
{   public:
       void init(q*p)
       {p->r=p->f=-1;}
       
      int full(q*p)
        {if(p->r==max-1)
           return(1);
         return(0); 
          }
     int empty(q*p)
     {if(p->r==-1)
           return(1);
         return(0); 
         }
     void enque(q*p,int x)
     {if(p->r==-1)
        {p->r=p->f=0;
          p->data[p->r]=x;
          }
      else
        {p->r=p->r+1;
         p->data[p->r]=x;
         }
    }
    int deque(q*p)
    {int x=p->data[p->f];
      if(p->r==p->f)
      {p->r=p->f=-1;
      }
      else
      {p->f=p->f+1;
      }
      return(x);      
      
    }
    void display(q*p)
    {for(int i=p->f;i<=p->r;i++)
      cout<<p->data[i]<<"  ";
      }
}f;
int main()
{q p;
  char a;
 int x,i,ch;
 f.init(&p);
 do
 {cout<<"\nMENU \n1:create \n2:insert \n3:del \n4:display";
  cout<<"\nenter choice";
  cin>>ch;
  switch(ch)
  {case 1:
       cout<<"\ntotal no. of jobs to enter: ";
       cin>>i;
       for(int j=0;j<i;j++)
       {if(!f.full(&p))
           {cout<<"enter ele: ";
             cin>>x;
             f.enque(&p,x);
             }
        else
        {cout<<"\nfull";
        }
             }break;
    case 2:
      if(!f.full(&p))
           {cout<<"enter ele: ";
             cin>>x;
             f.enque(&p,x);
             }
        else
        {cout<<"\nfull";
        }
        break;
     case 3:
       if(!f.empty(&p))
           {x=f.deque(&p);
           cout<<"ele deleted is"<<x<<endl;}
       else
       {cout<<"\nempty";
       }
       break;
     case 4:
        cout<<"\nqueue is:" ;
        f.display(&p);
        break;
        default:cout<<"wromg choice entered";
         }cout<<"wanna continue";
         cin>>a;
         }while(a=='y' || a=='Y');
         cout<<endl;
         return 0;
         }

