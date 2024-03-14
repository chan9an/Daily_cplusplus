    /*-------------------------
    ???????????????
    ????????????????
    ????????????????
    ????????????????
    ????????????????
    ????????????????
    ????????????????
    ????????????????
    ????????????????
    ????????????????
    ????????????????
    ????????????????
    ????????????????
    ??????????????????
    ????????????????????
    ?????????????????????
    ?????????????????????
    ????????????????????
    ????????????????????
    ---------------------------*/

    /**************************** --- Header --- ****************************/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;
using namespace __gnu_pbds;

/**************************** --- Ordered Set --- ****************************/
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// less is a comparator
// less -> ascending ordered set
// less_equal -> ascending multi set
// greater -> descending ordered set
// greater_equal -> descending multi set
#define ind_in_set(x) order_of_key(x) //gives index of x, if not present then gives the index at which it would come
#define it_in_set(x) find_by_order(x) //gives the iterator to the element at the index x, so use with * to get the element at index x

/**************************** --- Print --- ****************************/
#define int long long
#define endl '\n'
#define yes {cout << "Yes" << endl; return;}
#define no {cout << "No" << endl; return;}
#define cout(x) {cout << x << endl; return;}
#define elif else if

/**************************** --- Type --- ****************************/
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using str = string;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vpl = vector<pl>;
using vs = vector<str>;
using sl = set<ll>;
using ml = map<ll, ll>;

/**************************** --- Pair --- ****************************/
#define fi first
#define se second

/**************************** --- Vector --- ****************************/
#define pb emplace_back
#define sz(v) (ll)(v).size()
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define asc(v) sort(all(v))
#define desc(v) sort(allr(v))
#define rev(v) reverse(all(v))
#define maxe(v) *max_element(all(v))
#define mine(v) *min_element(all(v))
#define sum(v)  accumulate(all(v), 0ll)
#define ass(v,x)  iota(all(v), x)
#define pre(a,pf)  partial_sum(all(a), (pf).begin()+1) // pf is of n+1 size
#define unq(v)  (v).resize(unique(all(v)) - (v).begin()); // sort and then pass v, it will remove all duplicate and reduce the size of v also

/**************************** --- Set & Map --- ****************************/
#define in emplace
#define er erase
#define lb lower_bound
#define ub upper_bound

/**************************** --- Priority Queue --- ****************************/
template<class T> using mxq = priority_queue<T>;
template<class T> using mnq = priority_queue<T, vector<T>, greater<T>>;

