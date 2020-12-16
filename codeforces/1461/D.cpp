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
#define f(i, k, n) for (int i = k; i < n; i++)
#define ll long long
#define int ll
#define pb push_back
#define fr first
#define sc second
#define len(s) s.size()
#define all(v) v.begin(), v.end()
// #define deb(x) cout << #x << "=" << x << endl
// =================

const int mod = 1e9+7;
const int N = 3e5 + 1;
int n;
vector<int> pf(N),v;
map<int,int> mp;

void precompute(int l,int r)
{
    if(l>r) return;
    if(l==r) 
    {
        mp[v[l]]=1;
        return;
    }
    int md=(v[l]+v[r])/2;
    int l1=l,r1=r,ok=l;
    while(l1<=r1)
    {
        int mid=l1+(r1-l1)/2;
        bool OK=(v[mid]<=md);
        if(OK) l1=mid+1,ok=mid;
        else r1=mid-1;
    }
    // deb(l,r,ok);
    mp[pf[r+1]-pf[ok+1]]=1;
    mp[pf[ok+1]-pf[l]]=1;
    if(ok==r) return;
    precompute(l,ok);
    precompute(ok+1,r);
}

void solve()
{
    int q;
    cin>>n>>q;
    v.resize(n);
    f(i,0,n) cin>>v[i];
    sort(all(v));
    f(i,0,n) pf[i+1]=pf[i]+v[i];
    mp[pf[n]]=1;
    precompute(0,n-1);
    f(i,0,q)
    {
        int s;
        cin>>s;
        if(mp[s]) cout<<"Yes\n";
        else cout<<"No\n";
    }
    mp.clear();
    v.clear();
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