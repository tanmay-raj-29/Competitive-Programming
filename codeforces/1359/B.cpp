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
        int n,m,x,y; cin>>n>>m>>x>>y;
        char a[n][m];
        f(i,0,n) f(j,0,m) cin>>a[i][j];
        if(y>=2*x) y=2*x;
        ll cost=0;
        f(i,0,n) {
            f(j,0,m) {
                if(a[i][j]=='*') continue;
                else {
                    if(a[i][j+1]=='.' && j+1<m) cost+=y,a[i][j+1]='*';
                    else cost+=x;
                }
            }
        }
        cout<<cost<<endl;
    }
    
    return 0;
}