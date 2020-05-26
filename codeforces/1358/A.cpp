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
typedef vector<pll> vpll;
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

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (n == 1 && m == 1)
            cout << "1\n";
        else if (n == 1)
            cout << m / 2 + m % 2 << "\n";
        else if (m == 1)
            cout << n / 2 + n % 2 << "\n";
        else
        {
            int ans = (m / 2) * n + (m % 2) * (n / 2 + n%2);
            int ans1 = (n / 2) * m + (n % 2) * (m / 2 + m%2);
            cout<<min(ans,ans1)<<endl;
        }
    }

    return 0;
}