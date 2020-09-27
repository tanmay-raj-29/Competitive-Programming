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
	vi a(n),b(n),c(n),isTaken(n);
	bool ok=1;
	f(i,0,n) {
		a[i]=n-i-1;
		c[i]=i;
		
		if(a[i]==c[i]) {
			if(isTaken[0]) ok=0;
			else b[i]=0;
		} 
		else if(a[i]>c[i]) {
			b[i]=n+c[i]-a[i];
			ok=!isTaken[b[i]];
			isTaken[b[i]]=1;
		}
		else {
			b[i]=c[i]-a[i];
			ok=!isTaken[b[i]];
			isTaken[b[i]]=1;
		}
		
	}
	if(ok) {
		f(i,0,n) cout<<a[i]<<" ";
		cout<<endl;
		f(i,0,n) cout<<b[i]<<" ";
		cout<<endl;
		f(i,0,n) cout<<c[i]<<" ";
		cout<<endl;
	} else cout<<"-1"; 
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