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
const int N = 5e5 + 1;

vector<int> g[N];
int vis[N],sz[N];
int num=0;
set<int> s;

void dfs(int u, int par)
{
    num++;
    vis[u]=1;
    for (int v : g[u])
    {
        if (vis[v])
        {
            continue;
        }
        dfs(v, par);
    }
    s.insert(u);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int k;
        cin>>k;
        int prev=0;
        if(k) 
        {
            cin>>prev;
            k--;
        }
        f(i,0,k)
        {
            int curr;
            cin>>curr;
            g[prev].pb(curr);
            g[curr].pb(prev);
            prev=curr;
        }
    }
    f(i,1,n+1)
    {
        if(!vis[i]) 
        {
            dfs(i,0);
            for(auto &it:s)
            {
                sz[it]=num;
            }
            num=0;
            s.clear();
        }
    }
    f(i,1,n+1) cout<<sz[i]<<" ";
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