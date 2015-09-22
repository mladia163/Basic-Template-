#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n,m,a,b,i;
bool visited[10000];
vector<int> tree[1000];

//list<int> q;
//stack<int> s;
int in[1001];
set<int> s;
map<int,list<int> > my;
vector<int> sorted_order;

void dfs_temp(int v)
{
    visited[v]=true;
    my[in[v]].remove(v);
    if(!my[in[v]].size())
        s.erase(in[v]);
   // cout<<v<<" ";
    for(i=0;i<tree[v].size();i++)
        if(!visited[tree[v][i]])
            dfs_temp(tree[v][i]);

    sorted_order.pb(v);
}



void dfs_s()
{
//	cout<<in[4]<<" ";
	for(int i=0;i<n;i++)
	{
		//s.insert(i);
	   my[in[i]].pb(i);
	   s.insert(in[i]);
	}

  //	cout<<*my[0].begin()<<" ";
    //visited[root]=true;

    while(!s.empty())
    {
        int temp2;
        while(!my.count(*s.begin()) || my[*s.begin()].size()==0)
            s.erase(s.begin());

        temp2=my[*s.begin()].back();
        my[*s.begin()].pop_back();

        dfs_temp(temp2);
        //cout<<s.size()<<" ";
        //exit(0);
        //s.pop();
        //cout<<temp2<<" ";
        /*
        for(i=tree[temp2].size()-1;i>=0;i--)
        {
            if(!visited[tree[temp2][i]])
            {
                visited[tree[temp2][i]]=true;
                s.push(tree[temp2][i]);
            }
        }
        */
    }

}

int main()
{
    cin>>n;
    for(i=0;i<1000;i++)
    {
        visited[i]=false;
        tree[i].clear();
    }
  //  while(!q.empty())
    //    q.pop_front();

    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        tree[a].push_back(b);
        in[b]++;
      // tree[b].push_back(a);
    }
    //cin>>m;
    dfs_s();
    reverse(sorted_order.begin(),sorted_order.end());
    for(int i=0;i<sorted_order.size();i++)cout<<sorted_order[i]<<" ";
    return 0;
}
