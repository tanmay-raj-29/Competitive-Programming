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
    int n,sum=0;
    cin>>n;
    vector<int> a(n);
    for(auto &it:a)
    {
        cin>>it;
        sum+=it;
    }
    vector<int> aux(sum%n,(sum+n-1)/n);
    f(i,0,n-sum%n) aux.pb(sum/n);
    sort(all(aux));
    sort(all(a));
    int cnt=0;
    f(i,0,n) cnt+=abs(a[i]-aux[i]);
    cout<<cnt/2;
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