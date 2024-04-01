/*
  ! Though life is hard, I want it to be boiling.
  ! Created: 2024/03/28 09:43:52
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

typedef pair<int, double> PII;

int n, m;
double dis[N];
vector<PII> to[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    to[x].emplace_back(y, 1. * p / q);
  }
  fill(dis + 1, dis + n + 1, 1e18), dis[n] = 0;
  for (int i = n - 1; i >= 1; i--) {
    sort(to[i].begin(), to[i].end(), [&](PII x, PII y) {
      return dis[x.first] < dis[y.first];
    });
    double sum = 1, res = 0;
    for (auto j : to[i]) {
      int x; double y;
      tie(x, y) = j;
      res = sum * y * (dis[x] + 2) + res;
      sum = sum * (1 - y);
      dis[i] = min(dis[i], (res + sum) / (1 - sum));
    }
  }
  if (dis[1] == 1e18) printf("-1\n");
  else printf("%.9lf\n", dis[1]);
  for (int i = 1; i <= n; i++) to[i].clear();
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t; cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
