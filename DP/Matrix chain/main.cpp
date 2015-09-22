#include <bits/stdc++.h>
using namespace std;


int matrix(int p[],int n)
{
    int len=2,k,i,j,mini=INT_MAX,ans[n][n];
    for(i=0;i<n;i++)
        ans[i][i]=0;

    for(;len<n;len++)       // length of matrixes we are considering
    {
        for(i=1;i<=n-len+1;i++)     // starting to end how many we make
        {
            j=i+len-1;
            ans[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                mini=ans[i][k]+ans[k+1][j]+p[i-1]*p[k]*p[j];
                if(ans[i][j]>mini)
                    ans[i][j]=mini;
            }
        }
    }
    return ans[1][n-1]];
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
