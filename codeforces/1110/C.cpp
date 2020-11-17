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
vector<int> v;

void precompute()
{
    int base=1;
    f(i,0,26) 
    {
        base*=2;
        int mx=1;
        for(int j=2;j*j<=base-1;j++) 
        {
            if((base-1)%j==0)
            amax(mx,max(j,(base-1)/j));
        }
        v.pb(mx);
    }
}

void solve()
{
    int n;
    cin>>n;
    bitset<32> num(n),ans;
    int x=32-__builtin_clz(n);
    f(i,0,x)
    {
        ans[i]=!num[i];
    }
    int c1=n,c2=ans.to_ulong();
    if(c2==0) {
        cout<<v[x-1]<<"\n";
        return;
    }
    c1=c1^c2,c2=0;
    cout<<__gcd(c1,c2)<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    precompute();
    int t=1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}