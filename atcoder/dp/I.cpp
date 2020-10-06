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

void solve()
{
    int n; cin>>n;
    vector<double> p(n);
    for(double& x: p) cin>>x;
    vector<vector<double>> dp(n+1,vector<double>(n+1,0));
    dp[0][0]=1;

    for(int i=1;i<=n;i++) {
        dp[i][0]=dp[i-1][0]*(1-p[i-1]);
        for(int j=1;j<=i;j++) {
            dp[i][j]=dp[i-1][j]*(1-p[i-1]);
            dp[i][j]+=dp[i-1][j-1]*p[i-1];
        }
    }
    // deb(dp);
    double ans=0;
    for(int i=(n+1)/2;i<=n;i++) {
        ans+=dp[n][i];
    }
    printf("%0.15lf",ans);
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