#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
#define f(i, k, n) for (int i = k; i < n; i++)
// #define r(i, k, n) for (int i = k; i >= n; i--)
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define len(s) s.size()
#define all(v) v.begin(), v.end()
#define tr(it, v) for (auto &it : v)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;
// =================

const int mod = 1e9+7;
const int N = 3e5 + 1;

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vi a(n);
    tr(it,a) cin>>it;
    vector<ll> diff(n+1);
    diff[0]=a[0];
    f(i,1,n) diff[i]=a[i]-a[i-1];
    vi l(m),r(m),d(m);
    f(i,0,m) {
        cin>>l[i]>>r[i]>>d[i];
        l[i]--;
        r[i]--;
    }
    vi numQuery(m+1);
    f(i,0,k) {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        numQuery[x]++;
        numQuery[y+1]--;
    }

    f(i,0,m) {
        if(!i) {
            diff[l[i]]+=1ll*d[i]*numQuery[i];
            diff[r[i]+1]-=1ll*d[i]*numQuery[i];
        }
        else {
            numQuery[i]+=numQuery[i-1];
            diff[l[i]]+=1ll*d[i]*numQuery[i];
            diff[r[i]+1]-=1ll*d[i]*numQuery[i];
        }
        
    }
    cout<<diff[0]<<" ";
    f(i,1,n) {
        diff[i]+=diff[i-1];
        cout<<diff[i]<<" ";
    }
}

signed main()
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