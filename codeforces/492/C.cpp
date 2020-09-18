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
int r;

bool cmp(pii &a, pii &b) {
    return a.sc < b.sc;
}

void solve()
{
    int n,avg; cin>>n>>r>>avg;
    vpii g;
    ll curr=0;
    f(i,0,n) {
        int a,b; cin>>a>>b;
        if(a<r) g.pb({a,b});
        curr+=a;
    }
    ll tot=1ll*avg*n;
    if(tot<=curr) {
        cout<<"0";
        return;
    }
    sort(all(g),cmp);
    ll cnt=0;
    tr(it,g) {
        if(tot-curr> r-it.fr) curr+=r-it.fr,cnt+=1ll*it.sc*(r-it.fr);
        else cnt+=1ll*(tot-curr)*it.sc,curr=tot;
        if(curr>=tot) break;
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