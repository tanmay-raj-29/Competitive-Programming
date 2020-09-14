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
    vi a(n),g(n);
    int tot_a=0,tot_g=0;
    f(i,0,n) {
        cin>>a[i]>>g[i];
        tot_a+=a[i];
    }
    bool ok=0;
    string s(n,'A');
    if(abs(tot_g-tot_a)<=500) {
        cout<<s;
        return;
    }
    f(i,0,n) {
        if(abs(tot_g+g[i]-tot_a+a[i])<=500) {
            s[i]='G';
            ok=1;
            break;
        } else {
            s[i]='G';
            tot_a-=a[i];
            tot_g+=g[i];
        }
    }
    if(abs(tot_g-tot_a)<=500) ok=1;
    if(ok) cout<<s;
    else cout<<"-1";
     
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