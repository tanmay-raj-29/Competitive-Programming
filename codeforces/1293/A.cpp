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
        int n,s,k; cin>>n>>s>>k;
        int mn=MOD;
        vi v(k);
        for(int& x: v) cin>>x;
        sort(all(v));
        int i=1;
        auto it=find(v.begin(),v.end(),s);
        auto itt=it;
        if(it==v.end()) cout<<"0\n";
        else {
            while(1) {
                if(s+i<=n) it=find(v.begin(),v.end(),s+i);
                if(s-i>=1) itt=find(v.begin(),v.end(),s-i);
                if(it==v.end() || itt==v.end()) {
                    cout<<i<<endl;
                    break;
                }
                i++;
            }
        }
    }
    
    return 0 ;  
}