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

vector<int> g[N];
int vis[N];

void impgraph(int n, int m)
{
    int i=0, u, v;
    while (m--)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

int dist[N]; 
vector<int> aux(N);
vector<int> V(N,-mod);

void dfs(int u, int par)
{
    dist[u]=dist[par]+1;
    vis[u]=1;
    aux[u]=1;
    for (int v : g[u])
    {
        if (vis[v])
        {
            continue;
        }
        dfs(v, u);
        aux[u]+=aux[v];
    }
    V[u]=dist[u]-1 - (aux[u]-1);
}

void solve()
{
    int n,k;
    cin>>n>>k;
    if(n==k) 
    {
        cout<<"0";
        return;
    }
    impgraph(n,n-1);
    dfs(1,0);
    int ans=0;
    sort(all(V),greater<int>());
    for(auto &it:V)
    {
        k--;
        ans+=it;
        if(!k) break;
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