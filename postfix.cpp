#include<iostream>
#include<stdlib.h>
#include<ctype.h>
using namespace std;
typedef struct stack
  {char data[100];
   int top;
   }stack;
void create(stack*s)
 {s->top=-1;
  }
void push(stack*s,int x)
  {if(s->top==100-1)
      {cout<<"stack overflow";
      }
    else
      {s->top=(s->top)+1;
       s->data[s->top]=x;
        }
   }
int pop(stack*s)
  {char x='\0';
   if(s->top==-1)
     {cout<<"under overflow";
      }
    else
      {x=s->data[s->top];
       s->top=(s->top)-1;
      }return(x);
    }

 

int prec(char x)
{  if(x=='(')
     return(0);
    if(x=='+' || x=='-')
     return(1);
    if(x=='*' || x=='/')
    return(2);
    return(3);
  }
  
void infix_postfix(char infix[20],char postfix[20],stack*s)
{    char x,op;
      int j=0;
      for(int i=0;infix[i]!='\0';i++)
      {  x=infix[i];
        if(isalnum(x))
          {postfix[j++]=x;
          }
         else if(x=='(')
          {push(s,'(');
          }
          else if(x==')')
          {while((op=pop(s))!='(')
              postfix[j++]=op;
              }
           else 
           {while(prec(x)<=prec(s->data[s->top]) && s->top!=-1)
             {op=pop(s);
             postfix[j++]=op;
             }
           push(s,x);
           }
     }
while(s->top!=-1)
{op=pop(s);
postfix[j++]=op;
}
postfix[j]='\0';
 }
 
 int eval(char x,int op1,int op2)
 { if(x=='+')
     return(op1+op2); 
   if(x=='-')
     return(op1-op2); 
   if(x=='*')
     return(op1*op2); 
   if(x=='/')
     return(op1/op2); 
 }
 
 void postfix_eval(char postfix[20],stack*s)
 {char x;
 int y,op1,op2;
 int val;
 for(int i=0;postfix[i]!='\0';i++)
   {x=postfix[i];
   if(isalpha(x))
     {cout<<"\nenter value of x: "<<x;
       cin>>y;
       push(s,y);
       }
    else if(isdigit(x))
    {y=x-48;
      push(s,y);
      }
     else
     {op2=pop(s);
     op1=pop(s);
     val=eval(x,op1,op2);
     push(s,val);
     }
      }
val=pop(s);
cout<<"\nvalue is"<<val;

  }
int main()
{stack s;
 create(&s);
 char infix[20],postfix[20];
 cout<<"\ninfix exp is";
 cin.getline(infix,20);
 infix_postfix(infix,postfix,&s);
 cout<<"\npostfix exp is: "<<postfix;
 create(&s);
 cout<<"\npostfix evalution";
 postfix_eval(postfix,&s);
 cout<<endl;
 return 0;
 }  
