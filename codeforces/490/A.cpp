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
    vi v1,v2,v3;
    f(i,0,n) {
        int x; cin>>x;
        if(x==1) v1.pb(i+1);
        else if(x==2) v2.pb(i+1);
        else v3.pb(i+1);
    }
    int w=min3(len(v1),len(v2),len(v3));
    cout<<w<<endl;
    f(i,0,w) {
        cout<<v1[i]<<" "<<v2[i]<<" "<<v3[i]<<endl;
    }
    return 0;
}