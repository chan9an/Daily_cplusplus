//https://www.codechef.com/INOIPRAC/problems/INOI1501?tab=statement
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
const int N = (int) 1e6 + 7;
const ll INF = (ll) 1e18;
int a[N], b[N];
ll pre[N], suf[N], mx[N];
int n;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  // freopen("input", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + b[i];
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + b[i];
  }
  ll ret = -INF;
  for (int i = 1; i <= n; i++) {
    ret = max(ret, a[i]);
  }
  ll mn = pre[1] - a[1];
  for (int i = 2; i <= n; i++) {
    ll sum = pre[i - 1] + a[i] - mn;
    ret = max(ret, sum);
    mn = min(mn, pre[i] - a[i]);
  }
  mx[0] = -INF;
  for (int i = 1; i <= n; i++) {
    mx[i] = max(mx[i - 1], pre[i - 1] + a[i]);
  }
  for (int i = 2; i <= n; i++) {
    ll sum = a[i] + suf[i + 1] + mx[i - 1];
    ret = max(ret, sum);
  }
  cout << ret << "\n";
  return 0;
}
