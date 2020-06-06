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

    int n;
    cin >> n;
    char a[n][n];
    f(i, 0, n) f(j, 0, n) cin >> a[i][j];
    char x = a[0][0], o = a[1][0];
    if(x==o) {
        cout<<"NO";
        return 0;
    }
    bool ok = true;
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            if (i == j && a[i][j] != x)
            {
                ok = false;
                break;
            }
            else if (j == n - i - 1 && a[i][j] != x)
            {
                ok = false;
                break;
            }
            else if (a[i][j] != o && j != n - i - 1 && i != j)
            {
                ok = false;
                break;
            }
        }
    }
    if (ok)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}