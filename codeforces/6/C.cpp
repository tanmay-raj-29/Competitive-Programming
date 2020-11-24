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
    vector<int> t(n);
    for(auto &it:t)
    {
        cin>>it;
    }
    int B=0,A=0;
    int l=0,r=n-1,reqA=t[l],reqB=t[r];
    if(l==r)
    {
        cout<<"1 0";
        return;
    }
    while(l<r)
    {
        if(reqA>reqB)
        {
            B++;
            r--;
            if(l==r) 
            {
                A++;
                break;
            }
            reqA-=reqB;
            reqB=t[r];
        }
        else if(reqA<reqB)
        {
            A++;
            l++;
            if(l==r) 
            {
                B++;
                break;
            }
            reqB-=reqA;
            reqA=t[l];
        }
        else 
        {
            A++;
            B++;
            r--;
            l++;
            if(l==r) 
            {
                A++;
                break;
            }
            reqB=t[r];
            reqA=t[l];
        }
    }

    cout<<A<<" "<<B;
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