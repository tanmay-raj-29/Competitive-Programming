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
int n,m;

bool ch(int x,int y)
{
    return x>=0&&y>=0&&x<n&&y<m;
}

void solve()
{
    cin>>n>>m;
    char c[n][m];
    int aux[n][m];
    memset(aux,0,sizeof(aux));
    f(i,0,n) f(j,0,m) {
        cin>>c[i][j];
        aux[i][j]=(c[i][j]=='*');
    }
    for(int i=n-1;i>=0;i--)
    {
        f(j,0,m)
        {
            if(ch(i,j+1)&&ch(i,j-1)&&ch(i-1,j)&&aux[i][j]&&aux[i][j+1]&&aux[i][j-1]&&aux[i-1][j])
            {
                amax(aux[i-1][j],min({aux[i][j-1],aux[i][j],aux[i][j+1]})+1);
            }            
        }
    }
    // f(i,0,n)
    // {
    //     f(j,0,m) cout<<aux[i][j]<<" ";
    //     cout<<"\n";
    // }
    int ans=0;
    f(i,0,n) f(j,0,m) ans+=aux[i][j];
    cout<<ans<<"\n"; 
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