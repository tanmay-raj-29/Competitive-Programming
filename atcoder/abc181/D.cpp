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
    int n;
    string s;
    cin>>s;
    n=len(s);
    mii mp;
    if(n==1) {
        if(s=="8") cout<<"Yes";
        else cout<<"No";
        return;
    }
    f(i,0,n) {
        int x= s[i]-'0';
        mp[x]++;
    }
    if(n==2) {
        f(i,10,100) {
        if(i%8==0) {
            int m=i;
            mii num;
            while (m)
            {
                int digit=m%10;
                num[digit]++;
                m/=10;
            }
            bool ok=1;
            tr(it,num) {
                // deb(it);
                // deb(mp[it.fr]);
                if(mp[it.fr]<it.sc) {
                    ok=0;
                    break;
                }
            }
            if(ok) {
                cout<<"Yes";
                return;
            }
        }
        }
        cout<<"No";
        return;
    }
   
    f(i,100,1000) {
        if(i%8==0) {
            int m=i;
            mii num;
            while (m)
            {
                int digit=m%10;
                num[digit]++;
                m/=10;
            }
            bool ok=1;
            tr(it,num) {
                // deb(it);
                // deb(mp[it.fr]);
                if(mp[it.fr]<it.sc) {
                    ok=0;
                    break;
                }
            }
            if(ok) {
                cout<<"Yes";
                return;
            }
        }
    }
    cout<<"No";
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
    while (t--)
        solve();
    return 0;
}