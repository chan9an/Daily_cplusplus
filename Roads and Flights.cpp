// Problem: Roads and Flights
// Contest: CodeChef - START117
// URL: https://www.codechef.com/problems/ROADAIR
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include<chrono>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std::chrono;
using namespace __gnu_pbds;
using namespace std;
#ifndef ONLINE_JUDGE
 #include "algo/debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#define debug(...) ;
#endif
#define ff                  first
#define ss                  second
#define int                 long long
#define pb                  push_back
#define mp                  make_pair
#define pii                 pair<int,int>
#define vi                  vector<int>
#define vvi                  vector<vi>
#define mii                 map<int,int>
#define pqb                 priority_queue<int>
#define pqs                 priority_queue<int,vi,greater<int> >
#define setbits(x)          __builtin_popcountll(x)
#define zrobits(x)          __builtin_ctzll(x)
#define modm                998244353    //this is a prime number
#define inf                 1e18
#define ps(x,y)             fixed<<setprecision(y)<<x
#define mk(arr,n,type)      type *arr=new type[n];
#define w(x)                int x; cin>>x; while(x--)
#define fd(i,a,b)           for(int i=a;i>b;i--)
#define fde(i,a,b)           for(int i=a;i>=b;i--)
#define f(i,a,b)            for(int i=a;i<b;i++)
#define fe(i,a,b)           for(int i=a;i<=b;i++)
#define input(x)            int x;cin>>x;
#define PI                  3.141592653589793238462
#define all(x)              (x).begin(), (x).end()
#define endl                '\n'
#define el                  '\n'
#define triplet             pair<int,pair<int,int>>
#define prDouble(x)         cout<<fixed<<setprecision(10)<<x
#define FastIO              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define set_bits            __builtin_popcountll
#define parity              __builtin_parity //even number of 1:0 & odd number of 1:1
#define zeroesAtStart       __builtin_clz
#define zeroesAtEnd         __builtin_ctz
#define yc                  y_combinator
#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")  //for optimising popcountll,clz (count leading zeroes)
typedef tree<int ,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; 
// Custom hash map
struct chash
{
static uint64_t splitmix64(uint64_t x)
{
x += 0x9e3779b97f4a7c15;
x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
return x ^ (x >> 31);
}
size_t operator()(uint64_t x) const
{
static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
return splitmix64(x + FIXED_RANDOM);
}
};
template <class K, class V> using cmap = gp_hash_table<K, V, chash>;
// example usage: cmap<int, int>
//for map<pair<int,int>,int>
struct HASH{
size_t operator()(const pair<int,int>&x)const{
return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
}
};
struct mint {int mod,val;mint(int val=0,int mod=998244353):mod(mod),val((val%mod+mod)%mod){}
  mint& fix() { val = (val%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint operator~() const { return mint(1) / *this;}
  mint& operator+=(const mint& a){ if((val+=a.val)>=mod) val-=mod; return *this;}
  mint& operator-=(const mint& a){ if((val+=mod-a.val)>=mod) val-=mod; return *this;}
  mint& operator*=(const mint& a){ (val*=a.val)%=mod; return *this;}
  mint& operator/=(const mint& a){ (val*=a.exp(mod-2).val)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  mint operator/(const mint& a)const{ return mint(*this) /= a;}
  mint exp(int t) const {
    if(!t) return 1;
    mint res = exp(t/2);
    res *= res;
    return (t&1)?res*val:res;
  }
  bool operator<(const mint& a)const{ return val < a.val;}
  bool operator==(const mint& a)const{ return val == a.val;}
};
// Operator overloads
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, chash>;
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v){cin >> it;}return istream;}
template<typename T,typename V> // cin >> vector<pair<T,V>>
istream& operator>>(istream &istream, vector<pair<T,V>> &v){for (auto &it : v){cin >>it.ff>>it.ss;}return istream;}
istream& operator>>(istream& istream,mint& v){cin>>v.val;return(istream);};
ostream &operator<<(ostream& ostream,mint v){cout<<v.val;return(ostream);};
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, pair<T1, T2> &p)
{for(auto x:p){cout<<x.ff<<" "<<x.ss<<el;}return (ostream);}
template <typename T> // cout<< vector<T>
ostream &operator<<(ostream &ostream, vector<T> &v)
{for(auto &it : v){cout<<it<<" ";}return ostream;}
template <typename T, typename V> // cout << vector<pair<T,V>>
ostream &operator<<(ostream &ostream, vector<pair<T, V>> &v)
{for (auto &it : v){cout<<it.ff<<" "<<it.ss<<el;}return ostream;}
// y-combinator
template <class Fun> class y_combinator_result {Fun fun_;public:template <class T>explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}template <class... Args> decltype(auto) operator()(Args &&...args) {return fun_(std::ref(*this), std::forward<Args>(args)...);}};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) {return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));}
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
//int gcd(int a,int b){ if(b==0) return a; else return gcd(b,a%b); } //time complexity:O(log(max(a,b)))
int gcd(int a,int b){if(!a || !b){return (a|b);};int shift = zeroesAtEnd(a|b);a>>= zeroesAtEnd(a);do{b>>=zeroesAtEnd(b);if(a>b){swap(a,b);}b-=a;}while(b);return (a<<shift); }
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
long long expo(int base,  int exp,  int mod){int x = 1;int i;int power = base % mod;for (i = 0; i < sizeof(int) * 8; i++) {int least_sig_bit = 0x00000001 & (exp >> i);if (least_sig_bit){x = (x * power) % mod;}power = (power * power) % mod;}return x;}
int inv(int a, int b) {return expo(a, b - 2, b);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, inv(b, m), m) + m) % m;}  //only for prime m
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
template <typename Node, typename Update>
struct LazySGT
{
    vector<Node> segtree;
    vector<bool> lazy;
    vector<Update> updates;
    vector<int> arr; // type may change
    int n;
    int s;
    LazySGT(int a_len, vector<int> &a)
    { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n)
        {
            s = s << 1;
        }
        segtree.resize(s);
        fill(all(segtree), Node());
        lazy.resize(s);
        fill(all(lazy), false);
        updates.resize(s);
        fill(all(updates), Update());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index)
    { // Never change this
        if (start == end)
        {
            segtree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        segtree[index].merge(segtree[2 * index], segtree[2 * index + 1]);
    }
    void pushdown(int index, int start, int end)
    {
        if (lazy[index])
        {
            int mid = (start + end) / 2;
            apply(2 * index, start, mid, updates[index]);
            apply(2 * index + 1, mid + 1, end, updates[index]);
            updates[index] = Update();
            lazy[index] = 0;
        }
    }
    void apply(int index, int start, int end, Update &u)
    {
        if (start != end)
        {
            lazy[index] = 1;
            updates[index].combine(u, start, end);
        }
        u.apply(segtree[index], start, end);
    }
    void update(int start, int end, int index, int left, int right, Update &u)
    { // Never Change this
        if (start > right || end < left)
            return;
        if (start >= left && end <= right)
        {
            apply(index, start, end, u);
            return;
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        update(start, mid, 2 * index, left, right, u);
        update(mid + 1, end, (2 * index) + 1, left, right, u);
        segtree[index].merge(segtree[2 * index], segtree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right)
    {
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
        {
            pushdown(index, start, end);
            return segtree[index];
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int left, int right, int val)
    {                            
        Update new_update = Update(val);
        update(0, n - 1, 1, left, right, new_update);
    }
    Node make_query(int left, int right)
    {
        return query(0, n - 1, 1, left, right);
    }
};

//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
struct Node1
{
    int val; // may change
    Node1()
    {                          // Identity element
        val = 0; // may change
    }
    Node1(int p1)
    {             // Actual Node
        val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r)
    {                        // Merge two child nodes
        val = l.val + r.val; // may change
    }
};

struct Update1
{
    int val; // may change
    Update1()
    { // Identity update
        val = 0;
    }
    Update1(int val1)
    { // Actual Update
        val = val1;
    }
    void apply(Node1 &a, int start, int end)
    {   // apply update to given node
        a.val = val; // * (end - start + 1); // may change
    }
    void combine(Update1 &new_update, int start, int end)
    {
        val = new_update.val;
    }
};
struct vertex
{
    char ch;   // assuming characters = 'a-z'
    int index; // index of the string added
    vertex *next[26], *go[26], *par, *link, *exit_link;
    // link = suffix link
    // go =  any link towards a given character if possible(similar to dictionary link)
    // next = next child nodde
    vertex()
    {
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
            go[i] = NULL;
        }
        par = link = exit_link = NULL;
        index = -1;
    }
    vertex(char ch, vertex *ppar) : ch(ch), par(ppar)
    {
        for (int i = 0; i < 26; i++)
        {
            next[i] = go[i] = NULL;
        }
        link = NULL;
        exit_link = NULL;
        index = -1;
    }
};
class aho_corasick
{
public:
    vertex *root;
    aho_corasick()
    {
        root = new vertex;
    };
    // adding string similarly as we do in trie
    void add_string(string s, int idx)
    {
        vertex *ptr = root;
        for (auto x : s)
        {
            if (ptr->next[x - 'a'] == NULL)
            {
                ptr->next[x - 'a'] = new vertex(x, ptr);
            }
            ptr = ptr->next[x - 'a'];
        }
        ptr->index = idx;
    };
    // finding suffix link
    vertex *getLink(vertex *u)
    {
        if (u->link != NULL)
        {
            return u->link;
        }
        if (u == root || u->par == root)
        {
            u->link = root;
        }
        else
        {
            // u->link = getLink(u->par)->next[u->ch];
            // finding a link towards 'u->ch' character from suffix link of current node's parent node
            u->link = go(getLink(u->par), u->ch);
        }
        return u->link;
    }
    // finding a linked node from 'u' node towards 'ch' character
    vertex *go(vertex *u, char ch)
    {
        if (u->go[ch - 'a'] != NULL)
        {
            return u->go[ch - 'a'];
        }
        if (u->next[ch - 'a'] != NULL)
        {
            u->go[ch - 'a'] = u->next[ch - 'a'];
        }
        else
        {
            u->go[ch - 'a'] = (u == root) ? root : go(getLink(u), ch);
        }
        return u->go[ch - 'a'];
    }
    // nearest leaf vertex that is reachable using suffix links
    // here leaf vertex means a vertex where any of the given strings ends
    vertex *get_exit_link(vertex *u)
    {
        if (u->exit_link != NULL)
        {
            return u->exit_link;
        }
        if (getLink(u)->index != -1 || getLink(u) == root)
        {
            // here either a given string ends (index!=-1) or the node is root node.
            u->exit_link = getLink(u);
        }
        else
        {
            u->exit_link = get_exit_link(getLink(u));
        }
        return u->exit_link;
    }
};
//-------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
const int mxn=3e5+5;
int n,m;
vi adj[mxn],rev_adj[mxn];
vector<mint> dp1,dp2;
int component[mxn],vis[mxn];
int componentSize[mxn];
vvi comps;
vector<mint> mull;
void init(){
	comps.clear();
	dp1.clear();
	dp2.clear();
	f(i,0,n+4){
		adj[i].clear();
		rev_adj[i].clear();
		component[i]=-1;
		vis[i]=0;
		componentSize[i]=0;
	}
}
void solve(){
	cin>>n>>m;
	dp1.resize(n+2,mint(0,modm));
	dp2.resize(n+2,mint(0,modm));
	vector<pii> edges;
	f(i,0,m){
		int u,v;cin>>u>>v;
		edges.pb({u,v});
		adj[u].pb(v);swap(u,v);
		rev_adj[u].pb(v);swap(u,v);
	}	
	vi dfsOrder;
	auto dfs1=yc(
		[&](auto&& dfs1,int node)->void{
			vis[node]=1;
			for(auto x:adj[node]){
				if(!vis[x]){
					dfs1(x);
				}
			}
			dfsOrder.pb(node);
		}
	);
	f(i,1,n+1){
		if(!vis[i]){dfs1(i);}
	}
	dbg(dfsOrder);
	reverse(all(dfsOrder));
	int compNo=1;
	f(i,0,n+4){vis[i]=0;}
	vi tmp;
	comps.pb({});

	auto dfs2=yc(
		[&](auto&& dfs2,int node,int compNo)->void{
			component[node]=compNo;
			componentSize[compNo]++;
			tmp.pb(node);
			vis[node]=1;
			for(auto x:rev_adj[node]){
				if(!vis[x]){dfs2(x,compNo);}
			}
		}
	);
	for(auto x:dfsOrder){
		if(!vis[x]){
			vis[x]=1;
			dfs2(x,compNo++);
			dbg(x,tmp);
			comps.pb(tmp);
			tmp.clear();
		}
	}
	f(i,1,n+1){
		dp1[i]=1;
	}
	dbg(comps);
	for(auto comp:comps){
		mint sm(0,modm);
		for(auto node:comp){
			for(auto elem:rev_adj[node]){
				if(component[node]!=component[elem]){
					dp1[node]+=dp2[elem];	
				}
			}			
			sm+=dp1[node];
		}
		dbg(sm.val);
		mint mull(0,modm),cur(1,modm);
		int sz=max(0ll,(int)comp.size()-2);
		f(j,0,sz+1){
			mull+=cur;
			cur*=(sz-j);
		}
		for(auto node:comp){
			dp2[node]=dp1[node];
			if(comp.size()>=2){
				dp2[node]+=(mull*((sm-dp1[node]+modm).val%modm));
			}
		}
	}
	mint res(0,modm);
	f(i,1,n+1){
		dbg(i,dp2[i].val);
		res+=dp2[i];
	}
	cout<<res<<"\n";	
	init();
}	
int32_t main()
{
    FastIO;
    w(t){
        solve();
    }
    return 0;
}
