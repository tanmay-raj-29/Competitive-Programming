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
    vector<int> v(n);
    for(auto &it:v)
    {
        cin>>it;
    }
    sort(all(v),greater<int>());
    deque<int> aux;
    f(i,0,n)
    {
        if(len(aux)==0 || aux.front()==v[i]) aux.pb(v[i]);
        else 
        {
            aux.pop_front();
            aux.pb(v[i]);
        }
    }
    cout<<len(aux);

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