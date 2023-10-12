/*https://www.codechef.com/ZCOPRAC/problems/ZCO23001?tab=statement*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

const int N = 1000005;
bool b[N];
int next[N], ans[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::fill(b, b + m + 5, false);

	for (int i = 0; i < n; ++i) {
		int p;
		std::cin >> p;
		b[p] = true;
	}

	next[m + 3] = -1;

	for (int i = m + 2; i >= 0; --i) {
		next[i] = next[i + 1];
		if (b[i + 1]) next[i] = i + 1;
	}

	for (int x = 0; x <= m; ++x) {
		ans[x] = 0;
		int cur = next[0] + x;
		while (cur != -1) {
			++ans[x];
			if (cur > m) break;
			cur = next[cur];
			if (cur != -1) cur += x;
		}
	}

	int q;
	std::cin >> q;

	while (q--) {
		int f;
		std::cin >> f;

		auto it = std::lower_bound(ans, ans + m + 1, f, [&](int i, int j) {
			return i > j;
		});

		std::cout << int(it - ans) << '\n';
	}

	return 0;
}
