#include <bits/stdc++.h>
using namespace std;
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
// =================
#define f(i, k, n) for (int i = k; i < n; i++)
#define ll long long
#define int ll
#define pb push_back
#define fr first
#define sc second
#define len(s) s.size()
#define all(v) v.begin(), v.end()
#define deb(x) cout << #x << "=" << x << endl
// =================

const int mod = 1e9+7;
const int N = 3e2 + 1;

// int dp[N][N];

void solve()
{
    int n;
    cin>>n;
    // dp[i][j] -> answer if i total length and j parts
    int dp[N][N][2]; // dp[i][j][0] -> no cut at ith index & dp[i][j][1] -> cut at ith index
    memset(dp,0,sizeof(dp));
    // f(i,0,12) dp[0][i][0]=1;
    dp[0][0][0]=1;
    f(i,0,n+1)
    {
        f(j,0,min(12ll,i+1))
        {
            if(i==0) dp[i][j][0]=1;
            else
            {
                dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
                if(j>=1) dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1];
            }
        }
    }
  //   int L=n;
  //   for(int i=0;i<=L;i++)
  // {
  //   for(int j=0;j<=11&&j<=i;j++)
  //   {
  //     if(i==0)
  //     {
  //       dp[i][j][0]=1;
  //       dp[i][j][1]=0;
  //     }
  //     else
  //     {
  //       dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
  //       if(j==0)
  //       {
  //         dp[i][j][1]=0;
  //       }
  //       else
  //         dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1];
  //     }
  //   }
  // }
    cout<<dp[n][11][0];



    // f(i,1,n+1)
    // {
    //     f(j,1,13)
    //     {
    //         f(k,0,i) dp[i][j]+=dp[k][j-1];
    //     }
    // }
    
    // f(i,1,n+1)
    // {
    //     f(j,1,min(12,i))
    //     {
    //         f(k,0,i) dp[i][j]+=dp[k][j-1];
    //     }
    // }

    // f(i,0,n+1)
    // {
    //     f(j,0,12) cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    // cout<<dp[n][12];
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