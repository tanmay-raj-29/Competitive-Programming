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

const int mod = 1e9+7;
const int N = 3e5 + 1;
int dp[3001][3001][2];

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    int sum=0;
    tr(it,a) {
        cin>>it;
        sum+=it;
    }
    f(i,0,n) dp[i][i][0]=a[i],dp[i][i][1]=0;

    // f(i,0,n) {
    //     f(j,i+1,n) {
    //         dp[i][j][0]=dp[i][j-1][1]+a[j];
    //         dp[i][j][1]=dp[i][j-1][0];    
    //     }
    //     r(j,i-1,0) {
    //         dp[j][i][0]=dp[j+1][i][1]+a[j];
    //         dp[j][i][1]=dp[j+1][i][0];
    //     }
    // }
    // f(i,0,n) {
    //     f(j,1,n) {
    //         if(j-1>=0) {
    //             amax(dp[i][j][0],dp[i][j-1][1]+a[j]);
    //             amin(dp[i][j][1],dp[i][j-1][0]);
    //         }
    //         if(i+1<n) {
    //             amax(dp[i][j][0],dp[i+1][j][1]+a[i]);
    //             amin(dp[i][j][1],dp[i+1][j][0]);
    //         }
    //     }
    // }

    f(seg,1,n) {
        for(int l=0;l+seg<n;l++) {
            int r=l+seg;
            dp[l][r][0]=max(dp[l][r-1][1]+a[r],dp[l+1][r][1]+a[l]);
            dp[l][r][1]=min(dp[l][r-1][0],dp[l+1][r][0]);
        }
    }


    // deb(sum);    
    cout<<2*dp[0][n-1][0]-sum;
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