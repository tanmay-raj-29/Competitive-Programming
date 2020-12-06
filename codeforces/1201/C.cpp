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
    int curr=n/2 + 1,ptr=n/2;
    while(k>0 && curr<n)
    {
        int req=(curr-ptr)*(v[curr]-v[ptr]);
        if(req>k) 
        {
            v[n/2]+=k/(curr-ptr);
            k=0;
            break;
        }
        else v[ptr]=v[curr],k-=req,curr++;
    }
    cout<<v[n/2]+k/(curr-ptr);
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