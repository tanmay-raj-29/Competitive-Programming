#include <bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define f(i, a, n) for (int i = a; i < n; i++)
using namespace std;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef vector<string> vs;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p,n,ans=-1; cin>>p>>n;
    bool ok=true;
    vi v(p);
    f(i,0,n) {
        int x; cin>>x;
        if(v[x%p]==0) v[x%p]=1;
        else {
            ans=i+1;
            break;
        }
    }
    cout<<ans;
    return 0;
}