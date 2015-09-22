#include <bits/stdc++.h>
using namespace std;
#define pb   push_back
#define maxn    100010
#define lgmaxn  100

vector<int> graph[maxn];
int N,visited[maxn]={0},P[maxn][lgmaxn],T[maxn],L[maxn],log2_[maxn];

void init()
{
	log2_[0]=0;log2_[1]=0;log2_[2]=1;
	int cmp=4;
	for(int i=3;i<=100000;i++){
		if(cmp>i) log2_[i]=log2_[i-1];
		else{
			log2_[i]=log2_[i-1]+1;
			cmp<<=1;
		}
	}
}

void bfs(int node)
{
    visited[node]=1;
    int temp,i;
    queue<int> Q;
    Q.push(node);
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
                visited[graph[temp][i]]=1;
                Q.push(graph[temp][i]);
                T[graph[temp][i]]=temp;
                L[graph[temp][i]]=L[temp]+1;
            }
        }
    }
}

void make_P()
{
    int i,j;
    // initialise by -1 all
    for(i=0;i<=N;i++)
        for(j=0;1<<j<=N;j++)
            P[i][j]=-1;
    // all the 2^0 i.e first ancestor will be itself
    for(i=1;i<=N;i++)
        P[i][0]=T[i];

    // bottom up dp
    for(j=1;1<<j<=N;j++)
        for(i=1;i<=N;i++)
            if(P[i][j-1]!=-1)
                P[i][j]=P[P[i][j-1]][j-1];

    /*for(j=0;1<<j<=N;j++)
    {
        cout<<j<<" : ";
        for(i=1;i<=N;i++)
        {
            cout<<P[i][j]<<" ";
        }
        cout<<"\n";
    }*/
}

int query(int p,int q)
{
    int log,i,tmp;

    // without any loss in generality we always take p at higher level
    // if its not so just swap them
    if(L[p]<L[q])
        tmp=p,p=q,q=tmp;

    // finding [log[L[p]]] ie ceil of it

    //for(log=1;(1<<log)<=L[p];log++)
      //  log--;
    log=log2_[L[p]];
    // now ie if not in same level then we have to find ancestor of p
    // at the same level as that of q from P[][lgmaxn]
    for(i=log;i>=0;i--)
    {
        if(L[p]-(1<<i) >= L[q])
            p=P[p][i];
    }

    // we have find ancestor
    if(p==q)
        return q;


        for(i=log;i>=0;i--)
        {
            if(P[p][i]!=-1 && P[p][i]!=P[q][i])
            {
                p=P[p][i];
                q=P[q][i];
            }
        }
        return T[p];
}

int main()
{
    int Q,edges,i,u,v;
    cin>>N>>Q;
    cin>>edges;
    for(i=0;i<edges;i++)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    bfs(1);
    make_P();
    while(Q--)
    {
        cin>>u>>v;
        cout<<query(u,v)<<"\n";
    }
    return 0;
}
