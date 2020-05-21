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

        int n,cnt=0; cin>>n;
        vi vr(n),vb(n);
        for(int& x:vr) cin>>x;
        for(int& x:vb) {
            cin>>x;
            if(x) cnt++;
        }
        int sum=0;
        if(cnt==n) {
            cout<<"-1\n";
            return 0;
        }
        int sumr=0,sumb=0;
        cnt=0;
        f(i,0,n) {
            if(vb[i] && vr[i]) sum++,sumr++,sumb++;
            else if(vb[i] && !vr[i]) sum++,sumb++;
            else if(vr[i]) cnt++;
        }
        if(cnt==0) cout<<"-1\n";
        else {
            int ans=((sumb-sumr+1)%cnt? (sumb-sumr+1)/cnt +1 : (sumb-sumr+1)/cnt);
            cout<<ans<<"\n";
        }
    
    return 0 ;  
}