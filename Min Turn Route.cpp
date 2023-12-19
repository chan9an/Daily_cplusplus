#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define all(a) (a).begin(), (a).end()
#define rev(a) (a).rbegin(), (a).rend()
#define ordered_set                                                            \
  tree<int, null_type, less<int>, rb_tree_tag,                                 \
       tree_order_statistics_node_update>
int recur_depth = 0;
#ifdef DEBUG
#define dbg(x)                                                                 \
  {                                                                            \
    ++recur_depth;                                                             \
    auto x_ = x;                                                               \
    --recur_depth;                                                             \
    cerr << string(recur_depth, '\t') << "\e[91m" << __func__ << ":"           \
         << __LINE__ << "\t" << #x << " = " << x_ << "\e[39m" << endl;         \
  }
#else
#define dbg(x)
#endif

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> ii;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> llll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vii;
typedef vector<vii> vvii;

typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pair<ll, ll>> vll;
typedef vector<vll> vvll;

typedef vector<bool> vb;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v)
    os << sep << x, sep = ", ";
  return os << '}';
}

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<vector<char>>> grid(m, vector<vector<char>>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      char t, r, b, l;
      cin >> t >> r >> b >> l;
      grid[i][j] = {t, r, b, l};
    }
  }

  auto rotate90 = [](vector<char> &c) -> vector<char> {
    return {c[3], c[0], c[1], c[2]};
  };

  auto weight = [&](int a, int b, int c, int d) -> int {
    vector<char> tmp = grid[a][b];
    int cnt = 0;
    if (a == c - 1 && b == d) {
      while (tmp[2] != grid[c][d][0]) {
	tmp = rotate90(tmp);
	cnt++;
      }
      return cnt;
    } else if (a == c + 1 && b == d) {
      while (tmp[0] != grid[c][d][2]) {
	tmp = rotate90(tmp);
	cnt++;
      }
      return cnt;
    } else if (a == c && b == d - 1) {
      while (tmp[1] != grid[c][d][3]) {
	tmp = rotate90(tmp);
	cnt++;
      }
      return cnt;
    } else if (a == c && b == d + 1) {
      while (tmp[3] != grid[c][d][1]) {
	tmp = rotate90(tmp);
	cnt++;
      }
      return cnt;
    } else return 0;
  };

  auto valid = [&](int i, int j) -> bool {
    return (0 <= i && i < m && 0 <= j && j < n);
  };


  vector<vb> seen(m, vb(n, false));
  
  priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
  pq.push({0, {0, 0}});
  while (!pq.empty()) {
    pair<int, ii> curr = pq.top();
    pq.pop();

    int r = curr.second.first, c = curr.second.second;
    int cost = curr.first;

    if (seen[r][c]) continue;
    seen[r][c] = true;

    if (r == m - 1 && c == n - 1) {
      cout << cost << "\n";
      return;
    }

    if (valid(r - 1, c) && (!seen[r - 1][c])) {
      pq.push({cost + weight(r, c, r - 1, c), {r - 1, c}});
    }

    if (valid(r + 1, c) && (!seen[r + 1][c])) {
      pq.push({cost + weight(r, c, r + 1, c), {r + 1, c}});
    }

    if (valid(r, c - 1) && (!seen[r][c - 1])) {
      pq.push({cost + weight(r, c, r, c - 1), {r, c - 1}});
    }

    if (valid(r, c + 1) && (!seen[r][c + 1])) {
      pq.push({cost + weight(r, c, r, c + 1), {r, c + 1}});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int test_cases = 1;
  /* cin >> test_cases; */

  while (test_cases--)
    solve();
  return 0;
}
