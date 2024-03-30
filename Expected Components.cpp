// Contribution Technique

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;

void add(ll &a, ll b) {
	a += b;
	if (a >= mod)  a -= mod;
}

void sub(ll &a, ll b) {
	a -= b;
	if (a < 0)  a += mod;
}

ll powmod(ll a, ll b) {
	a %= mod;
	if (b == -1)  b = mod - 2;
	ll ret = 1;
	while (b) {
		if (b & 1)  ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

void solve() {
	ll n, k;  cin >> n >> k;
	vector<int> black(k), is_black(n);
	for (auto &u: black) {
		cin >> u;  u--;
		is_black[u] = 1;
	}
	vector<array<int, 2>> edges(n - 1);
	vector<int> deg(n);
	for (auto &[u, v]: edges) {
		cin >> u >> v;  u--, v--;
		deg[u]++, deg[v]++;
	}

	ll sum1 = 0;
	for (int u: black) {
		sum1 += deg[u] - 1;
	}

	ll sum2 = 0;
	for (auto [u, v]: edges) {
		if (is_black[u] and is_black[v]) {
			sum2++;
		}
	}

	for (ll x = 1; x <= k; ++x) {
		ll ans = 1;
		ll ways1 = x * powmod(k, -1) % mod;
		add(ans, sum1 * ways1 % mod);

		ll ways2 = x * (x - 1) % mod * powmod(k * (k - 1), -1) % mod;
		sub(ans, sum2 * ways2 % mod);

		cout << ans << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int tc;  cin >> tc;
	while (tc--) {
		solve();
	}
}
