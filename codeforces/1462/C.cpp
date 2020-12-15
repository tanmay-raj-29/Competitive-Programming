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
#define deb(x) cout << #x << "=" << x << endl
// =================

const int mod = 1e9+7;
const int N = 3e5 + 1;

vector<int> dp(N,mod);

void pre()
{
    vector<int> aux;
    f(i,1,10) aux.pb(i);
    f(i,0,1<<9)
    {
        int x=0,sum=0;
        f(j,0,9)
        {
            if(i&(1<<j)) x=x*10+aux[j],sum+=aux[j];
        }
        amin(dp[sum],x);
    }
    f(i,0,N) if(dp[i]==mod) dp[i]=-1;
}

void solve()
{
    int n;
    cin>>n;
    cout<<dp[n]<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    pre();
    cin>>t;
    while (t--)
        solve();
    return 0;
}