#include <bits/stdc++.h>
using namespace std;

vector<int> graph[2000];
int color[2000];            // just for colouring
int visit[2000];             // for full graph visit


bool check_bipartiteness(int v)     // v is total n umber of vertices
{
    int i,j,temp;
    bool ans = true;        // let it be initially bipartite
    for(i=1;i<=v;i++)       // vertices from 1 to v
    {                               // we have run this loop for the disconnected graph
        if(visit[i]==0)
        {
            queue<int> q;       // now running simple code for bfs
            q.push(i);
            color[i]=1;
            while(!q.empty())
            {
                temp=q.front();
                visit[temp]=1;
                q.pop();
                for(j=0;j<graph[temp].size();j++)
                {
                    if(color[graph[temp][j]]==-1)           // if not coloured
                        color[graph[temp][j]]=1-color[temp];
                    else if(color[graph[temp][j]]==color[temp])     // if already coloured and color equals to the
                    {                                               // its color of parent hence breaks rule of bipartiteness
                        ans=false;                                  // so break it.... and no eed to chq further
                        break;
                    }
                    if(visit[graph[temp][j]]==0)
                        q.push(graph[temp][j]);
                }
                if(!ans)
                    break;
            }
        }
        if(!ans)
            break;
    }
    return ans;
}




int main()
{
    int a,b,v,n,i;
    cin>>v>>n;

    for(i=0;i<2000;i++)
    {
        graph[i].clear();
        visit[i]=0;      // visit node
        color[i]=-1;
    }

    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool ans_final = check_bipartiteness(v);

    if(ans_final)
        cout<<"Yes it is bipartite"<<endl;
    else
        cout<<"You are chuchu :p "<<endl;

    return 0;
}
