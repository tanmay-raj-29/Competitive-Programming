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
	int n; cin>>n;
	int k1; cin>>k1;
	queue<int> p1,p2; 
	
	f(i,0,k1) {
		int x; cin>>x;
		p1.push(x);
	}

	int k2; cin>>k2;
	
	f(i,0,k2) {
		int x; cin>>x;
		p2.push(x);
	}

	int i=0;
	while (k1 && k2)
	{
		i++;
		// deb2(p1.front(),p2.front());
		if(p1.front()>p2.front()) {
			p1.push(p2.front());
			p1.push(p1.front());
			p1.pop();
			p2.pop();
			k1++;
			k2--;
		}
		else {
			p2.push(p1.front());
			p2.push(p2.front());
			p1.pop();
			p2.pop();
			k2++;
			k1--;
		}
		// deb2(k1,k2);
		if(i==500) break;
	}	
	if(i==500) {
		cout<<"-1";
		return;
	}
	cout<<i<<" "<<(k2?"2":"1");
	 
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