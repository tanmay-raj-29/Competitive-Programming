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
    int n,x; cin>>n>>x;
    vi v(n),v1;
    v1.reserve(n);
    int gt=0,ls=0,cnt=0;
    tr(it,v) {
        cin>>it;
        if(it>x) gt+=it-x;
        else if(x>it) ls+=x-it;
        else cnt++;
        it=it-x;
    }
    // deb3(gt,ls,cnt);
    if(cnt==n) {
        cout<<"0"<<endl;
        return;
    }
    int j=0;
    int diff=0;
    if(gt==ls || cnt) {
        cout<<"1"<<endl;
        return;
    }
   cout<<"2"<<endl;
    
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