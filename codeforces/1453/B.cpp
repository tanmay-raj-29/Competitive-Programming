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
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &it:v)
    {
        cin>>it;
    }
    f(i,1,n) v[i]-=v[0];
    v[0]=0;
    int ans=0;
    f(i,1,n) ans+=abs(v[i]-v[i-1]);
    int tot=ans;
    amin(ans,tot-abs(v[1]-v[0]));
    f(i,1,n)
    {
        int curr=tot;
        curr-=abs(v[i]-v[i-1]);
        if(i+1<n)
        {
            curr-=abs(v[i+1]-v[i]);
            curr+=abs(v[i+1]-v[i-1]);
        }
        amin(ans,curr);
    }
    cout<<ans<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}