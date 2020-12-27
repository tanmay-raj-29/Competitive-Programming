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

void solve()
{
    int n,k;
    string s; cin>>s>>k;
    n=len(s);
    int j=0;
    while (k && j<n)
    {
        char mx=s[j];
        int index=j;
        f(i,j,j+k+1) {
            if(i>=n) break;
            if(s[i]>mx) mx=s[i],index=i;
        }
        if(index==j) {
            j++;
            continue;
        }
        while (k && index-1>=0 && s[index]>s[index-1])
        {
            if(!k) break;
            char tmp=s[index];
            s[index]=s[index-1];
            s[index-1]=tmp;
            k--;
            index--;
        }
        j++;
    }
    cout<<s;
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