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

const int mod = 1e9+7;
const int N = 3e5 + 1;

void solve()
{
    int n;
    cin>>n;
    vi cnt(n+1);
    map<int,vpii> mp;
    int num=0;
    f(i,0,n-2) {
        int x,y,z;
        cin>>x>>y>>z;
        cnt[x]++;
        cnt[y]++;
        cnt[z]++;
        mp[x].pb({y,z});
        mp[y].pb({x,z});
        mp[z].pb({x,y});
    }
    f(i,0,n+1) {
        if(cnt[i]==1) {
            num=i;
            break;
        }
    }
    vi ans;
    ans.reserve(n);
    ans.pb(num);
    if(cnt[mp[num][0].fr]==2) 
        ans.pb(mp[num][0].fr),ans.pb(mp[num][0].sc);
    else ans.pb(mp[num][0].sc),ans.pb(mp[num][0].fr);
    cnt[mp[num][0].fr]=0;
    cnt[mp[num][0].sc]=0;
    cnt[num]=0;
    // deb(ans);
    int L=len(ans);
    while (L<n)
    {
        int x;
        tr(it,mp[ans[L-1]]) {
            int match=0;
            if(!cnt[it.fr]) {
                match++;
                x=it.sc;
            }
            if(!cnt[it.sc]) {
                match++;
                x=it.fr;
            }
            if(match==1) break;
        }
        ans.pb(x);
        cnt[x]=0;
        // deb(ans);
        L=len(ans);
    }
    f(i,0,n) cout<<ans[i]<<" ";
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