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
// =================

const int mod = 1e9+7;
const int N = 1e5 + 1;

vector<vector<int>> dp(101,vector<int>(N,-1));

int knapSack(int W, int wt[], int val[], int n) 
{ 
    if(n<=0 || W<=0) return 0;
    if(dp[n][W]!=-1) return dp[n][W];
    if(W<wt[n-1])
    {
        dp[n][W]=knapSack(W,wt,val,n-1);
        return dp[n][W];
    }
    dp[n][W]=max(knapSack(W,wt,val,n-1),val[n-1]+knapSack(W-wt[n-1],wt,val,n-1));
    return dp[n][W];
}

void solve()
{
    int n,w;
    cin>>n>>w;
    int wt[n],val[n];
    f(i,0,n) cin>>wt[i]>>val[i];
    cout<<knapSack(w,wt,val,n);
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