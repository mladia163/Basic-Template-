#include <bits/stdc++.h>
using namespace std;
//#define pii  pair< int , int >
#define YY  1e15
typedef pair< int, int > pii;

vector< pii > graph[100000];
int d[100000];


void dijkstra(int start)
{
    int t1,i,u,v,cost=0;
    // making such that it will give minimum value at first sight
    priority_queue< pii, vector< pii >, greater< pii > > Q;
    memset(d,0x3f,sizeof(d));
    d[start]=0;        // from where i have to start
    Q.push(pii(d[start],start));

    while(!Q.empty())
    {
        u = Q.top().second;     // node
        cost = Q.top().first;   // value of node
        Q.pop();

        if(d[u]<cost)   continue;       // already better value so neglect this one

        for(i=0;i<graph[u].size();i++)
        {
            v = graph[u][i].first;          // node
            t1 = graph[u][i].second;        // value
            if(d[v]>(d[u]+t1))
            {
                d[v]=d[u]+t1;
                Q.push(pii(d[v],v));
            }
        }
    }
}

int main()
{
    int st,w,i,v,e,x,y;
    cin>>v>>e;
    for(i=0;i<=v;i++)
        graph[i].clear();

    for(i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        graph[x].push_back(pii(y,w));
        graph[y].push_back(pii(x,w));   // if bidirectional only
    }
    cin>>st;
    dijkstra(st);

    for(i=0;i<=v;i++)
    {
        if(i==st)   continue;
        if(d[i]>=YY)    cout<<i<<" - not reachable"<<endl;
        else    cout<<i<<" - "<<d[i]<<endl;
    }

    return 0;
}
