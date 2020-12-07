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
const int N = 3e5 + 1;

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp; // count
    for(auto &it:v)
    {
        cin>>it;
        mp[it]++;
    }
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    n=len(v);
    vector<int> dp(n+1); // dp[i] -> answer if there are i elements
    dp[1]=mp[v[0]]*v[0];
    f(i,2,n+1)
    {
        int j=i-1;
        if(v[j]-1==v[j-1]) dp[i]=max(dp[i-1],dp[i-2]+mp[v[j]]*v[j]);
        else dp[i]=dp[i-1]+mp[v[j]]*v[j];
    }
    // deb(dp);
    cout<<dp[n];
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