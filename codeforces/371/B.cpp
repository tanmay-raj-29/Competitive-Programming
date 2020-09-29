#include <bits/stdc++.h>
using namespace std;
#define f(i, k, n) for (int i = k; i < n; i++)
#define r(i, k, n) for (int i = k; i >= n; i--)
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define len(s) s.size()
#define all(v) v.begin(), v.end()
#define tr(it, v) for (auto &it : v)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << ","<< #z << "=" << z << endl
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;
// =================

const int mod = 1e9;
const int N = 3e5 + 1;

void fun(int a, vi &ans){
    while (a%2==0 || a%3==0 || a%5==0)
    {
        if(a%2==0) a/=2, ans[1]++;
        else if(a%3==0) a/=3, ans[2]++;
        else a/=5, ans[3]++;
    }
    ans[0]=a;
}

void solve()
{
    int a,b; cin>>a>>b;
    if(a==b) {
        cout<<"0";
        return;
    }
    vi a1(4),b1(4);
    fun(a,a1);
    fun(b,b1);
    if(a1[0]!=b1[0]) {
        cout<<"-1";
    } 
    else {
        cout<<abs(a1[1]-b1[1])+ abs(a1[2]-b1[2])+ abs(a1[3]-b1[3]);
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
    while (t--)
        solve();
    return 0;
}