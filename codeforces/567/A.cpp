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

    int n; cin>>n;
    vi v(n);
    f(i,0,n) cin>>v[i];
    f(i,0,n) {
        if(i && i!=n-1) cout<<min(v[i]-v[i-1],v[i+1]-v[i]) <<" "<<max(v[n-1]-v[i],v[i]-v[0]);
        else if(i) cout<<v[i]-v[i-1]<<" "<<v[i]-v[0];
        else cout<<v[i+1]-v[i]<<" "<<v[n-1]-v[i];
        cout<<endl;
    }

    return 0;
}