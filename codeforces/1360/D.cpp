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

    int sieve=1e6;
    bool prime[sieve+1];
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i*i<=sieve;i++) if(prime[i]) for(int j=i*i;j<=sieve;j+=i) prime[j]=false;

    int t; cin>>t; while(t--) {
        int n,k; cin>>n>>k;
        if(k>=n) {
            cout<<"1\n";
            continue;
        }
        if(n<=sieve && prime[n]) {
            cout<<n<<"\n";
            continue;
        }
        int ans=n;
        
        for(int i=2;i*i<=n;i++) {
            if(n%i==0) {
                if(i<=k) ans=min(ans,n/i);
                if(n/i<=k) ans=min(ans,i);
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0 ;  
}