#include <iostream>
using namespace std;

#define N 1000005
#define MOD 1000000007
#define int long long

int ans2[N + 5] = { 0 }, dp[N] = { 0 }, dp1[N] = { 0 }, dp2[N] = { 0 }, prev3 = 3,prev2 = 3;

void solve(int n)
{
	for (int i = prev3 + 1; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 3] + 2 * dp1[i - 2]) % MOD;
		dp1[i] = (dp2[i - 1] + dp1[i - 3]) % MOD;
		dp2[i] = (dp[i - 3] + dp2[i - 3]) % MOD;
	}
}

int32_t main()
{
	ans2[0] = ans2[1] = dp1[1] = dp1[2] = dp1[3] = dp2[2] = 0;
	dp[1] = dp[2] = ans2[2] = ans2[3] = dp2[3] = 1, dp[3] = 2;
	int t;
	cin >> t;
	while (t--)
	{
		int k, n;
		cin >> k >> n;
		if (k == 1)
			cout << (n % 3 == 0) << endl;
		else if (k == 2)
		{
			if (prev2 >= n) { cout << ans2[n] << endl; continue; }
			for (int i = prev2 + 1; i <= n; i++)
				ans2[i] = (ans2[i - 2] + ans2[i - 3]) % MOD;
			cout << ans2[n] << endl;
			prev2 = n;
		}
		else { if (prev3 < n) solve(n),prev3 = n; cout << dp[n] << endl;  }
	}
	return 0;
}
