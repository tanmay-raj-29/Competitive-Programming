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
#define int ll
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

const int mod = 1e9;
const int N = 3e5 + 1;

void solve()
{
    int n,x; cin>>n>>x;
    vi d(n);
    vector<ll> pfx1,pfx2;
    tr(it,d) cin>>it;
    bool flag=0;
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
        if(!flag && i==n-1) i=-1,flag=1;
    }
    ll ans=0,l=0;

    int cnt=1;
    while (cnt<2*n+1)
    {
        if(pfx2[cnt]-pfx2[0]>=x) break;
        cnt++;
    }

    while (l<=r)
    {
        ll mid=l+(r-l)/2;
        bool ok=0;
        f(i,cnt,2*n+1) {
            int left=lower_bound(all(pfx2),pfx2[i]-x)-pfx2.begin();
            // deb(left,pfx2[i]);
            if(pfx2[i]-pfx2[left]==x) {
                if(pfx1[i]-pfx1[left]>=mid) {
                    ok=1;
                    break;
                }
            }
            else{
                int days=pfx2[left]-pfx2[left-1];
                int rem= days -  (x-(pfx2[i]-pfx2[left]));
                if(pfx1[i]-pfx1[left]+ 1ll*days*(days+1)/2 - 1ll*rem*(rem+1)/2 >=mid) {
                    ok=1;
                    break;
                }
            }
        }
        ok?l=mid+1,ans=mid:r=mid-1;
        // deb(ans,mid,ok,l,r);
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