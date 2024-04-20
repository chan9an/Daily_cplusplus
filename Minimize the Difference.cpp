#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MOD = 998244353;

bool possible(const vector<int>& A, int target) {
    vector<int> dp(target + 1, 1);
    for (int a : A) {
        vector<int> ndp(target + 1, 0);
        for (int i = 0; i <= target; ++i) {
            if (i - a >= 0) {
                ndp[i] = dp[i - a];
            }
            if (i + a <= target) {
                ndp[i] |= dp[i + a];
            }
        }
        swap(dp, ndp);
    }
    return any_of(dp.begin(), dp.end(), [](int x) { return x; });
}

void solve() {
int N;
    cin >> N;
    vector<int> A(N);
    for (int& a : A) {
        cin >> a;
    }
    int M = *max_element(A.begin(), A.end());
    int l = M, r = 2 * M;
    while (l < r) {
        int m = (l + r) >> 1;
        if (possible(A, m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    vector<int> dp(l + 1, 1);
    for (int a : A) {
        vector<int> ndp(l + 1, 0);
        for (int i = 0; i <= l; ++i) {
            if (i - a >= 0) {
                ndp[i] = (ndp[i] + dp[i - a]) % MOD;
            }
            if (i + a <= l) {
                ndp[i] = (ndp[i] + dp[i + a]) % MOD;
            }
        }
        swap(dp, ndp);
    }
    int ans = 0;
    for (int x : dp) {
        ans = (ans + x) % MOD;
    }
    cout << l << " " << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
