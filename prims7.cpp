#include<iostream>
using namespace std;
#define max 20
#define infinity 9999
class graph
{
  public:
  int span[max][max];
  int G[max][max];
  int n;
  string city[max];
      
      void accept()
      {
         int i;
         
         cout<<"\nno. of cities:\n";
         cin>>n;
         cout<<"\nenter name:\n";
         for(i=0;i<n;i++)
         {
            cin>>city[i];
         }
   
         
      }
  


       void read()
      {
            cout<<"\nenter adjencey matrix that connect phone lines: \n";
            cout<<"\nenter company charges:\n";
            for(int i=0;i<n;i++)
            {   
                for(int j=0;j<n;j++)
                {
                    cin>>G[i][j];
                }
     
              cout<<endl;
     
             }
       }

       void display()
       {
           for(int k=0;k<n;k++)
           {
              cout<<"\t"<<city[k];
           }
   
            for(int i=0;i<n;i++)
             {   
                 cout<<endl;
                 cout<<"\t"<<city[i]<<"\t";
                 for(int j=0;j<n;j++)
                 {
                     cout<<span[i][j]<<" ";
                  }
     
                        cout<<endl;
     
               }
        }

        int prims()
       {
           int i,j,u,v,cost[max][max],visit[max],from[max],dist[max],edges;
              int min_cost=0;
               for( i=0;i<n;i++)
               {   
                 for( j=0;j<n;j++)
                 {
                       if(G[i][j]==0)
                      {
                         cost[i][j]=infinity;
                       }
                               cost[i][j]=G[i][j];
                        span[i][j]=0;
                     }
     
    
     
            }
   
                 visit[0]=1;
                 dist[0]=0;
                 for(i=1;i<n;i++)
                {
                        dist[i]=cost[0][i];
                        visit[i]=0;
                        from[i]=0;
                 }
                edges=n-1;
                while(edges>0)
               {
                      int min_dist=infinity;
                         for(i=1;i<n;i++)
                        {
                                if(visit[i]==0 && dist[i]<min_dist)
                                {
                                     min_dist=dist[i];
                                      v=i;
                                     }
                              }
       
                       u=from[v];
                       span[u][v]=span[v][u]=cost[u][v];
                       edges--;
                       visit[v]=1;
                       for(i=1;i<n;i++)
                        {
                              if(visit[i]==0 && cost[i][v]<dist[i])
                                {
                                     dist[i]=cost[i][v];
                                        from[i]=v;
                                       }
          
                          }
                       min_cost=min_cost+cost[u][v];
                      }
                 return(min_cost);
           }
 };

int main()
{
   graph g;
   
   g.accept();
   g.read();
  
   
   int total=g.prims();
   cout<<"\nSPANNING MATRIX IS :\n";
   g.display();
   cout<<"\nmin cost is: "<<total<<endl;
   return 0;
}
