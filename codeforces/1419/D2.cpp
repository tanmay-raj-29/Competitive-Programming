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
    int n;
    cin >> n;
    vi a(n);
    tr(it, a) cin >> it;
    sort(all(a));
    int l = 0, r = n - 1, ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int j = mid, cnt = a[mid - 1] < a[n - 1] ? 1 : 0;
        if (!cnt)
        {
            r = mid - 1;
            continue;
        }
        f(i, 0, mid)
        {
            int k = 0;
            while (j < n - 1)
            {
                if (a[i] < a[j])
                {
                    cnt++;
                    j++;
                    break;
                }
                j++;
            }
        }
        if (cnt > mid)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
        // deb3(mid,ans,cnt);
    }
    cout << ans << endl;
    cout << a[n - 1] << " ";
    int j = n - 2;
    r(i, ans - 1, 0)
    {
        cout << a[i] << " " << a[j] << " ";
        j--;
    }
    f(i, ans, j + 1) cout << a[j] << " ";
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