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

const int NUM=1e5+1;
bool prime[NUM];
int p1,p2,cnt1,cnt2;

void sieve() {
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i*i<=NUM;i++) if(prime[i]) for(int j=i*i;j<=NUM;j+=i) prime[j]=false;
}

bool parts(int n,int cnt) {
    p1=n/cnt;
    p2=p1+1;
    cnt2=n%cnt;
    cnt1=cnt-cnt2;
    // deb(n,cnt,p1,p2,prime[p1],prime[p2]);
    return !(prime[p1] || prime[p2]);
}

void solve()
{
    int n;
    cin>>n;
    sieve();
    vi ans;
    ans.reserve(100);
    bool ok=0;
    f(i,n,NUM) {
        if(prime[i] && parts(i,n)) {
            // deb(parts(i,n),i,n);
            ok=1;
            break;
        }
    }
    if(ok==0) {
        cout<<"-1\n";
    }
    while (cnt1)
    {
        ans.pb(p1);
        cnt1--;
    }
    while (cnt2)
    {
        ans.pb(p2);
        cnt2--;
    }
    sort(all(ans));
    f(i,0,n) {
        int j=i;
        while (j<i+n)
        {
            cout<<ans[j%n]<<" ";
            j++;
        }
        cout<<"\n";
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
    cerr<<(1000*clock())/CLOCKS_PER_SEC<<"ms";
    return 0;
}