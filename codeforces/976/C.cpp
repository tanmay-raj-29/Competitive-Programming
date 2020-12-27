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

struct cmp {
    bool operator() (const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b) 
    const {
        return a.sc.fr==b.sc.fr?a.sc.sc>b.sc.sc:a.sc.fr<b.sc.fr;
    }
};

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> vp(n);
    int i=0;
    for(auto &it:vp)
    {
        cin>>it.sc.fr>>it.sc.sc;
        it.fr=i+1;
        i++;
    }
    sort(all(vp),cmp());
    set<pair<int,int>> curr;
    f(i,0,n)
    {
        auto it=curr.lower_bound({vp[i].sc.sc,0});
        if(it!=curr.end())
        {
            cout<<vp[i].fr<<" "<<(*it).sc<<"\n"; 
            return;
        }
        curr.insert({vp[i].sc.sc,vp[i].fr});
    }
    cout<<"-1 -1\n";
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