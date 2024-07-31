#include<iostream>
#include<cstdlib>
using namespace std;
class pizza
{ int f,r,q[5];
  public:
   pizza()
   { f=-1;
     r=-1;
    } 
     
   int isfull()
   {if(f==(r+1)%5)
     {return(1);
    }
    else
     {return(0);}
    }
   
    int isempty()
    {if(r==-1)
     {return(1);
    }
    else
     {return(0);}
    }
    
   void add()
   {    if(!isfull())
          {  cout<<"\nenter pizza ID";
           if(r==-1)
              {r=0;
                cin>>q[r];
             }
          else
            {r=(r+1)%5;
              cin>>q[r];
             }
       char c;
      cout<<"do yo want to add more";
      cin>>c;
      if(c=='y' || c=='Y')
        add();
    }   
   else
    {cout<<"full";
     
     }
    

   }
 void serve()
  {    if(isempty()==0)
         {  
           if(r==f)
              {cout<<"served"<<q[f];
               r=f=-1 ;
             }
          else
            {cout<<"served"<<q[f];
              f=(f+1)%5;
             }
        } 
   
   else
    {cout<<"empty";
     
     }
    
       
   }
void display()
{  if(isempty()==0)
    {for(int i=f;i<r;i=(i+1)%5)
      {cout<<q[i]<<"  ";}
       
    cout<<q[r];
     }
  else
   {cout<<"empty";
  }
  }
 void check()
 { 
    int ch;
    char a;
  do
     {cout<<" \nmenu \n1:add \n2:display \n3:serve ";
      cout<<"\nenter choice";
       cin>>ch;
      switch(ch)
       {case 1:
             add();
              break;
        case 2:
             display();
              break;
      case 3:
             serve();
              break;
   default:cout<<"\nwrong choice";
      }cout<<"wanna continue";
      
      cin>>a;
      }while(a=='y' || a=='Y');
       check();
}
};
int main()
{   pizza p1;
  p1.check();
  return 0;
}


