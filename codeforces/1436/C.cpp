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

const int MYNUM = 3e5+1;
const int MYMOD = mod;
int fact[MYNUM], invfact[MYNUM];

int pow(int a, int b, int m)
{
    int ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return ans;
}

int modinv(int k)
{
    return pow(k, MYMOD-2, MYMOD);
}

void precompute()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<MYNUM;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=MYMOD;
    }
    invfact[MYNUM-1]=modinv(fact[MYNUM-1]);
    for(int i=MYNUM-2;i>=0;i--)
    {
        invfact[i]=invfact[i+1]*(i+1);
        invfact[i]%=MYMOD;
    }
}

int nCr(int x, int y)
{
    if(y>x)
        return 0;
    int num=fact[x];
    num*=invfact[y];
    num%=MYMOD;
    num*=invfact[x-y];
    num%=MYMOD;
    return num;
} 

void solve()
{
    precompute();
    int n,x,pos;
    cin>>n>>x>>pos;
    int l=0,r=n,b=0,s=0;
    while (l<r)
    {
        int mid=(l+r)/2;
        if(mid>pos) b++;
        else if(mid<pos) s++;
        if(mid<=pos) l=mid+1;
        else r=mid;        
    }
    int gt=n-x,ls=x-1;
    ll n1=nCr(gt,b),n2=nCr(ls,s),n3=fact[n-1-b-s];
    ll ans=1;
    ans*=n1;ans%=mod;
    ans*=n2;ans%=mod;
    ans*=n3;ans%=mod;
    ans*=fact[b];ans%=mod;
    ans*=fact[s];ans%=mod;
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