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

    int m=(1e5)*5+1;
    vll v(m);
    v[1]=0;
    int j=1;
    for(int i=3;i<m;i+=2) {
        v[i]=v[i-2] + 1ll*j*2*(2*i-2);
        j++;
    }
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        cout<<v[n]<<endl;
    }
    return 0 ;  
}