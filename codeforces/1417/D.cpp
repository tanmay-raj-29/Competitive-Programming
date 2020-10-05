#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]"<<endl;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#define deb(x...) cout << #x << " = ["; _print(x)
// =================
#define f(i, k, n) for (int i = k; i < n; i++)
#define r(i, k, n) for (int i = k; i >= n; i--)
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define len(s) s.size()
#define all(v) v.begin(), v.end()
#define tr(it, v) for (auto &it : v)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;
// =================

const int mod = 1e9;
const int N = 3e5 + 1;

struct ans
{
    int i,j,x;
};


void solve()
{
    int n;
    cin>>n;
    vi a(n);
    int sum=0;
    tr(it,a) {
        cin>>it;
        sum+=it;
    }
    if(sum%n) {
        cout<<"-1\n";
        return;
    }
    int y=sum/n;
    vector<ans> v;
    
    f(i,1,n) {
        if(a[i]%(i+1)==0) {
            v.pb({i+1,1,a[i]/(i+1)});
            a[0]+=a[i];
            a[i]=0;
        } else {
            v.pb({1,i+1,i+1-a[i]%(i+1)});
            a[0]-=i+1-a[i]%(i+1);
            a[i]+=i+1-a[i]%(i+1);
            // deb(a,i+1-a[i]%(i+1),a[i],a[0]);
            v.pb({i+1,1,a[i]/(i+1)}); 
            a[0]+=a[i];
            a[i]=0;
        }
    }
    // deb(a);
    f(i,1,n) {
        v.pb({1,i+1,y});
        a[0]-=y;
        a[i]+=y;
    }

    // deb(a);
    cout<<len(v)<<"\n";
    tr(it,v) {
        cout<<it.i<<" "<<it.j<<" "<<it.x<<"\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}