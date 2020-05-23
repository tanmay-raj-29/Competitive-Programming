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

    int sieve=1e6+1;
    bool prime[sieve+1];
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i*i<=sieve;i++) if(prime[i]) for(int j=i*i;j<=sieve;j+=i) prime[j]=false;
    
    int t; cin>>t; while(t--) {
       int n,k; cin>>n>>k;
       if(n%2) {
           if(prime[n]) n+=n,k--;
           else {
               f(i,3,n) if(n%i==0) {n+=i,k--; break;}
           }
       }
       cout<<n+2*k<<endl;
    }
    
    return 0 ;  
}