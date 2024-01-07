#include <bits/stdc++.h>

using namespace std;

struct Fast {
  Fast() {
    std::cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(10);
  }
} fast;

#define all(a) (a).begin(), (a).end()
#define contains(a, x) ((a).find(x) != (a).end())
#define rep(i, a, b) for (int i = (a); i < (int)(b); i++)
#define rrep(i, a, b) for (int i = (int)(b)-1; i >= (a); i--)
#define writejoin(s, a) rep(_i, 0, (a).size()) cout << (a)[_i] << (_i + 1 < (int)(a).size() ? s : "\n");
#define YN(b) cout << ((b) ? "YES" : "NO") << "\n";
#define Yn(b) cout << ((b) ? "Yes" : "No") << "\n";
#define yn(b) cout << ((b) ? "yes" : "no") << "\n";

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

template <int m = 998244353>
struct simple_modint {
  using mint = simple_modint;

 public:
  static constexpr int mod() { return m; }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }

  simple_modint() : _v(0) {}
  simple_modint(int v) {
    long long x = (long long)(v % (long long)(umod()));
    _v = (unsigned int)(x < 0 ? x + umod() : x);
  }
  simple_modint(long long v) {
    long long x = v % (long long)(umod());
    _v = (unsigned int)(x < 0 ? x + umod() : x);
  }
  simple_modint(unsigned int v) : _v(v % umod()) {}
  unsigned int val() const { return _v; }
  mint& operator++() {
    _v++;
    if (_v == umod()) _v = 0;
    return *this;
  }
  mint& operator--() {
    if (_v == 0) _v = umod();
    _v--;
    return *this;
  }
  mint operator++(int) {
    mint result = *this;
    ++*this;
    return result;
  }
  mint operator--(int) {
    mint result = *this;
    --*this;
    return result;
  }
  mint& operator+=(const mint& rhs) {
    _v += rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    _v -= rhs._v;
    if (_v >= umod()) _v += umod();
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    unsigned long long z = _v;
    z *= rhs._v;
    _v = (unsigned int)(z % umod());
    return *this;
  }
  mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

  mint operator+() const { return *this; }
  mint operator-() const { return mint() - *this; }

  mint pow(long long n) const {
    assert(0 <= n);
    mint x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  mint inv() {
    auto eg = inv_gcd(_v, m);
    assert(eg.first == 1);
    return eg.second;
  }
  constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a %= b;
    if (a == 0) return {b, 0};
    long long s = b, t = a, m0 = 0, m1 = 1;
    while (t) {
      long long u = s / t;
      s -= t * u;
      m0 -= m1 * u;
      auto tmp = s;
      s = t;
      t = tmp;
      tmp = m0;
      m0 = m1;
      m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
  }
  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
  friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
  friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
  friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }

 private:
  unsigned int _v;
  static constexpr unsigned int umod() { return m; }
};

using mint = simple_modint<998244353>;
using vm = vector<mint>;

void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n), a1(n), a2(n);
  rep(i, 0, n) cin >> a1[i];
  rep(i, 0, n) cin >> a2[i];
  rep(i, 0, n) a[i] = min(k, (a1[i] - 1) / a2[i] + 1);

  sort(all(a));
  vm f(k + 1);
  int x = n - 1;
  mint v = 1;
  rrep(i, 0, k + 1) {
    f[i] = -v;
    for (; x >= 0 && a[x] >= i; x--) v += v;
    f[i] += v;
  }
  mint div = (v - 1).inv();

  vm ans(k + 1, 0);
  rep(i, 1, k + 1) {
    for (int j = 0; i * j <= k; j++) ans[i * j] += f[i];
  }
  rep(i, 0, k) ans[i + 1] += ans[i];
  rep(i, 0, k) {
    ans[i] *= div;
    cout << ans[i].val() << " \n"[i + 1 == k];
  }
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
