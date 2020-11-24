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
    vector<int> a(n);
    for(auto &it:a)
    {
        cin>>it;
    }
    sort(all(a));
    int mx=a[n-1];
    map<int,int> mp;
    while(mx%2==0) {
        mp[2]++;
        mx/=2;
    }
    for(int i=3;i<=mx;i+=2)
    {
        while(mx%i==0)
        {
            mp[i]++;
            mx/=i;
        }
    }
    bool ok=1;
    f(i,0,n-1)
    {
        for(auto &it:mp)
        {
            int cnt=0;
            while(a[i]%it.fr==0)
            {
                cnt++;
                a[i]/=it.fr;
            }
            if(it.fr>3 && cnt!=it.sc) 
            {
                ok=0;
                break;
            }
        }
        while(a[i]%2==0) {
            a[i]/=2;
        }
        while(a[i]%3==0) {
            a[i]/=3;
        }
        if(a[i]!=1) ok=0;
    }
    puts(ok?"YES":"NO");
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