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
    int n,k,p;
    cin>>n>>k>>p;
    vector<int> a(n);
    for(auto &it:a)
    {
        cin>>it;
    }    
    vector<int> b(k);
    for(auto &it:b)
    {
        cin>>it;
    }
    sort(all(a));
    sort(all(b));
    int ans=0;
    f(i,0,n) amax(ans,abs(a[i]-b[i])+abs(b[i]-p));
    int l=0,r=k-n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        bool OK=1;
        int m1=mid,m2=mid+1,cnt1=0,cnt2=0;
        f(i,0,n)
        {
            amax(cnt1,abs(a[i]-b[m1+i])+abs(p-b[m1+i]));
            amax(cnt2,abs(a[i]-b[m2+i])+abs(p-b[m2+i]));
        }
        amin(ans,min(cnt1,cnt2));
        if(cnt2>cnt1) OK=0;
        if(OK) l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
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