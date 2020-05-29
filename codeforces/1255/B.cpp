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
typedef vector<pll> vpll;
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

    int t;
    cin >> t;
    while (t--)
    {
        int n,m; cin>>n>>m;
        vi v(n);
        int sum=0;
        f(i,0,n) {
            cin>>v[i];
            sum+=v[i];
        }
        if(n!=m || n<3) {
            cout<<"-1\n";
            continue;
        }
        cout<<2*sum<<endl;
        f(i,0,n-1) cout<<i+1<<" "<<i+2<<endl;
        cout<<"1 "<<n<<endl;
        
    }
    return 0;
}