#include <bits/stdc++.h>
using namespace std;
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
// =================
#define f(i, k, n) for (int i = k; i < n; i++)
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define len(s) s.size()
#define all(v) v.begin(), v.end()
#define deb(x) cout << #x << "=" << x << endl
// =================

const int mod = 1e9+7;
const int N = 3e5 + 1;

void solve()
{
    int n,m,t;
    cin>>n>>m>>t;
    int c=n,prev=0;
    f(i,0,m)
    {
        int x,y;
        cin>>x>>y;
        c-=x-prev;
        if(c<=0) 
        {
            cout<<"No";
            return;
        }
        c+=y-x;
        if(c>=n) c=n;
        prev=y;
    }
    c-=t-prev;
    if(c<=0) cout<<"No";
    else cout<<"Yes";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}