#include <bits/stdc++.h>
using namespace std;
string a,b;

int lcs(int m,int n)
{
    int kp[m+1][n+1],i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                kp[i][j]=0;
            else if(a[i-1]==b[j-1])
                kp[i][j]=1+kp[i-1][j-1];
            else
                kp[i][j]=max(kp[i-1][j],kp[i][j-1]);
        }
    }
    //printing 2d array :p
    /*for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
            cout<<kp[i][j]<<" ";
        cout<<endl;
    }*/
    return kp[m][n];
}


int lcs_less_memory(int m,int n)        // highly optimised (taken care of the memory)
{
    //int h1[n+1],h2[n+1],i,j,temp=0,h[2][n+1];
    int h[2][n+1],i,j;
    for(i=0;i<n;i++)
    {
        //h1[i]=h2[i]=0;
        h[1][i]=h[0][i]=0;
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1])
                h[i%2][j]=1+h[(i-1)%2][j-1];
            else
                h[i%2][j]=max(h[(i-1)%2][j],h[i%2][j-1]);
            /*if(a[i-1]==b[j-1])    h2[j]=1+h1[j-1];
            else    h2[j]=max(h1[j],h2[j-1]);*/
        }
        //for(j=0;j<=n;j++)     // in order to remove this loop i have make % wala system :p
          //  h1[j]=h2[j];
    }
    return h[(i-1)%2][n];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    //int i,temp;
    cin>>a>>b;
    int m=a.length();
    int n=b.length();
    int ans=lcs_less_memory(m,n);

    cout<<ans<<endl;
    return 0;
}
