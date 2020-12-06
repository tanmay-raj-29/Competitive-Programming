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
    int n,m,k;
    cin>>n>>m>>k;
    char mat[n][m];
    f(i,0,n) f(j,0,m) cin>>mat[i][j];
    int ans=0;
    vector<int> opt;
    f(i,0,n)
    {
        int cnt=0;
        f(j,0,m)
        {
            if(mat[i][j]=='.') cnt++;
            else 
            {
                if(cnt>=k) opt.pb(cnt);
                cnt=0;
            }
        }
        if(cnt>=k) opt.pb(cnt);
    }
    if(k>1)
    f(i,0,m)
    {
        int cnt=0;
        f(j,0,n)
        {
            if(mat[j][i]=='.') cnt++;
            else 
            {
                if(cnt>=k) opt.pb(cnt);
                cnt=0;
            }
        }
        if(cnt>=k) opt.pb(cnt);
    }
    for(auto &it:opt) ans+=(it-k+1);
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