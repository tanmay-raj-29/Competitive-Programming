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

bool decToOctal(int n)
{
    int octalNum[100];
 
    int i = 0;
    while (n != 0) {
 
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }
 
    // printing octal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        if(octalNum[j]==7) return false;
    return true;
}


void solve()
{
    int n;
    cin>>n;
    int cnt=0;
    f(i,1,n+1)
    {
        bool ok=1;
        int x=i;
        while(x)
        {
            if(x%10==7)
            {
                ok=0;
                break;
            }
            x/=10;
        }
        if(ok) ok=decToOctal(i);
        if(ok) cnt++;
    }
    cout<<cnt;
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