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
    int flag=1,prev,flag1=0;
    int x,y; cin>>x>>y;
    if(x!=y) flag1=1;
    prev=y;

    f(i,0,n-1) {
        cin>>x>>y;
        if(x!=y) flag1=1;
        if(y>prev) flag=0;
        prev=y;
    }
    if(flag1) cout<<"rated";
    else if(flag) cout<<"maybe";
    else cout<<"unrated";
    
    return 0;
}