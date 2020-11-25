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
    cin>>n;
    vector<int> v(n);
    for(auto &it:v)
    {
        cin>>it;
    }
    auto it=unique(all(v));
    v.resize(it-v.begin());
    map<int,int>  freq;
    f(i,0,len(v))
    {
        freq[v[i]]++;
    }
    int ans=mod;
    for(auto &it:freq)
    {
        int curr=it.sc+1;
        if(it.fr==v[0]) curr--;
        if(it.fr==v[len(v)-1]) curr--;
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