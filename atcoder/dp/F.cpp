#include <bits/stdc++.h>
using namespace std;
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
// =================
#define f(i, k, n) for (int i = k; i < n; i++)
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define len(s) s.size()
#define all(v) v.begin(), v.end()
// =================

const int mod = 1e9+7;
const int N = 3e5 + 1;

void solve()
{
    string a,b;
    cin>>a>>b;
    int n=len(a),m=len(b);
    vector<vector<int>> dp(n+1,vector<int>(m+1)),choice(n+1,vector<int>(m+1));
    f(i,1,n+1)
    {
        f(j,1,m+1)
        {
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1,choice[i][j]=2;            
            else if(dp[i-1][j]>=dp[i][j-1]) dp[i][j]=dp[i-1][j],choice[i][j]=1;
            else dp[i][j]=dp[i][j-1];
        }
    }
    int i=n,j=m;
    string ans="";
    while(i&&j)
    {
        if(choice[i][j]==2) ans+=a[i-1],i--,j--;
        else if(choice[i][j]==1) i--;
        else j--;
    }
    reverse(all(ans));
    cout<<ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}