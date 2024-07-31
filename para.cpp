
#include<iostream>
#include<cstdio>
using namespace std;
typedef struct stack
{ int data[100];
 int top;
 
}stack;
void create(stack*s)
{  s->top=-1;
}
void push(stack*s,int x)
{if(s->top==100-1)
 {cout<<"stack overflow";
 }
 else
  {s->top=s->top+1;
  s->data[s->top]=x;
  }
  }
 char pop(stack*s)
 {char x='\0';
  if(s->top==-1)
  {cout<<"stack underflow";
   return(x);
   }
   else
   {x=s->data[s->top];
    s->top=s->top-1;
    return(x);
    }
    }
int main()
{char x,y;
 int flag=0;
 stack s;
 create(&s);
 cout<<"enter parentezasid exp: ";
 while((x=getchar())!='\n')
  {if(x=='(' || x=='[' || x=='{')
   {push(&s,x);
   }
   else if(x==')' || x=='}' || x==']')
   {y=pop(&s);
   
   if(y=='(' && x==')' || y=='{' && x=='}' || y=='[' && x==']' )
      {flag=1;
      }
      else
       push(&s,y);
       }
       }
 if(flag==1 && s.top==-1)
 {cout<<"well formed";
 }
 else
 {cout<<"not well formed";
 }
 return 0;
 }
