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
        string s; cin>>s;
        string s1="";
        int cnt=0;
        f(i,0,n) {
            if(s[i]%2) cnt++;
        }
        if(!cnt || cnt==1) cout<<"-1\n";
        else {
            int cnt1;
            if(cnt%2==0) cnt1=0;
            else cnt1=1;
            f(i,0,n) {
                if(s[i]%2 && cnt1!=cnt) s1+=s[i],cnt1++;
            }
            cout<<s1<<endl;
        }
    }
    
    
    return 0 ;  
}