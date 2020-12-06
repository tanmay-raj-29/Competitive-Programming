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
#define deb(x) cout << #x << "=" << x << endl
// =================

const int mod = 1e9+7;
const int N = 3e5 + 1;

bool pal(string s)
{
    int n=len(s);
    bool ok=1;
    f(i,0,n/2)
    {
        if(s[i]!=s[n/2+i])
        {
            ok=0;
            break;
        }
    }
    return ok&&len(s)%2==0;
}

void solve()
{
    string t;
    cin>>t;
    string aux;
    int n=len(t);
    f(i,0,n) if(t[i]!='a') aux+=t[i];
    if(aux==t)
    {
        if(pal(aux))
        {
            f(i,0,(n+1)/2) cout<<aux[i];
        }
        else cout<<":(";
        return;
    }
    if(pal(aux))
    {
        string ans;
        int i=0,curr=0;
        while(curr<(len(aux)+1)/2)
        {
            ans+=t[i];
            if(aux[curr]==t[i]) curr++;
            i++;
        }
        while(t[i]=='a')
        {
            ans+=t[i];
            i++;
        }
        while(i<n)
        {
            if(t[i]=='a') 
            {
                cout<<":(";
                return;
            }
            i++;
        }
        cout<<ans;
    }
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