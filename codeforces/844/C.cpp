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
vector<int> g[N];
int vis[N]; 
set<int> s[N];

void dfs(int u, int par)
{
    vis[u]=1;
    for (int v : g[u])
    {
        if (vis[v])
        {
            continue;
        }
        dfs(v, par);
    }
    s[par].insert(u);
}

void solve()
{
    int n;
    cin>>n;
    map<int,int> aux;
    f(i,0,n) 
    {
        int x;
        cin>>x;
        aux[x]=i+1;
    }
    int curr=1;
    for(auto &it:aux)
    {
        g[it.sc].pb(curr);
        g[curr].pb(it.sc);
        curr++;
    }
    curr=0;
    f(i,1,n+1)
    {
        if(!vis[i])
        {
            dfs(i,curr);
            curr++;
        }
    }
    cout<<curr<<"\n";
    f(i,0,curr)
    {
        cout<<len(s[i])<<" ";
        for(auto &it:s[i])
        {
            cout<<it<<" ";
        }
        cout<<"\n";
    }
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