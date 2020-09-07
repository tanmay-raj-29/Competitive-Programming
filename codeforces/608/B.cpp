
#include <bits/stdc++.h>
using namespace std;
#define f(i, k, n) for (int i = k; i < n; i++)
#define r(i, k, n) for (int i = k; i >= n; i--)
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define len(s) s.size()
#define all(v) v.begin(), v.end()
#define tr(it, v) for (auto &it : v)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
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
    int n, m;
    string a, b;
    cin >> a >> b;
    n = len(a);
    m = len(b);
    vvi dp(m + 1, vi(2, 0));
    f(i, 0, m)
    {
        int x = b[i] - '0';
        dp[i + 1][1] = dp[i][1] + (x == 1);
        dp[i + 1][0] = dp[i][0] + (x == 0);
    }
    ll ans=0;
    f(i,0,n) {
        int y=a[i]-'0';
        ans+=dp[m-n+i+1][!y]-dp[i][!y];
    }
    cout<<ans;
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