#include"bits/stdc++.h"
using namespace std;
#define FIO  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define int long long
#define nl "\n"
#define ff first
#define ss second
#define pb push_back
#define w(t) int t; cin >> t; while (t--)
#define deci(n) fixed << setprecision(n)
#pragma GCC optimize ("-O3")

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)              cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define pi 3.1415926535897932384626433832795
// replace int with int32_t
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef priority_queue<int> pq;

const int MOD = 1e9 + 7;
int md = MOD;

const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void google(int x) {
	cout << "Case #" << x << ": ";
}

int Power(int n, int x) {
	int ans = 1; while (x > 0) {
		if (x & 1) ans = (ans * n) % md;
		n = (n * n) % md; x = x >> 1;
	} return ans;
}

vl fact, inv;

void inverse(ll n)
{	if (n >= inv.size()) {
		ll size = inv.size(); size = size == 0 ? 1 : size;
		inv.resize(n + 1); inv[0] = 1;
		for (ll i = size; i <= n; i++)inv[i] = Power(fact[i], md - 2);
	}
}

void factorial(ll n)
{	if (n >= fact.size()) {
		ll size = fact.size(); size = size == 0 ? 1 : size;
		fact.resize(n + 1); fact[0] = 1; for (ll i = size; i <= n; i++)
			fact[i] = (fact[i - 1] * i) % md;
	}
}

ll ncr(ll n, ll r) {
	if (r > n) return 0; if (r == 0 || r == n) return 1;
	return (((fact[n] * inv[r]) % md) * inv[n - r]) % md;
}

vl SieveOfEratosthenes(int n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	for (int p = 2; p * p <= n; p++)
	{	if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	vl ans; for (int p = 2; p <= n; p++)if (prime[p])ans.pb(p); return ans;
}
vi primeFactors(int n)
{
	vi ans;
	while (n % 2 == 0) {ans.pb(2); n /= 2;}
	for (int i = 3; i * i <= n; i = i + 2) {
		while (n % i == 0) {ans.pb(i); n /= i;}
	}
	if (n > 2)ans.pb(n); return ans;
}

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
	if (start < 0) start = 0;
	if (end < 0) end = (int)(v.size());

	for (int i = start; i < end; i++)
		cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

//********************************************** END OF TEMPLATES************************************************//

void solve() {

	int n; cin >> n;
	int same = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (i == x)
			same++;
		else {
			ans += (same + 1) / 2;
			same = 0;
		}
	}
	ans += (same + 1) / 2;
	cout << ans  << nl;
}

int32_t main()
{

	FIO
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif

	w(t) {
		solve();
	}

}
