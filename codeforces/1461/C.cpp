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
// #define deb(x) cout << #x << "=" << x << endl
// =================

const int mod = 1e9+7;
const int N = 3e5 + 1;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    f(i,1,n+1) cin>>a[i];
    int r[m];
    float p[m];
    f(i,0,m) cin>>r[i]>>p[i];
    int curr=0;
    f(i,1,n+1) if(i!=a[i]) curr=i;
    float ans=0,srt=1,unsrt=1;
    int cnt=0;
    if(curr)
    f(i,0,m)
    {
        if(r[i]<curr) continue;
        if(r[i]>=curr)
        {
            // srt*=p[i];
            // ans+=srt;
            if(cnt) ans+=unsrt*p[i];
            else ans+=p[i];
            unsrt*=(1-p[i]);
            cnt++;
        }
        // else
        // {

        // }
    }
    else ans=1;
    printf("%0.6f\n", ans);
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