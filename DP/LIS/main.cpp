#include <bits/stdc++.h>
using namespace std;
#define pb  push_back

vector<int> a;
int lis[100000],n;


//O(n^2) implementation of lis
void lis_n2()
{
    int i,j;
    for(i=0;i<=n;i++)
        lis[i]=1;
    for(i=1;i<n;i++)
        for(j=0;j<i;i++)
        {
            if(a[j]<a[i] && lis[i]<(lis[j]+1))
                lis[i]=lis[j]+1;
        }

    for(i=0;i<n;i++)
        cout<<lis[i]<<" ";
    // find maximum from lis array to get answer :p
}

// nlogn method     , for explanation  http://ideone.com/C4jI6o , as we know set maintain in sorted order :p
int lis_nlogn()
{
    set<int> s;
    set<int>::iterator k;
    set<int>::iterator pp;      // to str elemtents ;)

    s.clear();
    for(int i=0;i<n;i++)
    {
        if(s.insert(a[i]).second)
        {
            k=s.find(a[i]);
            k++;                    // make it to next index
            if(k!=s.end())          // if at ast index the a[[i] is not present delete it ;)
                s.erase(k);
        }
    }

    for(k=s.begin();k!=s.end();k++)
        cout<<*k<<" ";      // LIS array :p
    return s.size();    // max LIS

}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int i,temp;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>temp;
        a.pb(temp);
    }
    //lis_n2();
    int ans=lis_nlogn();
    cout<<ans<<endl;
    return 0;
}
