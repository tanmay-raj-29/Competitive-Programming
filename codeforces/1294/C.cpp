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
    int a=1,b=1,c=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) 
        {
            a=i;
            break;
        }
    }
    n/=a;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0 && i!=a)
        {
            b=i;
            break;
        }
    }
    c=n/b;
    if(a!=1 && b!=1 && c!=1 && a!=b && a!=c && b!=c) cout<<"YES\n"<<a<<" "<<b<<" "<<c<<"\n";
    else cout<<"NO\n";
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