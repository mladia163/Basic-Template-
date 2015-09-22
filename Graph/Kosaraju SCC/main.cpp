// http://ideone.com/vsX5ob  - For checking at each point
// Algo being simple
// dfs of original graph and take revesed post order i.e. finis time ke hisaab se stack mei daal do vertex ko
// ab again dfs on ( transposed graph ) i.e. reversed graph via popping out from stack

#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
vector<int> revgraph[100010];
stack<int> finish_time;
int visit[100010];

void dfs(int v)
{
    visit[v]=1;
    for(int i=0;i<graph[v].size();i++)
        if(visit[graph[v][i]]==0)
            dfs(graph[v][i]);
    finish_time.push(v);
}

void dfsrevisit(int v)
{
    visit[v]=1;
    cout<<v<<" ";
    for(int i=0;i<revgraph[v].size();i++)
        if(visit[revgraph[v][i]]==0)
            dfsrevisit(revgraph[v][i]);
}

int main()
{
    int i,n,u,v,edges;
    cin>>n>>edges;
    for(i=0;i<=n;i++)
    {
        graph[i].clear();
        revgraph[i].clear();
    }
    memset(visit,0,sizeof visit);

    for(i=1;i<=edges;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }

    while(!finish_time.empty())
        finish_time.pop();

    for(i=1;i<=n;i++)
        if(visit[i]==0)
            dfs(i);
    memset(visit,0,sizeof visit);

    while(!finish_time.empty())
    {
        int temp=finish_time.top();
        finish_time.pop();

        if(visit[temp]==0)
        {
            dfsrevisit(temp);
            cout<<"\n";
        }
    }

    return 0;
}
