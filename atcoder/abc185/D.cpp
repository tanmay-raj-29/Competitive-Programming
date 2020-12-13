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
// #define deb(x) cout << #x << "=" << x << endl
// =================

const int mod = 1e9+7;
const int N = 3e5 + 1;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    f(i,0,m) cin>>a[i];
    a.pb(n+1);
    sort(all(a));
    int prev=1;
    vector<int> aux;
    f(i,0,m+1)
    {
        if(a[i]==prev) prev=a[i]+1;
        else aux.pb(a[i]-prev),prev=a[i]+1;
    }
    int ans=mod,cnt=0;
    f(i,0,len(aux)) amin(ans,aux[i]);
    f(i,0,len(aux)) cnt+=(aux[i]+ans-1)/ans;
    cout<<cnt; 
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