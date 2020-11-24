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
    string s;
    cin>>s;
    int n=len(s);
    map<char,vector<int>> mp;
    f(i,0,n) 
    {
        mp[s[i]].pb(i);
    }
    int ans=mod;
    for(auto &it:mp)
    {
        int cnt=0,prev=-1;
        for(auto &it1:it.sc)
        {
            amax(cnt,it1-prev);
            prev=it1;
        }
        amax(cnt,n-prev);
        amin(ans,cnt);
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