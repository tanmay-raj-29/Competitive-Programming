#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]"<<endl;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#define deb(x...) cout << #x << " = ["; _print(x)
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
// =================
#define ll long long
#define fr first
#define sc second
#define pb push_back
#define len(s) s.size()
#define all(v) v.begin(), v.end()
// =================

const int mod = 1e9+7;
const int N = 3e5 + 1;

vector<int> g[N];
vector<int> dp(N,-1);

void impgraph(int n, int m)
{
    int i=0, u, v;
    while (m--)
    {
        cin >> u >> v;
        g[u].pb(v);
    }
}

void dfs(int u, int par)
{
    if(dp[u]==-1) dp[u]=0;
    for(int v : g[u]) {
        if(dp[v]==-1) dfs(v,par+1);
        amax(dp[u],dp[v]+1);
    }
}

void solve()
{
    int n,m; cin>>n>>m;
    impgraph(n,m);
    
    for(int i=1;i<=n;i++) {
        if(dp[i]==-1) {
            dfs(i,0);
        }
    }

    // deb(dp);
    int ans=0;
    for(int i=1;i<=n;i++) amax(ans,dp[i]);
    cout<<ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while (t--)
        solve();
    return 0;
}