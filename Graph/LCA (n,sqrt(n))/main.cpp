#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define pb  push_back
#define mp  make_pair
#define maxn    100010

int visited[maxn]={0},T[maxn],P[maxn],L[maxn],nr,N;
vector<int> graph[maxn];

// T[i] -> parent of ith node
// P[i] -> just above section ki last row wala & for 1st section its 1
// L[i] -> level of node i
// nr   -> something like number of sections (sqrt(N))
// via dfs we make our array P[] then apply LCA of P[]
void dfs(int node,int T[],int N,int P[],int L[],int nr)
{
    visited[node]=1;
    // if node at 1st section P[node]=1
    // if at beginning of some section then P[node]=T[node]
    // none of above 2 cases then P[node]=P[T[node]]

    if(L[node]<nr)
    {
        P[node]=1;
    }
    else
    {
        if(!(L[node]%nr))      // check beginning of any of the section or not
        {
            P[node]=T[node];
        }
        else
        {
            P[node]=P[T[node]];
        }
    }

    for(int k=0;k<graph[node].size();k++)
    {
        if(!visited[graph[node][k]])
            dfs(graph[node][k],T,N,P,L,nr);
    }

}

int LCA(int T[],int P[],int L[],int x,int y)
{
    // as long as the node in the next section of
    // x and y is not one common ancestor
    // we get the node situated on the smaller
    // lever closer

    while(P[x]!=P[y])
    {
        if(L[x]>L[y])
            x=P[x];
        else
            y=P[y];
    }

    // now they are in the same section, so we trivially compute the LCA

    while(x!=y)
    {
        if(L[x]>L[y])
            x=T[x];
        else
            y=T[y];
    }
    return x;
}

void bfs(int node)
{
    int i,temp;
    memset(visited,0,sizeof visited);
    queue<int> Q;
    temp=node;
    Q.push(node);
    visited[node]=true;
    T[node]=node;
    L[node]=0;
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();
        for(i=0;i<graph[temp].size();i++)
        {
            if(!visited[graph[temp][i]])
            {
                L[graph[temp][i]]=L[temp]+1;
                Q.push(graph[temp][i]);
                T[graph[temp][i]]=temp;
                visited[graph[temp][i]]=1;
            }
        }
    }
    // print T[i] i.e father of i
  //  for(i=1;i<=N;i++)
    //    cout<<i<<" - "<<T[i]<<" "<<L[i]<<endl;
}

int main()
{
    int i,u,v,edges,x,y,q;
    cin>>N>>q;
    cin>>edges;
    for(i=1;i<=edges;i++)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    nr=2;
    bfs(1);
    memset(visited,0,sizeof visited);
    dfs(1,T,N,P,L,nr);
    for(i=1;i<=N;i++)
        cout<<P[i]<<" ";
    cout<<"\n";
    while(q--)
    {
        cin>>x>>y;
        cout<<LCA(T,P,L,x,y)<<"\n";
    }

    return 0;
}
