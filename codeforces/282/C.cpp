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
    string a,b;
    cin>>a>>b;
    /*
        10 => 11 
        11 => 10, 01
        00 => 00
    */
    if(len(a)!=len(b))
    {
        cout<<"NO";
        return;
    }
    int n=len(a),cntA=0,cntB=0;
    f(i,0,n)
    {
        cntA+=a[i]=='0';
        cntB+=b[i]=='0';
    }
    if(cntA==n && cntB==n)
    {
        puts("YES");
    }
    else if(cntA==n || cntB==n) puts("NO");
    else puts("YES");
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