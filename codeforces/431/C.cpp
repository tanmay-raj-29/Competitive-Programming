#include <bits/stdc++.h>
using namespace std;
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
// =================
#define f(i, k, n) for (int i = k; i < n; i++)
#define ll long long
#define int ll
#define pb push_back
#define fr first
#define sc second
#define len(s) s.size()
#define all(v) v.begin(), v.end()
#define deb(x) cout << #x << "=" << x << endl
// =================

const int mod = 1e9+7;
const int N = 3e2 + 1;

void solve()
{
    int n,k,d;
    cin>>n>>k>>d;
    int dp[N+k][2];
    // dp[i][k] -> num of ways to get to sum i including and not including edge of wight atleast d
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    f(j,0,N)
    {
        f(i,1,k+1)
        {
            if(i<d) dp[i+j][0]+=dp[j][0],dp[i+j][1]+=dp[j][1];
            else dp[i+j][1]+=dp[j][0]+dp[j][1];
            dp[i+j][0]%=mod;
            dp[i+j][1]%=mod;
        }
    }
    cout<<dp[n][1];
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