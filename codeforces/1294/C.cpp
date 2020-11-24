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

const int NUM=1e5+1;
bool prime[NUM];
vector<int> p;
void sieve() {
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i*i<=NUM;i++) if(prime[i]) for(int j=i*i;j<NUM;j+=i) prime[j]=false;
    p.reserve(NUM/10);
    f(i,0,NUM) if(prime[i]) p.pb(i);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> fac;
    f(i,0,len(p))
    {
        while(n%p[i]==0)
        {
            fac.pb(p[i]);
            n/=p[i];
        }
    }
    fac.pb(n);
    if(len(fac)>2) 
    {
        int c1=1,c2=1;
        f(i,1,len(fac)) 
        {
            if(c1>fac[0]) c2*=fac[i];
            else c1*=fac[i];
        }
        if(c1!=c2 && c1!=fac[0] && c2!=fac[0] && c1!=1 && c2!=1) 
        {
            cout<<"YES\n"<<c1<<" "<<c2<<" "<<fac[0]<<"\n";
            return;
        }   
    }
    cout<<"NO\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();
    int t=1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}