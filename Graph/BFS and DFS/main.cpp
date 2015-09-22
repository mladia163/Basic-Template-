#include <bits/stdc++.h>
using namespace std;


int n,m,a,b,i;
bool visited[10000];
vector<int> tree[1000];
list<int> q;
stack<int> s;

void bfs(int temp)
{
    visited[temp]=true;
    q.push_back(temp);

    while(!q.empty())
    {
        int temp2=q.front();
        cout<<temp2<<" ";
        q.pop_front();
        for(i=0;i<tree[temp2].size();i++)
        {
            if(!visited[tree[temp2][i]])
            {
                q.push_back(tree[temp2][i]);
                visited[tree[temp2][i]]=true;
            }
        }
    }

}


void dfs_s(int root)                // only for connected graph :p
{
    visited[root]=true;
    s.push(root);
    while(!s.empty())
    {
        int temp2=s.top();
        s.pop();
        cout<<temp2<<" ";
        for(i=tree[temp2].size()-1;i>=0;i--)
        {
            if(!visited[tree[temp2][i]])
            {
                visited[tree[temp2][i]]=true;
                s.push(tree[temp2][i]);
            }
        }
    }

}

void dfs_temp(int v)
{
    visited[v]=true;
    cout<<v<<" ";
    for(i=0;i<tree[v].size();i++)
        if(!visited[tree[v][i]])
            dfs_temp(tree[v][i]);
}



int main()
{
    cin>>n;
    for(i=0;i<1000;i++)
    {
        visited[i]=false;
        tree[i].clear();
    }
    while(!q.empty())
        q.pop_front();

    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        tree[a].push_back(b);
      // tree[b].push_back(a);
    }
    ///cin>>m;
    //dfs_temp(m);
    return 0;
}




