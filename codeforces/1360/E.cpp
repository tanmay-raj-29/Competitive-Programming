#include <bits/stdc++.h> 
#define pb push_back
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define f(i,a,n) for(int i=a;i<n;i++)
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef pair<int,int> pii; 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        string a[n];
        int flag=0;
        f(i,0,n) cin>>a[i];
        f(i,0,n-1) {
            f(j,0,n-1) {
                if(a[i][j]=='1') {
                    if(a[i][j+1]=='1' || a[i+1][j]=='1') continue;
                    else {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0 ;  
}      