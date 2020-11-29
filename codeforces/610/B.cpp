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
    int n,mn;
    cin>>n;
    vector<int> a(n);
    for(auto &it:a)
    {
        cin>>it;
        amin(mn,it);
    }
    vector<int> pos,ans(n);
    f(i,0,n) if(mn==a[i]) pos.pb(i);
    int prev=-1;
    for(auto &it:pos)
    {
        int curr=it;
        while(curr>prev) 
        {
            ans[curr]=it-curr;
            curr--;
        }
        prev=it;
    }
    int curr=n-1;
    while(curr>prev)
    {
        ans[curr]=pos[0]+n-curr;
        curr--;
    }
    int mx=0;
    f(i,0,n) amax(mx,ans[i]+mn*n);
    cout<<mx;
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