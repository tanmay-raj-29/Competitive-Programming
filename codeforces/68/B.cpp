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
    int n;
    double k;
    cin>>n>>k;
    double a[n];
    f(i,0,n) cin>>a[i]; 
    int i=0;
    sort(a,a+n);
    double l=0,r=a[n-1],ans=r;
    cout.precision(10);
    while(abs(r-l)>1e-6)
    {
        double mid=l+(r-l)/2;
        double more=0,less=0;
        f(i,0,n)
        {
            if(a[i]>mid) more+=a[i]-mid;
            else less+=mid-a[i];
        }
        // cout<<l<<" "<<mid<<" "<<r<<" "<<more<<" "<<less<<"\n";
        if(more<1e-6) 
        {
            l=mid;
            continue;
        }
        else if(less<1e-6)
        {   
            r=mid;
            continue;
        }
        if(more-more*k/100>=less) l=mid,ans=mid;
        else r=mid;
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