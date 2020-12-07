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
#define deb(x) cout << #x << "=" << x << endl
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
    int n;
    cin>>n;
    vector<int> p(n);
    for(auto &it:p)
    {
        cin>>it;
    }
    DSU dsu;
    dsu.init(n);
    f(i,0,n)
    {
       dsu.unite(p[i],p[p[i]-1]); 
    }
    f(i,1,n+1)
    {
        cout<<dsu.sz[dsu.getPar(i)]<<" ";
    }
    cout<<"\n";
    dsu.sz.clear();
    dsu.par.clear();
    dsu.connected=0;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}