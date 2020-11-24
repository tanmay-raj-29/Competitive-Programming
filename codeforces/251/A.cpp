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
    int n,d;
    cin>>n>>d;
    vector<int> x(n);
    for(auto &it:x)
    {
        cin>>it;
    }
    ll ans=0;
    f(i,0,n)
    {
        int l=i,r=n-1,opt=i;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            bool OK=1;
            OK=(x[mid]-x[i])<=d;
            if(OK) l=mid+1,opt=mid;
            else r=mid-1;
        }
        ll tot=opt-i;
        // cout<<tot<<" ";
        if(tot>1)
        {
            ans+=(tot*(tot-1)/2);
        }    
    }
    cout<<ans<<"\n";
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