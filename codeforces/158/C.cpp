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
    string path;
    while(n--)
    {
        string com;
        cin>>com;
        if(len(path)==0 || path[len(path)-1]!='/') path.pb('/');
        
        if(com=="pwd") cout<<path<<"\n";
        else
        {
            string curr;
            cin>>curr;
            if(curr[0]=='/' && len(path)) path.clear();
            if(len(path)==0 || path[len(path)-1]!='/') path.pb('/');
            f(i,0,len(curr))
            {
                if(curr[i]=='.')
                {
                    if(len(path)&&path.back()=='/') path.pop_back();
                    while(len(path)&&path[len(path)-1]!='/')
                    {
                        path.pop_back();
                    }
                    i+=2;
                    if(len(path)==0 || path[len(path)-1]!='/') path.pb('/');
                }
                else if(curr[i]!='/')
                {
                    path.pb(curr[i]);
                }
                else if(len(path)==0 || path[len(path)-1]!='/') path.pb('/');
            }
            if(len(path)==0 || path[len(path)-1]!='/') path.pb('/');
        }
    }
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