#ifndef HIDDEN_IN_VS // 折りたたみ用

// 警告の抑制
#define _CRT_SECURE_NO_WARNINGS

// ライブラリの読み込み
#include <bits/stdc++.h>
using namespace std;

// 型名の短縮
using ll = long long; using ull = unsigned long long; // -2^63 ～ 2^63 = 9 * 10^18（int は -2^31 ～ 2^31 = 2 * 10^9）
using pii = pair<int, int>;	using pll = pair<ll, ll>;	using pil = pair<int, ll>;	using pli = pair<ll, int>;
using vi = vector<int>;		using vvi = vector<vi>;		using vvvi = vector<vvi>;	using vvvvi = vector<vvvi>;
using vl = vector<ll>;		using vvl = vector<vl>;		using vvvl = vector<vvl>;	using vvvvl = vector<vvvl>;
using vb = vector<bool>;	using vvb = vector<vb>;		using vvvb = vector<vvb>;
using vc = vector<char>;	using vvc = vector<vc>;		using vvvc = vector<vvc>;
using vd = vector<double>;	using vvd = vector<vd>;		using vvvd = vector<vvd>;
template <class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
using Graph = vvi;

// 定数の定義
const double PI = acos(-1);
const vi DX = { 1, 0, -1, 0 }; // 4 近傍（下，右，上，左）
const vi DY = { 0, 1, 0, -1 };
int INF = 1001001001; ll INFL = 4004004003104004004LL; // (int)INFL = 1010931620;

// 入出力高速化
struct fast_io { fast_io() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(18); } } fastIOtmp;

// 汎用マクロの定義
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)(x).size())
#define lbpos(a, x) (int)distance((a).begin(), std::lower_bound(all(a), x))
#define ubpos(a, x) (int)distance((a).begin(), std::upper_bound(all(a), x))
#define Yes(b) {cout << ((b) ? "Yes\n" : "No\n");}
#define rep(i, n) for(int i = 0, i##_len = int(n); i < i##_len; ++i) // 0 から n-1 まで昇順
#define repi(i, s, t) for(int i = int(s), i##_end = int(t); i <= i##_end; ++i) // s から t まで昇順
#define repir(i, s, t) for(int i = int(s), i##_end = int(t); i >= i##_end; --i) // s から t まで降順
#define repe(v, a) for(const auto& v : (a)) // a の全要素（変更不可能）
#define repea(v, a) for(auto& v : (a)) // a の全要素（変更可能）
#define repb(set, d) for(int set = 0, set##_ub = 1 << int(d); set < set##_ub; ++set) // d ビット全探索（昇順）
#define repis(i, set) for(int i = lsb(set), bset##i = set; i >= 0; bset##i -= 1 << i, i = lsb(bset##i)) // set の全要素（昇順）
#define repp(a) sort(all(a)); for(bool a##_perm = true; a##_perm; a##_perm = next_permutation(all(a))) // a の順列全て（昇順）
#define smod(n, m) ((((n) % (m)) + (m)) % (m)) // 非負mod
#define uniq(a) {sort(all(a)); (a).erase(unique(all(a)), (a).end());} // 重複除去
#define EXIT(a) {cout << (a) << endl; exit(0);} // 強制終了
#define inQ(x, y, u, l, d, r) ((u) <= (x) && (l) <= (y) && (x) < (d) && (y) < (r)) // 半開矩形内判定

// 汎用関数の定義
template <class T> inline ll powi(T n, int k) { ll v = 1; rep(i, k) v *= n; return v; }
template <class T> inline bool chmax(T& M, const T& x) { if (M < x) { M = x; return true; } return false; } // 最大値を更新（更新されたら true を返す）
template <class T> inline bool chmin(T& m, const T& x) { if (m > x) { m = x; return true; } return false; } // 最小値を更新（更新されたら true を返す）
template <class T> inline T get(T set, int i) { return (set >> i) & T(1); }

