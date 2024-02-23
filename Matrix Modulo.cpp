#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ll long long
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define nsync                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

// constants
const int M = (int)(1e9 + 7);
const int s = 1e5 + 1;
const int INF = 3e18L + 5;
const int INF64 = 1e18;
const int NINF = 1e18 * (-1);

int factdp[520];
int factorial(int n) {
  if (n <= 1)
    return 1;
  if (factdp[n] != -1)
    return factdp[n];
  return factdp[n] = (n * factorial(n - 1)) % M;
}
int pow2(int n) {
  int ans = 1;
  int x = 2;
  while (n) {
    if (n & 1) {
      ans = (ans * x) % M;
    }
    x = (x * x) % M;
    n >>= 1;
  }
  return ans;
}

bool checkDiagonal(int element, int n) {
  int lb = ((n * (n - 1)) / 2) + 1;
  int ub = ((n * (n + 1)) / 2);
  if (element >= lb && element <= ub)
    return true;
  return false;
}

const int N = 510, MM = N * N;
int a[N][N];
ll fac[MM], poww[MM];

int32_t main() {
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // sieve();
  fac[0] = poww[0] = 1;
  for (int i = 1; i <= 250000; i++)
    fac[i] = (fac[i - 1] * i) % M;
  for (int i = 1; i <= 250000; i++)
    poww[i] = (poww[i - 1] * 2) % M;
  int t;
  cin >> t;
  vector<pair<int, int>> marked(510 * 510);
  while (t--) {
    int n;
    cin >> n;
    int Kmax = (n * (n + 1)) / 2;
    int lb = n * (n - 1) / 2;
    int rem = 0;
    int c = 0;
    int ans = 1;
    vector<vector<int>> matrix(n + 10, vector<int>(n + 10, 0));
    REP(i, n) REP(j, n) { cin >> matrix[i][j]; };
    REP(i, n * n + 1) marked[i] = {-1, -1};

    bool flag = true;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (matrix[i][j] == 0 && matrix[j][i] == 0)
          c++;
        else if (matrix[i][j] == 0 || matrix[j][i] == 0) {
          int x = max(matrix[i][j], matrix[j][i]);
          if (x == matrix[i][j])
            marked[x] = {i, j};
          else
            marked[x] = {j, i};
        } else if (abs(matrix[i][j] - matrix[j][i]) != Kmax)
          flag = false; // check divisibility

        // check within bounds
        if (matrix[j][i] > lb && matrix[j][i] <= Kmax)
          flag = false;
        if (matrix[i][j] > lb && matrix[i][j] <= Kmax)
          flag = false;
      }
    }
    // check diagonals
    for (int i = 0; i < n; i++) {
      if (!matrix[i][i])
        rem++;
      else if (matrix[i][i] > Kmax || matrix[i][i] <= lb)
        flag = false;
    }

    // validate marked fields
    for (int i = 1; i <= lb; i++) {
      if (marked[i].first == -1 || marked[i + Kmax].first == -1)
        continue; // not marked - pair exists

      int x1 = marked[i].first, y1 = marked[i].second,
          x2 = marked[i + Kmax].first, y2 = marked[i + Kmax].second;
      if (x1 != y2 || x2 != y1)
        flag = false;
    }
    if (!flag) {
      cout << 0 << endl;
    } else {
      ans = (ans * poww[c]) % M;
      ans = (ans * fac[c]) % M;
      ans = (ans * fac[rem]) % M;
      cout << ans << endl;
    }
  }
  return 0;
}
