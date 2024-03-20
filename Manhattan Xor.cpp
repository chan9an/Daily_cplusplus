
#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i, s, n) for (lli i = s; i < n; i++)
#define INF (1LL << 62)
#define mp(a, b) make_pair(a, b)
#define SORT(V) sort(V.begin(), V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) #VariableName
#define LOG1(x)                                                                \
  if (DEBUG)                                                                   \
    cout << TO_STRING(x) << "=" << x << " " << endl;
#define LOG2(x, y)                                                             \
  if (DEBUG)                                                                   \
    cout << TO_STRING(x) << "=" << x << " " << TO_STRING(y) << "=" << y << endl;
#define LOG3(x, y, z)                                                          \
  if (DEBUG)                                                                   \
    cout << TO_STRING(x) << "=" << x << " " << TO_STRING(y) << "=" << y << " " \
         << TO_STRING(z) << "=" << z << endl;
#define LOG4(w, x, y, z)                                                       \
  if (DEBUG)                                                                   \
    cout << TO_STRING(w) << "=" << w << " " << TO_STRING(x) << "=" << x << " " \
         << TO_STRING(y) << "=" << y << " " << TO_STRING(z) << "=" << z        \
         << endl;
#define LOG5(w, x, y, z, a)                                                    \
  if (DEBUG)                                                                   \
    cout << TO_STRING(w) << "=" << w << " " << TO_STRING(x) << "=" << x << " " \
         << TO_STRING(y) << "=" << y << " " << TO_STRING(z) << "=" << z << " " \
         << TO_STRING(a) << "=" << a << endl;
#define LOG6(w, x, y, z, a, b)                                                 \
  if (DEBUG)                                                                   \
    cout << TO_STRING(w) << "=" << w << " " << TO_STRING(x) << "=" << x << " " \
         << TO_STRING(y) << "=" << y << " " << TO_STRING(z) << "=" << z << " " \
         << TO_STRING(a) << "=" << a << " " << TO_STRING(b) << "=" << b        \
         << endl;

#define overload6(a, b, c, d, e, f, g, ...) g
#define LOG(...)                                                               \
  overload6(__VA_ARGS__, LOG6, LOG5, LOG4, LOG3, LOG2, LOG1)(__VA_ARGS__)

template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

mt19937 engine;
std::chrono::system_clock::time_point start, endTime;

#define DEBUG 0

lli xorSumXor(lli n) {
  if (n < 0) {
    return 0;
  }
  lli div = n % 16;
  if (div == 0 || div == 1 || div == 8 || div == 9) {
    return n;
  }
  if (div == 2 || div == 3 || div == 10 || div == 11) {
    return 2;
  }
  if (div == 4 || div == 5 || div == 12 || div == 13) {
    return n + 2;
  }
  if (div == 6 || div == 7 || div == 14 || div == 15) {
    return 0;
  }
}

void solve() {

  lli N, M, X, Y;
  cin >> N >> M >> X >> Y;

  lli nowAns = 0;
  {

    lli nowX = N - X;
    lli nowY = Y;
    LOG(nowX, nowY);
    nowAns ^=
        xorSumXor(nowX + nowY - 1) ^ xorSumXor(nowY - 1) ^ xorSumXor(nowX - 1);
  }
  {

    lli nowX = N - X + 1;
    lli nowY = M - Y;
    LOG(nowX, nowY);
    nowAns ^=
        xorSumXor(nowX + nowY - 1) ^ xorSumXor(nowY - 1) ^ xorSumXor(nowX - 1);
  }
  {

    lli nowX = X - 1;
    lli nowY = M - Y + 1;
    LOG(nowX, nowY);
    nowAns ^=
        xorSumXor(nowX + nowY - 1) ^ xorSumXor(nowY - 1) ^ xorSumXor(nowX - 1);
  }
  {
    
    lli nowX = X;
    lli nowY = Y - 1;
    LOG(nowX, nowY);
    nowAns ^=
        xorSumXor(nowX + nowY - 1) ^ xorSumXor(nowY - 1) ^ xorSumXor(nowX - 1);
  }
  cout << nowAns << endl;
}
int main() {

  lli N = 1;
  cin >> N;
  while (N--)
    solve();

  return 0;
}
