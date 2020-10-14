#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]"<<endl;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#define deb(x...) cout << #x << " = ["; _print(x)
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
// =================
#define f(i, k, n) for (int i = k; i < n; i++)
#define r(i, k, n) for (int i = k; i >= n; i--)
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define len(s) s.size()
#define all(v) v.begin(), v.end()
#define tr(it, v) for (auto &it : v)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;
// =================

const int mod = 1e9+7;
const int N = 3e5 + 1;

void solve()
{
	ll a,b; cin>>a>>b;
	ll n=lcm(a,b);

	ll numA=0,numB=0;
	ll t=0;
	int initialA=a>b,initialB=b>a,x=a,y=b;
	while (min(a,b)<=n)
	{
		t=min(a,b);
		if(a==b) numA+=initialA,numB+=initialB;
		else if(t==a) numA++;
		else numB++;
		
		// deb(a,b,numA,numB);

		if(a>b) b+=y;
		else if(b>a) a+=x;
		else a+=x,b+=y;
	}
	puts(numA>numB ? "Dasha" : numA!=numB ? "Masha" : "Equal");
}

signed main()
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