// 演算子オーバーロード
template <class T, class U> inline istream& operator>>(istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template <class T> inline istream& operator>>(istream& is, vector<T>& v) { repea(x, v) is >> x; return is; }
template <class T> inline vector<T>& operator--(vector<T>& v) { repea(x, v) --x; return v; }
template <class T> inline vector<T>& operator++(vector<T>& v) { repea(x, v) ++x; return v; }

#endif // 折りたたみ用


//#if __has_include(<atcoder/all>)
//#include <atcoder/all>
//using namespace atcoder;
//
//#ifdef _MSC_VER
//#include "localACL.hpp"
//#endif
//
////using mint = modint1000000007;
//using mint = modint998244353;
////using mint = modint; // mint::set_mod(m);
//
//namespace atcoder {
//	inline istream& operator>>(istream& is, mint& x) { ll x_; is >> x_; x = x_; return is; }
//	inline ostream& operator<<(ostream& os, const mint& x) { os << x.val(); return os; }
//}
//using vm = vector<mint>; using vvm = vector<vm>; using vvvm = vector<vvm>; using vvvvm = vector<vvvm>;
//#endif


#ifdef _MSC_VER // 手元環境（Visual Studio）
#include "local.hpp"
#else // 提出用（gcc）
inline int popcount(int n) { return __builtin_popcount(n); }
inline int popcount(ll n) { return __builtin_popcountll(n); }
inline int lsb(int n) { return n != 0 ? __builtin_ctz(n) : -1; }
inline int lsb(ll n) { return n != 0 ? __builtin_ctzll(n) : -1; }
inline int msb(int n) { return n != 0 ? (31 - __builtin_clz(n)) : -1; }
inline int msb(ll n) { return n != 0 ? (63 - __builtin_clzll(n)) : -1; }
#define dump(...)
#define dumpel(v)
#define dump_list(v)
#define dump_mat(v)
#define input_from_file(f)
#define output_to_file(f)
#define Assert(b) { if (!(b)) while (1) cout << "OLE"; }
#endif


//【有限体 F_p 上の計算（32 bit）】
template <ll MOD> struct Static_modint {
	// verify : https://www.codechef.com/problems/MUSICAL

	ll v;

	// コンストラクタ
	Static_modint() noexcept : v(0) {};
	Static_modint(const Static_modint& a) = default;
	Static_modint(int a) noexcept : v(a% MOD) { if (v < 0) v += MOD; };
	Static_modint(ll a) noexcept : v(a% MOD) { if (v < 0) v += MOD; };

	// 代入
	Static_modint& operator=(const Static_modint& a) = default;
	Static_modint& operator=(int a) { v = a % MOD; if (v < 0) v += MOD; return *this; }
	Static_modint& operator=(ll a) { v = a % MOD; if (v < 0) v += MOD; return *this; }

	// 入出力
	friend istream& operator>> (istream& is, Static_modint& x) {
		is >> x.v; x.v %= MOD; if (x.v < 0) x.v += MOD; return is;
	}
	friend ostream& operator<< (ostream& os, const Static_modint& x) { os << x.v; return os; }

	// 比較（参考 : https://twitter.com/KakurenboUni/status/1717463221190414472）
	friend bool operator==(const Static_modint& a, const Static_modint& b) { return a.v == b.v; }
	friend bool operator!=(const Static_modint& a, const Static_modint& b) { return a.v != b.v; }

	// 単項演算
	Static_modint operator-() const { Static_modint a; if (v > 0) a.v = MOD - v; return a; }
	Static_modint& operator++() { v++; if (v == MOD) v = 0; return *this; }
	Static_modint operator++(int) { Static_modint tmp = *this; ++(*this); return tmp; }
	Static_modint& operator--() { v--; if (v == -1) v = MOD - 1; return *this; }
	Static_modint operator--(int) { Static_modint tmp = *this; --(*this); return tmp; }

	// 二項演算
	Static_modint& operator+=(const Static_modint& b) { v += b.v; if (v >= MOD) v -= MOD; return *this; }
	Static_modint& operator-=(const Static_modint& b) { v -= b.v; if (v < 0) v += MOD; return *this; }
	Static_modint& operator*=(const Static_modint& b) { v = (v * b.v) % MOD; return *this; }
	Static_modint& operator/=(const Static_modint& b) { *this *= b.inv(); return *this; }
	friend Static_modint operator+(Static_modint a, const Static_modint& b) { a += b; return a; }
	friend Static_modint operator-(Static_modint a, const Static_modint& b) { a -= b; return a; }
	friend Static_modint operator*(Static_modint a, const Static_modint& b) { a *= b; return a; }
	friend Static_modint operator/(Static_modint a, const Static_modint& b) { a /= b; return a; }

	// 累乗（0^0 := 1）
	Static_modint pow(ll d) const {
		Static_modint res(1), pow2 = *this;
		while (d > 0) {
			if (d & 1) res *= pow2;
			pow2 *= pow2;
			d >>= 1;
		}
		return res;
	}

	// 逆元（0^(-1) は未定義）
	Static_modint inv() const { Assert(v != 0); return pow(MOD - 2); }

	// 法の確認
	static int mod() { return int(MOD); }

	// 値の確認
	int val() const { return int(v); }
};
//using mint = Static_modint<1000000007>;
using mint = Static_modint<998244353>;
using vm = vector<mint>; using vvm = vector<vm>; using vvvm = vector<vvm>;


//【階乗など（法が大きな素数）】
/*
* Factorial_mint(int N) : O(n)
*	N まで計算可能として初期化する．
*
* mint fact(int n) : O(1)
*	n! を返す．
*
* mint fact_inv(int n) : O(1)
*	1/n! を返す（n が負なら 0 を返す）
*
* mint inv(int n) : O(1)
*	1/n を返す．
*
* mint perm(int n, int r) : O(1)
*	順列の数 nPr を返す．
*
* mint bin(int n, int r) : O(1)
*	二項係数 nCr を返す．
*
* mint mul(vi rs) : O(|rs|)
*	多項係数 nC[rs] を返す．（n = Σrs）
*
* mint hom(int n, int r) : O(1)
*	重複組合せの数 nHr = n+r-1Cr を返す（0H0 = 1 とする）
*/
class Factorial_mint {
	int n_max;

	// 階乗と階乗の逆数の値を保持するテーブル
	vm fac, fac_inv;

public:
	// n! までの階乗とその逆数を前計算しておく．O(n)
	Factorial_mint(int n) : n_max(n), fac(n + 1), fac_inv(n + 1) {
		// verify : https://atcoder.jp/contests/dwacon6th-prelims/tasks/dwacon6th_prelims_b

		fac[0] = 1;
		repi(i, 1, n) fac[i] = fac[i - 1] * i;

		fac_inv[n] = fac[n].inv();
		repir(i, n - 1, 0) fac_inv[i] = fac_inv[i + 1] * (i + 1);
	}
	Factorial_mint() : n_max(0) {} // ダミー

	// n! を返す．
	mint fact(int n) const {
		// verify : https://atcoder.jp/contests/dwacon6th-prelims/tasks/dwacon6th_prelims_b

		Assert(0 <= n && n <= n_max);
		return fac[n];
	}

	// 1/n! を返す（n が負なら 0 を返す）
	mint fact_inv(int n) const {
		// verify : https://atcoder.jp/contests/abc289/tasks/abc289_h

		Assert(n <= n_max);
		if (n < 0) return 0;
		return fac_inv[n];
	}

	// 1/n を返す．
	mint inv(int n) const {
		// verify : https://atcoder.jp/contests/exawizards2019/tasks/exawizards2019_d

		Assert(0 < n && n <= n_max);
		return fac[n - 1] * fac_inv[n];
	}

	// 順列の数 nPr を返す．
	mint perm(int n, int r) const {
		// verify : https://atcoder.jp/contests/abc172/tasks/abc172_e

		Assert(n <= n_max);

		if (r < 0 || n - r < 0) return 0;
		return fac[n] * fac_inv[n - r];
	}

	// 二項係数 nCr を返す．
	mint bin(int n, int r) const {
		// verify : https://atcoder.jp/contests/abc034/tasks/abc034_c

		Assert(n <= n_max);
		if (r < 0 || n - r < 0) return 0;
		return fac[n] * fac_inv[r] * fac_inv[n - r];
	}

	// 多項係数 nC[rs] を返す．
	mint mul(const vi& rs) const {
		// verify : https://yukicoder.me/problems/no/2141

		if (*min_element(all(rs)) < 0) return 0;
		int n = accumulate(all(rs), 0);
		Assert(n <= n_max);

		mint res = fac[n];
		repe(r, rs) res *= fac_inv[r];

		return res;
	}

	// 重複組合せの数 nHr = n+r-1Cr を返す（0H0 = 1 とする）
	mint hom(int n, int r) {
		// verify : https://mojacoder.app/users/riantkb/problems/toj_ex_2

		if (n == 0) return (int)(r == 0);
		Assert(n + r - 1 <= n_max);
		if (r < 0 || n - 1 < 0) return 0;
		return fac[n + r - 1] * fac_inv[r] * fac_inv[n - 1];
	}
};
Factorial_mint fm((int)1e6 + 10);


//【累乗（mint 利用）】
/*
* Pow_mint(mint B, int n) : O(n)
*	底を B とし，B^(-n) から B^n まで計算可能として初期化する．
*	制約 : B は mint の法と互いに素
*
* mint [](int i) : O(1)
*	B^i を返す．
*/
class Pow_mint {
	int n;
	vm powB, powB_inv;

public:
	Pow_mint(mint B, int n) : n(n) {
		// verify : https://atcoder.jp/contests/arc116/tasks/arc116_b

		// B の累乗を計算する．
		powB.resize(n + 1);
		powB[0] = 1;
		rep(i, n) powB[i + 1] = powB[i] * B;

		// B の逆元の累乗を計算する．
		mint invB = B.inv();
		powB_inv.resize(n + 1);
		powB_inv[0] = 1;
		rep(i, n) powB_inv[i + 1] = powB_inv[i] * invB;
	};
	Pow_mint() : n(0) {}

	// B^i を返す．
	mint const& operator[](int i) const {
		// verify : https://atcoder.jp/contests/arc116/tasks/arc116_b

		Assert(abs(i) <= n);

		return i >= 0 ? powB[i] : powB_inv[-i];
	}

#ifdef _MSC_VER
	friend ostream& operator<<(ostream& os, const Pow_mint& pw) {
		os << pw.powB << endl;
		os << pw.powB_inv << endl;
		return os;
	}
#endif
};


void Main() {
	int n, m;
	cin >> n >> m;

	if (m == 1) {
		cout << 0 << endl;
		return;
	}

	Pow_mint pow_m(m, n + 10);
	Pow_mint pow_x(m - 1, n + 10);

	mint res = 0; mint acc = 1;
	repi(l, 1, n / 2) {
		res += (pow_m[2 * l] - m * acc) * (n - 2 * l + 1) * pow_m[n - 2 * l];

		acc *= pow_m[2];
		acc += fm.bin(2 * l, l) * pow_x[l];
		acc -= fm.bin(2 * l, l + 1) * pow_x[l + 1];

		//acc *= m;
		//acc += fm.bin(2 * l, l) * pow_x[l];
		//acc *= m;
		//acc -= fm.bin(2 * l + 1, l + 1) * pow_x[l + 1];
	}

	cout << res << endl;
}

int main() {
//	input_from_file("input.txt");
//	output_to_file("output.txt");

	int t;
	cin >> t; // マルチテストケースの場合
//	t = 1;    // シングルテストケースの場合

	while (t--) {
		dump("------------------------------");
		Main();
	}
}
