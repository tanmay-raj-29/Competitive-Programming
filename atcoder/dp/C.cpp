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
#define ll long long
#define fr first
#define sc second
#define pb push_back
#define len(s) s.size()
#define all(v) v.begin(), v.end()
// =================

const int mod = 1e9;
const int N = 3e5 + 1;

void solve()
{
    int n; cin>>n;
    vector<vector<int>> t(3);
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            int x; cin>>x;
            t[j].pb(x);
        }
    }
    // deb(t);
    vector<vector<int>> ans(n,vector<int>(3,0));
    for(int i : {0,1,2}) {
        ans[0][i]=t[i][0];
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<3;j++) {
            for(int k=0;k<3;k++) {
                if(j!=k) {
                    ans[i][j]=max(ans[i-1][k]+t[j][i],ans[i][j]);
                }
            }
        }
    }
    // deb(ans);
    cout<<max({ans[n-1][0],ans[n-1][1],ans[n-1][2]});
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
    while (t--)
        solve();
    return 0;
}