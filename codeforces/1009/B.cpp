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
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
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
    string s;
    cin >> s;
    int n = len(s);
    bool ok = 0;
    int flag = n;
    f(i, 0, n)
    {
        if (s[i] == '2' && !ok)
            ok = 1, flag = i;
        if (i)
        {
            if (!ok)
            {
                if (s[i] == '0')
                {
                    int j = i;
                    while (j && s[j] == '0' && s[j - 1] == '1')
                    {
                        swap(s[j], s[j - 1]);
                        j--;
                    }
                }
            }
            else if (s[i] == '1')
                break;
        }
    }
    string ans(s, 0, flag);
    // deb2(ans,s);
    f(i, flag, n)
    {
        if (s[i] == '1')
            ans += '1';
    }
    f(i, flag, n)
    {
        if (s[i] != '1')
            ans += s[i];
    }
    cout << ans;
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