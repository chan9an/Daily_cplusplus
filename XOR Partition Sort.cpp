#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define mod1 998244353
#define mod2 1000000007
#define eps 1e-6

#define pb push_back
#define endl '\n'

void solve() {
    int n, q; cin >> n >> q;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector <int> dp(n + 1, n);
    vector pos(2, vector <int> (20, n));
    for (int i = n - 1; i >= 1; i--) {
        int j = 31 - __builtin_clz(a[i] ^ a[i + 1]);
        if (a[i] == a[i + 1]) {
            dp[i] = dp[i + 1];
            continue;
        }
        int x = a[i] >> j & 1;
        dp[i] = pos[x ^ 1][j];
        pos[x][j] = i;
        dp[i] = min(dp[i], dp[i + 1]);
    }
    
    vector rmq(20, vector <int> (n + 1, n));
    for (int i = 0; i < 19; i++) {
        for (int j = 1; j <= n; j++) rmq[i][j] = (i ? rmq[i - 1][min(rmq[i - 1][j] + 1, n)] : dp[j]);
    }
    while (q --) {
        int l, r; cin >> l >> r;
        int ans = 1;
        for (int i = 19; i >= 0; i--) {
            if (rmq[i][l] >= r) continue;
            l = rmq[i][l] + 1;
            ans += 1 << i;
        }
        cout << ans << "\n";
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int Tc = 1;
	cin >> Tc;
	while (Tc --) {
		solve();
	}
	return 0;
}
