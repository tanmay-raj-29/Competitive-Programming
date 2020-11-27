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
// =================

const int mod = 1e9+7;
const int N = 3e5 + 1;

void solve()
{
    int v1,v2,t,d;
    cin>>v1>>v2>>t>>d;
    vector<int> spd(t);
    spd[0]=v1;
    spd[t-1]=v2;
    f(i,1,t-1) spd[i]=spd[i-1]+d;
    for(int i=t-2;i>0;i--) amin(spd[i],spd[i+1]+d);
    cout<<accumulate(all(spd),0);
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