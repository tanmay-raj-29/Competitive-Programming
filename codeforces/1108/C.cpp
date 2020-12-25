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
    string s;
    cin>>s;
    map<string,int> mp;
    string aux="BGR";
    do
    {
        mp[aux]=0;
    } while (next_permutation(all(aux)));
    for(int i=0;i<3&&i<n;i++)
    {
        for(int j=i;j<n;j+=3)
        {
            for(auto &it:mp)
            {
                it.sc+=(it.fr[i]!=s[j]);
            }
        }
    }
    int ans=mod;
    for(auto &it:mp)
    {
        amin(ans,it.sc);
    }
    cout<<ans<<"\n";
    for(auto &it:mp)
    {
        if(it.sc==ans)
        {
            f(i,0,n) cout<<it.fr[i%3];
            break;
        }
    }
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