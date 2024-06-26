#include <bits/stdc++.h>
 
using namespace std;
 
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &pa) { is >> pa.first >> pa.second; return is; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << "(" << pa.first << "," << pa.second << ")"; return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec) { os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) { os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template <typename T> void resize_array(vector<T> &vec, int len) { vec.resize(len); }
template <typename T, typename... Args> void resize_array(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) resize_array(v, args...); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
 
#define rep(i, a, n) for (int i = a; i < (n); i++)
#define per(i, a, n) for (int i = (n)-1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef double db;
#if DEBUG
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
#else
#define dbg(x)
#endif

class Solution {
    struct Weight {
      ll w;
      int idx;
      bool operator<(const Weight& weight) const {
        if (w == weight.w) return idx > weight.idx;
        return w < weight.w;
      }
       friend ostream &operator<<(ostream &os, const Weight &w) { return os << "(" << w.w << ", " << w.idx << ")"; }
    };
public:
    void Solve() {
        int t; cin>>t;
        while(t--) {
            int n;
            ll c,s,m;
            cin>>n>>c>>s>>m;
            vector<ll> w(n); cin>>w;
            // prefix_set contains prefix_swap_in_set; 
            // min(prefix_set) > max(prefix_swap_out_set)
            set<Weight> prefix_set, prefix_swap_in_set, prefix_swap_out_set;
            // prefix_set + prefix_swap_out_set + suffix_set = whole set
            set<Weight> suffix_set;
            rep(i,0,n) suffix_set.insert({w[i],i});
            ll sum_w = 0;
            ll cost = c * n;

            auto get_max = [&] (const set<Weight>& st) {
              auto it = st.end(); --it;
              return *it;
            };
            auto get_min = [&] (const set<Weight>& st) {
              auto it = st.begin();
              return *it;
            };

            rep(i,0,n) {
              // add w[i] to prefix_set
              if (prefix_set.count({w[i],i})>0) { // w[i] swapped in before
                prefix_swap_in_set.erase({w[i],i});
                auto pmax = get_max(prefix_swap_out_set);
                sum_w += pmax.w;
                prefix_swap_out_set.erase(pmax);
                prefix_set.insert(pmax);
                // suffix_set.erase(*pmax);
              } else {
                if (sz(prefix_swap_out_set)>0 && get_max(prefix_swap_out_set).w > w[i]) {
                  auto pmax = get_max(prefix_swap_out_set);
                  sum_w += pmax.w;
                  prefix_set.insert(pmax);
                  prefix_swap_out_set.erase(pmax);
                  prefix_swap_out_set.insert({w[i],i});
                } else {
                  prefix_set.insert({w[i],i});
                  sum_w += w[i];
                }
                suffix_set.erase({w[i],i});
              }

              if (sum_w <=m) { // if sum_w > m at i, then for all i,i+1,i+2,...,n, sum_w > m, don't need to swap in anymore.
                if (sz(suffix_set)>0) {
                  auto suffix_max = get_max(suffix_set);
                  auto prefix_min = prefix_set.begin();
                  if (suffix_max.w > prefix_min->w) { // if suffix has value greater than prefix's smallest value, swap in, prefer smaller index
                    prefix_swap_in_set.insert(suffix_max);
                    sum_w += suffix_max.w;
                    prefix_swap_out_set.insert(*prefix_min);
                    sum_w -= prefix_min->w;
                    prefix_set.erase(prefix_min);
                    prefix_set.insert(suffix_max);
                    suffix_set.erase(suffix_max);
                  }
                }
              }

            // when sum_w > m, sz(prefix_swap_in_set) will only decrease as i increase.
              while (sz(prefix_swap_in_set) > 0 && sum_w - get_min(prefix_swap_in_set).w + get_max(prefix_swap_out_set).w > m) {
                auto pmin = get_min(prefix_swap_in_set);
                auto pmax = get_max(prefix_swap_out_set);
                sum_w = sum_w - pmin.w + pmax.w;
                prefix_set.erase(pmin);
                prefix_set.insert(pmax);
                prefix_swap_in_set.erase(pmin);
                prefix_swap_out_set.erase(pmax);
              }

              if (sum_w > m) {
                cost = min(cost, sz(prefix_swap_in_set) * s + (i)*c);
              }
            }
            cout << cost <<"\n";
        }
        cout.flush();
    }
private:
};
 
// #define USACO 1
void set_io(const string &name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#if FILE_IO || USACO
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#endif
}

int main() {
#if USACO
    set_io("time");
#else
    set_io("tmp");
#endif
    Solution().Solve();

    return 0;
}
