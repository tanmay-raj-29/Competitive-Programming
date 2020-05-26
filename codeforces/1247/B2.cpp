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
        int n, k, d;
        cin >> n >> k >> d;
        vi v(n);
        f(i, 0, n) cin >> v[i];
        mii mp;
        f(i, 0, d)
            mp[v[i]]++;

        // for (auto it : mp)
        //     cout << it.fr << " " << it.sc<<endl;
        //cout << endl;
        int ans = len(mp);
        int cnt = ans;
        //cout<<"cnt "<<cnt<<endl;
        f(i, 1, n - d + 1)
        {
            
            mp[v[i + d - 1]]++;
            if (mp[v[i + d - 1]] == 1)
                cnt++;

            mp[v[i - 1]]--;

            if (!mp[v[i - 1]])
                cnt--;

            // for (auto it : mp)
            //     cout << it.fr << " " << it.sc<<endl;
            // cout << endl;
            //  cout<<"cnt "<<cnt<<endl;
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }

    return 0;
}