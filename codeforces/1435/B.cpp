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
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
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

const int mod = 1e9+7;
const int N = 3e5 + 1;

void solve()
{
    int n,m;
    cin>>n>>m;
    int rows[n][m],cols[m][n];
    f(i,0,n) f(j,0,m) cin>>rows[i][j];
    f(i,0,m) f(j,0,n) cin>>cols[i][j];
    
    int ans[n][m];

    f(i,0,m) {
        vi fs;
        f(j,0,n) fs.pb(rows[j][i]);
        sort(all(fs));
        // deb(fs);
        bool found=1;
        int index=0;
        f(j,0,m) {
            found=1;
            index=j;
            // f(k,0,n) cout<<cols[j][k]<<" ";
            // cout<<endl;
            f(k,0,n) {
                int req=cols[j][k];
                int l=0,r=len(fs)-1;
                bool ok=0;
                while (l<=r)
                {
                    int mid=l+(r-l)/2;
                    if(fs[mid]==req) {
                        ok=1;
                        break;
                    }
                    else if(fs[mid]<req) l=mid+1;
                    else r=mid-1;
                }
                // deb(ok,cols[j][k]);
                if(!ok) {
                    // cout<<index<<" R"<<endl;
                    found=0;
                    break;
                }
            }
            if(found) break;
        }
        // deb(index);
        if(found) {
            f(j,0,n) ans[j][i]=cols[index][j];
        }
    }
    f(i,0,n) {
        f(j,0,m) cout<<ans[i][j]<<" ";
        cout<<"\n";
    }

}

signed main()
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