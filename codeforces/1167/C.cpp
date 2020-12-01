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

struct DSU
{
    int connected;
    vector<int> par, sz;

    void init(int n)   // initialise
    {
        par = sz = vector<int> (n + 1, 0);
        for(int i = 1; i <= n; i++)
            par[i] = i, sz[i] = 1;
        connected = n;
    }

    int getPar(int u)   // get parent
    {
        while(u != par[u])
        {
            par[u] = par[par[u]];
            u = par[u];
        }
        return u;
    }

    int getSize(int u)    // get size
    {
        return sz[getPar(u)];
    }

    void unite(int u, int v)   // union(u,v)
    {
        int par1 = getPar(u), par2 = getPar(v);

        if(par1 == par2)
            return;

        connected--;

        if(sz[par1] > sz[par2])
            swap(par1, par2);

        sz[par2] += sz[par1];
        sz[par1] = 0;
        par[par1] = par[par2];
    }
};

void solve()
{
    int n,m;
    cin>>n>>m;
    DSU dsu;
    dsu.init(n);
    while(m--)
    {
        int k;
        cin>>k;
        int prev;
        if(k) 
        {
            cin>>prev;
            k--;
        }
        f(i,0,k)
        {
            int curr;
            cin>>curr;
            dsu.unite(prev,curr);
            prev=curr;
        }
    }
    f(i,1,n+1) cout<<dsu.sz[dsu.getPar(i)]<<" ";
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