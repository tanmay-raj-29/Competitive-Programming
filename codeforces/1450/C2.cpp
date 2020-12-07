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

void solve()
{
    int n;
    cin>>n;
    char mat[n][n];
    int cnt[2][3]={0,0,0,0,0,0};
    f(i,0,n) f(j,0,n) 
    {
        cin>>mat[i][j];
        cnt[0][(i+j)%3]+=mat[i][j]=='X';
        cnt[1][(i+j)%3]+=mat[i][j]=='O';
    }
    int optX,optO,mx=mod;
    f(i,0,3)
    {
        f(j,0,3)
        {
            if(i!=j)
            {
                if(cnt[0][i]+cnt[1][j]<mx)
                {
                    mx=cnt[0][i]+cnt[1][j];
                    optX=i;
                    optO=j;
                }
                if(cnt[0][j]+cnt[1][i]<mx)
                {
                    mx=cnt[0][j]+cnt[1][i];
                    optX=j;
                    optO=i;
                }
            }
        }
    }
    f(i,0,n)
    {
        f(j,0,n)
        {
            if(mat[i][j]!='.' && (i+j)%3==optX%3) mat[i][j]='O';
            if(mat[i][j]!='.' && (i+j)%3==optO%3) mat[i][j]='X';
        }
    }
    f(i,0,n)
    {
        f(j,0,n) cout<<mat[i][j];
        cout<<"\n";
    }
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