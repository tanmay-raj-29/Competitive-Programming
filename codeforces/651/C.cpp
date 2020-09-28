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
    int n; cin>>n;
    map<pii,int> mp;
    mii mpx,mpy;
    f(i,0,n) {
        int x,y; cin>>x>>y;
        mp[{x,y}]++;
        mpx[x]++;
        mpy[y]++;
    }
    ll cnt=0;
    tr(it,mpx) {
        if(it.sc>2) cnt+=1ll*(it.sc-1)*(it.sc)/2;
        else cnt+=it.sc-1;
    }
    tr(it,mpy) {
        if(it.sc>2) cnt+=1ll*(it.sc-1)*(it.sc)/2;
        else cnt+=it.sc-1;
    }
    tr(it,mp) {
        if(it.sc>2) cnt-=1ll*(it.sc-1)*(it.sc)/2;
        else cnt-=it.sc-1;
    }
    cout<<cnt;
     
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