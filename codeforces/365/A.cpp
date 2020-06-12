#include <bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
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

    int n, k;
    cin >> n >> k;
    int cnt = 0;
    f(i, 0, n)
    {
        set<int> s;
        int a;
        cin >> a;
        while (a)
        {
            s.insert(a % 10);
            a /= 10;
        }
        if (len(s) > k)
        {
            int prev = 0;
            for (auto it : s)
            {
                if (prev != it)
                    break;

                prev++;
            }
            if (prev > k)
                cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}