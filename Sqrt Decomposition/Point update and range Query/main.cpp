// 1 Based indexing
#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define maxn    100100

ll arr[maxn],sqrt_arr[1000];

int main()
{
    ll temp,k,i,ch,N,l=0,ans=0,x,y,m,n;
    cin>>N;
    k=sqrt(N);

    for(i=1;i<=N;i++)
    {
        cin>>arr[i];
        if(i%k!=0)
        {
            sqrt_arr[l]+=arr[i];
        }
        else
        {
            sqrt_arr[l]+=arr[i];
            l++;
        }
    }

  /*  for(i=0;i<l;i++)
        cout<<sqrt_arr[i]<<" ";
    cout<<"\n";
  */
        ll Q;
    cin>>Q;

    for(i=0;i<Q;i++)
    {
        ans=0;
        cin>>ch;
        if(ch==1)
        {
            cin>>x>>y;
            sqrt_arr[x/k]+=(y-arr[x]);
            arr[x]=y;
          /*  for(i=1;i<=N;i++)
                cout<<arr[i]<<" ";
            cout<<"\n";
            for(i=0;i<l;i++)
                cout<<sqrt_arr[i]<<" ";
            cout<<"\n";*/
        }
        else
        {
            cin>>m>>n;
            temp=m;
            while((temp)%k!=0 && temp<=n)
                ans+=arr[temp],temp+=1;
            if(temp<=n)
                ans+=arr[temp];
      //      cout<<temp<<" - "<<ans<<endl;
            while((temp+k)<=n)
                ans+=sqrt_arr[temp/k],temp+=k;
        //    cout<<temp<<" - "<<ans<<endl;
            temp+=1;
            while(temp<=n)
                ans+=arr[temp],temp+=1;
      //      cout<<temp<<" -` "<<ans<<endl;
        }
    }






    return 0;
}