/**************************** --- Disjoint Set --- ****************************/
class DisjointSet {
public:
  vector<int> rank, par;
  DisjointSet(int n) {
    rank.resize(n + 1, 0);
    par.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      par[i] = i;
    }
  }

  int findPar(int node) {
    if (node == par[node])
      return node;
    return par[node] = findPar(par[node]);
  }

  void merge(int u, int v) {
    int ulp_u = findPar(u);
    int ulp_v = findPar(v);
    if (ulp_u == ulp_v) return;
    if (rank[ulp_u] < rank[ulp_v]) {
      par[ulp_u] = ulp_v;
    }
    else if (rank[ulp_v] < rank[ulp_u]) {
      par[ulp_v] = ulp_u;
    }
    else {
      par[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
};

/**************************** --- Binary Trie --- ****************************/
/*
struct BTrieNode {
  BTrieNode *child[2];

  bool isPresent(int bit) {
    return child[bit] != NULL;
  }

  void put(int bit) {
    child[bit] = new BTrieNode();
  }

  BTrieNode *get(int bit) {
    return child[bit];
  }
};

class BTrie {
private:
  BTrieNode *root;

public:
  BTrie(int x) {
    root = new BTrieNode();
  }

  void insert(int num) {
    BTrieNode *cur = root;

    for (int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1;

      if (!cur->isPresent(bit)) cur->put(bit);
      cur = cur->get(bit);
    }
  }

  int getMax(int x) {
    int ans = 0;
    BTrieNode *cur = root;

    for (int i = 31; i >= 0; i--) {
      int bit = (x >> i) & 1;

      if (cur->isPresent(!bit)) {
        ans = ans | (1 << i);
        cur = cur->get(!bit);
      }

      else cur = cur->get(bit);
    }

    return ans;
  }
};
*/

/**************************** --- Loop --- ****************************/
#define f(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, b, a) for (ll i = b; i >= a; i--)
#define fa(it, v) for (auto &it : v)
#define fp(x, y, v) for (auto &[x,y] : v)
#define fit(it, v) for (auto it = (v).begin(); it != (v).end(); it++)

/**************************** --- Maths --- ****************************/
// const ll mod = 1000000007;
const ll mod = 998244353;
const ll INF = 9e18;

#define gcd(a, b) __gcd(a, b)

/**************************** --- Mod --- ****************************/
template <const int MOD>
struct modint {
  int value;
  modint() = default;
  modint(int value_) : value(value_) {}
  inline modint<MOD> operator + (modint<MOD> other) const { int c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
  inline modint<MOD> operator - (modint<MOD> other) const { int c = this->value - other.value; return modint<MOD>(c < 0 ? c + MOD : c); }
  inline modint<MOD> operator * (modint<MOD> other) const { int c = (ll)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
  inline modint<MOD> &operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
  inline modint<MOD> &operator -= (modint<MOD> other) { this->value -= other.value; if (this->value < 0) this->value += MOD; return *this; }
  inline modint<MOD> &operator *= (modint<MOD> other) { this->value = (ll)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
  inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
  modint<MOD> pow(ull k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
  modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
  inline modint<MOD> operator /  (modint<MOD> other) const { return *this * other.inv(); }
  inline modint<MOD> operator /= (modint<MOD> other) { return *this *= other.inv(); }
  inline bool operator == (modint<MOD> other) const { return value == other.value; }
  inline bool operator != (modint<MOD> other) const { return value != other.value; }
  inline bool operator < (modint<MOD> other) const { return value < other.value; }
  inline bool operator > (modint<MOD> other) const { return value > other.value; }
};
template <int MOD> modint<MOD> operator * (int value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int MOD> istream &operator >> (istream &in, modint<MOD> &n) { return in >> n.value; }
template <int MOD> ostream &operator << (ostream &out, modint<MOD> n) { return out << n.value; }
using mint = modint<mod>;

/**************************** --- Bits --- ****************************/
ll binpow(ll a, ll n) { a %= mod; ll res = 1; while (n > 0) { if (n & 1) res = res * a % mod; a = a * a % mod; n >>= 1; } return res; }

#define set_bits(n) __builtin_popcountll(n)
#define isSet(i,n) (((1ll<<(i))&(n))!=0)
#define isPow2(n) (((n)&((n)-1))==0)

/**************************** --- Segment Tree --- ****************************/
struct segTreeNode{
  ll lar,secLar,cntLar,cntSecLar;
};

class SegTree{
public:
  vector<segTreeNode> seg;

  SegTree(int n){
    seg.resize(4*n);
  }

  segTreeNode merge(segTreeNode left, segTreeNode right){
    if(left.lar==right.lar){
      if (left.secLar == right.secLar) return { left.lar,left.secLar,left.cntLar + right.cntLar,left.cntSecLar + right.cntSecLar };
      if (left.secLar > right.secLar) return { left.lar,left.secLar,left.cntLar + right.cntLar,left.cntSecLar };
      return { left.lar,right.secLar,left.cntLar + right.cntLar,right.cntSecLar };
    }
    if(left.lar>right.lar){
      if (left.secLar == right.lar) return { left.lar,left.secLar,left.cntLar,left.cntSecLar+right.cntLar };
      if(left.secLar>right.lar) return left;
      return { left.lar,right.lar,left.cntLar,right.cntLar };
    }
    if (right.secLar == left.lar) return { right.lar,right.secLar,right.cntLar,right.cntSecLar + left.cntLar };
    if (right.secLar > left.lar) return right;
    return { right.lar,left.lar,right.cntLar,left.cntLar };
  }

  void build(int ind,int low,int high,vector<int> &a){
    if(low==high){
      seg[ind]={a[low],-INF,1,0};
      return;
    }
    int mid=low+(high-low)/2;
    build(2*ind+1,low,mid,a);
    build(2*ind+2,mid+1,high,a);
    seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
  }

  segTreeNode query(int ind,int low,int high,int l,int r){
    if(low>r||high<l) return {-INF,-INF-1,0,0};
    if(low>=l&&high<=r) return seg[ind];
    int mid=low+(high-low)/2;
    segTreeNode left=query(2*ind+1,low,mid,l,r);
    segTreeNode right=query(2*ind+2,mid+1,high,l,r);
    return merge(left,right);
  }

  void pointUpdate(int ind,int low,int high,int pos,int val){
    if(low==high){
      seg[ind]={val,-INF,1,0};
      return;
    }
    int mid=low+(high-low)/2;
    if(pos<=mid) pointUpdate(2*ind+1,low,mid,pos,val);
    else pointUpdate(2*ind+2,mid+1,high,pos,val);
    seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
  }
};

/**************************** --- Input --- ****************************/
template<typename typC, typename typD> istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.fi >> a.se; }
template<typename typC> istream &operator>>(istream &cin, vector<typC> &a) { for (auto &x : a) cin >> x; return cin; }

/**************************** --- Output --- ****************************/
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.fi << ' ' << a.se; }
template<typename typC> ostream &operator<<(ostream &cout, const vector<typC> &a) { ll n = sz(a); if (!n) return cout << endl; cout << a[0]; f(i, 1, n) cout << ' ' << a[i]; return cout << endl; }
template<typename typC> ostream &operator<<(ostream &cout, const vector<vector<typC>> &a) { ll n = sz(a); if (!n) return cout << endl; f(i, 0, n) cout << a[i]; return cout; }
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a) { fa(x, a) cout << x << endl; return cout; }
template<typename typC> ostream &operator<<(ostream &cout, const set<typC> &a) { fa(it, a) cout << it << ' '; return cout << endl; }
template<typename typC> ostream &operator<<(ostream &cout, const unordered_set<typC> &a) { fa(it, a) cout << it << ' '; return cout << endl; }
template<typename typC> ostream &operator<<(ostream &cout, const multiset<typC> &a) { fa(it, a) cout << it << ' '; return cout << endl; }
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const map<typC, typD> &a) { fa(it, a) cout << it << endl; return cout; }
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const unordered_map<typC, typD> &a) { fa(it, a) cout << it << endl; return cout; }
template<typename typC, typename typD> ostream &operator<<(ostream &cout, const multimap<typC, typD> &a) { fa(it, a) cout << it << endl; return cout; }

/**************************** --- Debug --- ****************************/
#define debug(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl
template<typename... Args> void dbg(Args... args) { ((cout << args << ' '), ...) << endl; }

/**************************** --- Precompute --- ****************************/

void precompute() {
  
}


/**************************** --- Code --- ****************************/
void solve() {
  ll n; cin>>n;
  vl a(n),b(n); cin>>a>>b;
  ll curA=0,curB=0;
  vl oddA,evenA,oddB,evenB;
  f(i,0,n){
    curA+=a[i],curB+=b[i];
    if(i&1) oddA.pb(curA),oddB.pb(curB);
    else evenA.pb(curA),evenB.pb(curB);
  }
  asc(oddA),asc(evenA),asc(oddB),asc(evenB);
  if(oddA==oddB&&evenA==evenB&&curA==curB) yes;
  no;
}

/**************************** --- Test cases --- ****************************/
int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll TC = 1;
  cin >> TC;

  precompute();

  f(x, 1, TC + 1) {
    // cout<<"Case #"<<x<<": ";
    solve();
  }
}
