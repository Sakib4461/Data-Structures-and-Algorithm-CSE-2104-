#include<bits/stdc++.h>

using namespace std;

int adj[100][100];
int color[100];
int prev[100];
int d[100];
int n,e;

void bfs(int s)
{

    for(int i=0; i<n; i++)
    {

        if(i!=s)
        {
            color[i]=0;
            prev[i]=-1;
            d[i]=10204000;
        }

    }

    color[s]=1;
    d[s]=0;
    prev[s]=-1;

    queue <int> Q;
    Q.push(s);


    while(Q.empty()==0)
    {
        int u=Q.front();
        Q.pop();

        for(int i=0; i<n; i++)
        {
            if(adj[u][i]==1)
            {
                if(color[i]==0)
                {

                    printf("%d -> %d\n",u,i);
                    color[i]=1;
                    prev[i]=u;
                    d[i]=d[u]+1;
                    Q.push(i);
                }
            }
        }
        color[u]=2;


    }

}

int main()
{

    int u,v;
    cin>>n>>e;


    for (int i=0; i<e; i++)
    {

        cin>>u>>v;

        adj[u][v]=1;
        adj[v][u]=1;

    }

    bfs(0);


    printf("Here is the previous array.\n");

    for(int i=0; i<n; i++)
    {
        printf("%d --> %d\n", i,prev[i]);
    }


    printf("Here is the distance\n");
    for(int i=0; i<n; i++)
    {
        printf("%d --> %d\n", i,d[i]);
    }


}
