#include <bits/stdc++.h>
using namespace std;
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
// =================
#define f(i, k, n) for (int i = k; i < n; i++)
#define ll long long
#define int ll
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
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &it:v)
    {
        cin>>it;
    }
    sort(all(v));
    int l=n/2,r=n-1,opt=l,opt_req=0;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        bool OK=1;
        int req=0;
        f(i,n/2+1,mid+1) req+=(i-n/2)*(v[i]-v[i-1]);
        if(req>k) OK=0; 
        if(OK) l=mid+1,opt=mid,opt_req=req;
        else r=mid-1;
    }
    cout<<v[opt]+(k-opt_req)/(opt-n/2+1);
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