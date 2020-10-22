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
const int N = 3e2 + 1;

double dp[N][N][N];

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    int cnt3=0,cnt2=0,cnt1=0,cnt0;
    tr(it,a) {
        cin>>it;
        cnt3+=it==3;
        cnt2+=it==2;
        cnt1+=it==1;
    }
    cnt0=n-cnt1-cnt2-cnt3;
    // p0 p1 p2 p3
    f(n3,0,n+1) {
        f(n2,0,n+1) {
            f(n1,0,n+1) {
                int n0=n-n1-n2-n3; 
                double p3=1.0*n3/n,p2=1.0*n2/n,p1=1.0*n1/n,p0=1.0*n0/n;
                if(n0==n || n1+n2+n3>n) continue;
                double val=1;
                // deb(p3,p2,p1);
                if(n3>0) val+=1.0*dp[n3-1][n2+1][n1]*p3;
                if(n2>0) val+=1.0*dp[n3][n2-1][n1+1]*p2;
                if(n1>0) val+=1.0*dp[n3][n2][n1-1]*p1;
                dp[n3][n2][n1]=1.0*val/(1-p0);
            }
        }
    }

    // deb(dp);
    cout<<setprecision(9);
    cout<<fixed;
    cout<<dp[cnt3][cnt2][cnt1]<<"\n";
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