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

bool check(string s)
{
    int cnt=0,n=len(s);
    f(i,0,n)
    {
        cnt+=s[i]=='(';
        cnt-=s[i]==')';
        if(i!=n-1 && cnt<=0) return 0;
    }
    return !cnt;
}

void solve()
{
    int n;
    string s;
    cin>>n>>s;
    if(n%2) 
    {
        cout<<":(";
        return;
    }
    int cntL=count(all(s),'('),cntR=count(all(s),')');
    f(i,0,n)
    {
        if(s[i]=='?')
        {
            if(cntL<n/2) s[i]='(',cntL++;
            else s[i]=')';
        }
    }
    // cout<<s<<"\n";
    if(check(s)) cout<<s<<"\n";
    else cout<<":(";
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