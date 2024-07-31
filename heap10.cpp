#include<iostream>
using namespace std;

void downadj1(int heap[],int i)
{
    int n ,j,temp,flag=1;                                               

    n=heap[0];
    while(i*2<n && flag==1)
    {
      j=i*2;
      if(j+1<=n && heap[j+1]>heap[j])
      {
          j=j+1;
      }
      if(heap[i]>heap[j])
      {
          flag=0;
      }
      else
      {
         temp=heap[i];
         heap[i]=heap[j];
         heap[j]=temp;
         i=j;
      }
    }
}

void create_max(int heap[])
{
   int i,n;
   n=heap[0];
   for(i=n/2;i>=1;i--)
   {
       downadj1(heap,i);
   }
}



void downadj2(int heap[],int i)
{
   int n,temp,flag=1,j;
   n=heap[0];
   while(i*2<=n && flag==1)
   {
      j=i*2;
      if(j+1<=n && heap[j+1]<heap[j])
      {
         j=j+1;
      }
      
      if(heap[i]<heap[j])
      {
          flag=0;
      }
      
      else
      {
        temp=heap[i];
        heap[i]=heap[j];
        heap[j]=temp;
        i=j;
      }
   }
   
}



void create_min(int heap[])
{
   int i,n;
   n=heap[0];
   for(i=n/2;i>=1;i--)
   {
     downadj2(heap,i);
   }
}


void display(int heap[])
{
   int i,n;
   n=heap[0];
   for(i=1;i<=n;i++)
   {
      cout<<heap[i]<<"  ";
      
   }
}

int main()
{
   int heap[30],n,i;
   cout<<"\nenter total no. of students: ";
   cin>>n;
   heap[0]=n;
   cout<<"\nenter examination marks for students:\n";
   for(i=1;i<=n;i++)
   {
      cin>>heap[i];
   }
   display(heap);
   create_max(heap);
   cout<<"\nmax marks is :  "<<heap[1];
   create_min(heap);
   cout<<"\nmin marks is :  "<<heap[1];
   return 0;
   
}
