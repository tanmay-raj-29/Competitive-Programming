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
const double pi=3.141592653589;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t; cin>>t; while(t--) {
        int r,g,b; cin>>r>>g>>b;
        int mn=min3(r,g,b),mx=max3(r,g,b),mid=r+g+b-mx-mn;
        if(mn+mid<=mx) cout<<mn+mid<<endl;
        else {
            int ans=mx-mid;
            cout<<mn+min(mid-(mn-ans)/2,mid-(mn-ans+1)/2)<<endl;
        }
    }

    return 0;
}