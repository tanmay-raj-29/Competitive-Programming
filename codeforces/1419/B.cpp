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
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << ","<< #z << "=" << z << endl
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
    int n;
    ll x; cin>>x;
    vector<ll> dp;
    ll mul=1;
    ll prev=0,curr=1;
    f(i,0,30) {
        dp.pb(curr+prev);
        // deb3(dp[i],curr,prev);
        prev+=curr;
        mul*=2;
        curr=mul*(mul*2-1);
    }
    dp.pb(1ll*mod*mod + 1);
    int l=0,r=30,ans=-1;
    while (l<=r)
    {
        int mid=l+(r-l)/2;
        if(x>=dp[mid]) ans=mid,l=mid+1;
        else r=mid-1;
    }

    // deb(dp[ans]);
    cout<<ans+1<<endl;
    
    

    
     
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}