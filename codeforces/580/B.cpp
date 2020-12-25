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
const int N = 3e5 + 1;

void solve()
{
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>> vp;
    f(i,0,n)
    {
        int x,y;
        cin>>x>>y;
        vp.pb({x,y});
    }
    sort(all(vp));
    vector<int> pf(n+1);
    f(i,0,n)
    {
        pf[i+1]=pf[i]+vp[i].sc;
    }
    int ans=0;
    f(i,0,n)
    {
        pair<int,int> p={vp[i].fr+d-1,mod};
        int opt=lower_bound(all(vp),p)-vp.begin();
        amax(ans,pf[opt]-pf[i]);
    }
    cout<<ans<<"\n";
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