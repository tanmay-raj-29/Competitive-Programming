#include <bits/stdc++.h>
#define pb push_back
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
    vi v(n) ;
    f(i,0,n) cin>>v[i];
    int l=0,r=n-1;
    int i=0;
    vi sum(2);
    while(l<=r) {
        i=(i?0:1);
        if(v[l]>=v[r]) sum[i]+=v[l],l++;
        else sum[i]+=v[r],r--; 
    }
    cout<<sum[1]<<" "<<sum[0];

    return 0;
}