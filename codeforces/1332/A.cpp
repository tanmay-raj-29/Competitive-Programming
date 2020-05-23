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
        int a,b,c,d; cin>>a>>b>>c>>d;
        int x,y,x1,y1,x2,y2; cin>>x>>y>>x1>>y1>>x2>>y2;
        if((x2-x1==0 && (a!=0 || b!=0)) || (y2-y1==0 && (c!=0 || d!=0))) cout<<"NO\n";
        else if(x1<=x-a+b && x-a+b<=x2 && y-c+d>=y1 && y-c+d<=y2) cout<<"YES\n";
        else cout<<"NO\n";
    }            
    return 0 ;  
}