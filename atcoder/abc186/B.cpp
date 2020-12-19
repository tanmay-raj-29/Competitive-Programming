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
    int h,w;
    cin>>h>>w;
    int m[h][w],mn=mod;
    f(i,0,h)
    {
        f(j,0,w) 
        {
            cin>>m[i][j];
            amin(mn,m[i][j]);
        }
    }
    int ans=0;
    f(i,0,h)
    {
        f(j,0,w)
        {
            ans+=m[i][j]-mn;
        }
    }
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