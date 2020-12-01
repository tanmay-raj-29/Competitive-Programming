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
int cnt[26];

void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int curr=1;
    if(k==1)
    {
        f(i,0,n) cnt[s[i]-'a']++;
    }
    else f(i,1,n)
    {
        if(s[i]==s[i-1]) curr++;
        else curr=1;

        if(curr==k)
        {
            cnt[s[i]-'a']++;
            curr=1;
            i++;
        }
    }
    int ans=0;
    f(i,0,26) amax(ans,cnt[i]);
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