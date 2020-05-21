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
        int a,b,c; cin>>a>>b>>c;
        int sum=a+b+c;
        a=max3(a,b,c), c=min3(a,b,c), b=sum-a-c;
        int ans=0;
        if(a) ans++,a--;
        if(b) ans++,b--;
        if(c) ans++,c--;
        if(a && b) ans++,a--,b--;
        if(a && c) ans++,a--,c--;
        if(b && c) ans++,b--,c--;
        if(a && b && c) ans++;
        cout<<ans<<"\n";
    }
    return 0 ;  
}