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

const int mod = 1e9;
const int N = 3e5 + 1;

void solve()
{
	int n,lng; cin>>n>>lng;
	vi a(n);
	tr(it,a) cin>>it;
	int i=0,j=n-1;
	double l=0,r=lng;
	double t=0,tx=a[0],ty=r-a[n-1];
	int sx=1,sy=1;
	while (j>=i)
	{
		if(tx>ty) {
			t+=ty;
			tx-=ty;
			r-=ty*sy;
			sy++;
			l+=ty*sx;
			if(i==n-1 || j==0) break;
			ty=1.0*(a[j]-a[j-1])/sy;
			j--;
		} else if(ty>tx) {
			t+=tx;
			ty-=tx;
			l+=sx*tx;
			r-=tx*sy;
			sx++;
			if(i==n-1 || j==0) break;
			tx=1.0*(a[i+1]-a[i])/sx;
			i++;
		} else {
			t+=tx;
			l=a[i];
			r=a[j];
			sx++;
			sy++;
			if(i==n-1 || j==0) break;
			tx=1.0*(a[i+1]-a[i])/sx;
			ty=1.0*(a[j]-a[j-1])/sy;
			i++;
			j--;
		}
	}
	t+=1.0*(r-l)/(sx+sy);
	printf("%0.9f\n",t);
	
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
	cin>>t;
	while (t--)
		solve();
	return 0;
}