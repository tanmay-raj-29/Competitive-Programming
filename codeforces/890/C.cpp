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
int minute[N];      // Last time I was at ith position
int position[N];    // What position I was at ith minute

void solve()
{
    int n;
    cin>>n;
    int curr=1;
    f(i,1,n+1)
    {
        int x;
        cin>>x;
        if( minute[position[x]] == x ) position[i]=position[x], minute[position[x]]=i;
        else 
        {
            curr++;
            position[i]=curr;
            minute[curr]=i;
        }
    }
    cout<<curr<<"\n";
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