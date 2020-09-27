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
	string s;
	cin >> s;
	string ans = "";
	f(i, 0, n)
	{
		switch (s[i])
		{
		case '9':
			ans += "7332";
			break;
		case '8':
			ans += "7222";
			break;
		case '7':
			ans += "7";
			break;
		case '6':
			ans += "53";
			break;
		case '5':
			ans += "5";
			break;
		case '4':
			ans += "322";
			break;
		case '3':
			ans += "3";
			break;
		case '2':
			ans += "2";
			break;
		default:
			break;
		}
	}
	sort(all(ans),greater<int>());
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