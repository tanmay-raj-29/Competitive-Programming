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
    int n,m;
    cin>>n>>m;
    vpii v;
    int cost=0;
    f(i,0,n) {
        int x; cin>>x;
        cost+=2*x;
        v.pb({x,i});
    }
    if(n==2 || (n>1 && m<n)) {
        cout<<"-1\n";
        return;
    } 
    sort(all(v));
    vpii ans;
    int i=0;
    int l=1,r=n-1;
    ans.pb({v[0].sc,v[n-1].sc});
    ans.pb({v[0].sc,v[n-2].sc});
    while (l<r)
    {
        if(i%2) {
            // deb(l,r);
            ans.pb({v[l].sc,v[r].sc});
            if(l+1>r-1) break;
            if(r-l==2) {
                r++;
                // deb(l+1,r-1);
                ans.pb({v[l+1].sc,v[r-1].sc});
                break;
            }
            // deb(l+1,r-1);
            ans.pb({v[l+1].sc,v[r-1].sc});
            l+=2;
        }
        else {
            // deb(l,r);
            ans.pb({v[l].sc,v[r].sc});
            if(l+1>r-1) break;
            if(r-l==2) {
                l--;
                // deb(l+1,r-1);
                ans.pb({v[l+1].sc,v[r-1].sc});
                break;
            }
            // deb(l+1,r-1);
            ans.pb({v[l+1].sc,v[r-1].sc});
            r-=2;
        }
        i++;
    }
    
    cout<<cost<<"\n";
    tr(it,ans){
        cout<<it.fr+1<<" "<<it.sc+1<<"\n";
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
    cin>>t;
    while (t--)
        solve();
    return 0;
}