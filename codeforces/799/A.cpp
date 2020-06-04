#include <bits/stdc++.h>
#define pb push_back
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define f(i, a, n) for (int i = a; i < n; i++)
using namespace std;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef vector<string> vs;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int tdash = ceil(1.0 * (n) / k) * t;
    int t1 = 0, t2 = d;
    int num = 0, i = 0;
    t1 = ceil(1.0 * d / t);
    if (t1 * k >= n)
    {
        cout << "NO";
        return 0;
    }

    num = t1 * k;
    t1 *= t;

    while (num < n)
    {
        num += k;
        if (i % 2)
            t1 += t;
        else
            t2 += t;
        i++;
    }
    cout << (max(t1, t2) >= tdash ? "NO" : "YES");
    return 0;
}