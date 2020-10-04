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
// =================
#define f(i, k, n) for (int i = k; i < n; i++)
#define r(i, k, n) for (int i = k; i >= n; i--)
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
#define int ll
const int mod = 1e9;
const int N = 3e5 + 1;

void solve()
{
    int n,x; cin>>n>>x;
    vi d(n);
    vector<ll> pfx1,pfx2;
    tr(it,d) cin>>it;
    bool fg=0;
    pfx1.reserve(2*n+1);
    pfx2.reserve(2*n+1);
    pfx1.pb(0);
    pfx2.pb(0);
    ll r=0, prev=0;
    f(i,0,n) {
        r+=1ll*d[i]*(d[i]+1)/2;
        pfx1.pb(r);
        pfx2.pb(d[i]+prev);
        prev+=d[i];
        if(!fg && i==n-1) i=-1,fg=1;
    }
    ll ans=0,l=0;

    ll cnt=1;
    while (cnt<2*n+1)
    {
        if(pfx2[cnt]-pfx2[0]>=x) break;
        cnt++;
    }
   
    ll flag=0;
    f(i,cnt,2*n+1) {
        ll l=0,an=0;
        r=i;
        while (l<=r)
        {
            ll mid=l+(r-l)/2;
            if(pfx2[i]-pfx2[mid]<=x) {
                flag=mid;
                r=mid-1;
            } else l=mid+1;   
        }
        an=pfx1[i]-pfx1[flag];
        if(pfx2[i]-pfx2[flag]!=x) {
            ll days=pfx2[flag]-pfx2[flag-1];
            ll rem= days -  (x-(pfx2[i]-pfx2[flag]));
            an+=days*(days+1)/2 - rem*(rem+1)/2;
        }
        // deb(an,i,flag);
        ans=max(ans,an);
    }

    cout<<ans;

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