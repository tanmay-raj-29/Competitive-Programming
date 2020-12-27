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
    int n,m;
    cin>>n>>m;
    map<int,vector<int>> mp;
    f(i,0,n)
    {
        int x,y;
        cin>>x>>y;
        mp[x].pb(y);
    }
    for(auto &it:mp)
    {
        sort(all(it.sc),greater<int>());
    }
    vector<int> ans(n,0);
    for(auto &it:mp)
    {
        int curr=0;
        f(i,0,len(it.sc))
        {
            curr+=it.sc[i];
            if(curr<0) break;
            ans[i]+=curr;
        }
    }
    int mx=0;
    f(i,0,n) amax(mx,ans[i]);
    cout<<mx<<"\n";
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