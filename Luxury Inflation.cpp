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
#define YES(b) {cout << ((b) ? "YES\n" : "NO\n");}
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
#define inQ(x, y, u, l, d, r) ((u) <= (x) && (l) <= (y) && (x) < (d) && (y) < (r)) // 矩形内判定

// 汎用関数の定義
template <class T> inline ll pow(T n, int k) { ll v = 1; rep(i, k) v *= n; return v; }
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


string solve(int n, vi c) {
	sort(all(c));

	int c_sum = accumulate(all(c), 0);

	dump(INF = 99);
	vvi dp(n + 1, vi(c_sum + 1, INF));
	dp[0][0] = 0;

	rep(i, n) {
		repi(j, 0, c_sum) {
			if (dp[i][j] >= INF) continue;

			chmin(dp[i + 1][j], dp[i][j]);
			if (j + c[i] <= c_sum) {
				chmin(dp[i + 1][j + c[i]], dp[i][j] + 1);
			}
		}
	}
	dumpel(dp);

	string res;

	repi(v, 1, c_sum - 1) {
		dump("v:", v);
		if (dp[n][v] >= INF) {
			res += '0';
			continue;
		}

		int rem = v;
		repir(i, n - 1, 0) {
			dump("i:", i, "/", rem);

			// c[i] を使わない場合
			ll cnt = (n - 1) - i + dp[i][rem];
			if (c[i] * cnt < v) {
				res += '1';
				break;
			}

			// c[i] を使わなくても良い場合
			if (rem - c[i] >= 0 && dp[i][rem - c[i]] < INF) {
				rem -= c[i];
			}
			else {
				res += '0';
				break;
			}
		}
	}
	res += '1';

	return res;
}


string naive(int n, vi c) {
	int c_sum = accumulate(all(c), 0);

	string res(c_sum, '0');

	vi p(n);
	iota(all(p), 0);

	repp(p) {
		ll sum = c[p[0]], cnt = 1;
		repi(i, 1, n - 1) {
			if (c[p[i]] * cnt >= sum) {
				sum += c[p[i]];
				cnt++;
			}
		}
		res[sum - 1] = '1';
		if (sum == 16) dump(p);
	}

	return res;
}


void bug_find() {
#ifdef _MSC_VER
	// 合わない入力例を見つける．

	mt19937_64 mt;
	mt.seed((int)time(NULL));
	uniform_int_distribution<ll> rnd(0LL, 1LL << 60);

	mute_dump = true;

	rep(hoge, 10000) {
		int n = 7;
		vi c(n);
		rep(i, n) c[i] = rnd(mt) % 20 + 1;
		sort(all(c));

		auto res_naive = naive(n, c);
		auto res_solve = solve(n, c);

		if (res_naive != res_solve) {
			cout << "----------error!----------" << endl;
			cout << "input:" << endl;
			cout << n << endl;
			cout << c << endl;
			cout << "results:" << endl;
			cout << res_naive << endl;
			cout << res_solve << endl;
			cout << "--------------------------" << endl;
		}
	}

	mute_dump = false;
	exit(0);
#endif
}
/*
----------error!----------
input:
6
1 2 4 4 5 8
results:
000000010001111111101111
000000010001111011101111 16
--------------------------
*/


void Main() {
	int n;
	cin >> n;

	vi c(n);
	cin >> c;

	dump(naive(n, c)); dump("-----");

	cout << solve(n, c) << endl;
}

int main() {
	input_from_file("input.txt");
//	output_to_file("output.txt");

	bug_find();

	int t;
	cin >> t; // マルチテストケースの場合
//	t = 1;    // シングルテストケースの場合

	while (t--) {
		dump("------------------------------");
		Main();
	}
}
