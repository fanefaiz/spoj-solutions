//mixtures.cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define sf_d(var) scanf("%d",&var)
#define sf_2d(var1,var2) scanf("%d %d",&var1,&var2)
#define vi vector<int>
#define vvi vector< vector<int> >
#define pb push_back
#define v_iter vector<int>::iterator
#define v_riter vector<int>::reverse_iterator
#define fr_z(start,end) for(int z=start;z<end;z++)
#define fr_o(start,end) for(int o=start;o<end;o++)
#define w while
#define mod 1000000007
#define srt(cont) sort(cont.begin(),cont.end())
#define all(m) m.begin(),m.end()
#define mp make_pair
#define mprq(a,b) priority_queue< pair<a,b> ,vector< pair<a,b> >,greater< pair<a,b> > >
#define fa_io std::ios::sync_with_stdio(false)

int acc[101],arr[100],dp[100][100];

int recur(int l,int r)
{
    if(r==l || r<l)
        return 0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    dp[l][r]=recur(l,l)+recur(l+1,r)+(((acc[r+1]-acc[l+1])%100)*(arr[l]%100));
    for(int i=l;i<r;++i)
        dp[l][r]=min(dp[l][r],recur(l,i)+recur(i+1,r)+(((acc[r+1]-acc[i+1])%100)*((acc[i+1]-acc[l])%100)));
    return dp[l][r];
}

int main()
{
    fa_io;
    cin.tie(NULL);

    int n;
    while(cin>>n && n)
    {
        memset(dp,-1,sizeof(dp));
        fr_z(0,n)
        {
            cin>>arr[z];
            dp[z][z]=0;
        }
        fr_z(1,n+1)
            acc[z]=acc[z-1]+arr[z-1];
        /*fr_z(0,n)
            cout<<arr[z]<<' ';
        cout<<'\n';
        fr_z(0,n+1)
            cout<<acc[z]<<' ';
        cout<<'\n';*/
        cout<<recur(0,n-1)<<'\n';
        /*fr_z(0,n)
        {
            fr_o(0,n)
                cout<<dp[z][o]<<' ';
            cout<<'\n';
        }*/
    }

    return 0;
}