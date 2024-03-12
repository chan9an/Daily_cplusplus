// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
 
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<typename T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <class K,class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define lb lower_bound
#define ub upper_bound
#define Checkbit(a,i) (((a)>>(i))&1)
#define Setbit(a,i) ((a)^=1LL<<(i))

const int mod = 1e9 + 7;
class BIT
{
public:
    vector<int> tree;
    int n;
    BIT(int sz, int val = 0) {
        tree.assign(sz + 5, val);
        n = sz;
    }
    void update(int pos, int val) {
        while (pos <= n) {
            tree[pos] += val;
            pos += pos & -pos;
        }
    }
    void update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }
    int query(int l) {
        int sum = 0;
        while (l > 0) {
            sum += tree[l];
            l -= l & -l;
        }
        return sum;
    }
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

class LCA 
{
public:
    vector<int> depth;
    vector<vector<pair<int,int>>> graph;
    vector<int> tin;
    vector<vector<int>> up;
    vector<int> sub;
    int N;
    int Time;
    int LOG;
    LCA(int n) : N(n) {
        Time = 0;
        depth.assign(N + 5, 0);
        graph.assign(N + 5, vector<pair<int,int>>());
        tin.assign(N + 5, 0);
        sub.assign(N + 5, 0);
        LOG = __lg(N) + 2;
        up.assign(N + 5, vector<int>(LOG));
    }
    void addEdge(int u, int v, int w = 1) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    void dfs(int u, int p = 0, int cost = 0) {
        tin[u] = ++Time;
        up[u][0] = p;
        depth[u] = depth[p] + 1;
        sub[u] = 1;
        for (int i = 1; i < LOG; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (auto [v, w] : graph[u]) {
            if (v != p) {
                dfs(v, u, cost + w);
                sub[u] += sub[v];
            }
        }
    }
    int lca(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        int dif = depth[v] - depth[u];
        for (int i = LOG - 1; i >= 0; i--) {
            if ((dif >> i) & 1) {
                v = up[v][i];
            }
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
};

const int N = 1e5;

void testcase()
{
    int n, Q;
    cin >> n >> Q;

    LCA t(n);
    BIT st(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        t.addEdge(u, v);
    }
    t.dfs(1);

    auto &depth = t.depth;
    auto &tin = t.tin;
    auto &sub = t.sub;
    auto &up = t.up;
    vector<set<pii>> g(n + 1);
    vector<int> marked(n + 1);

    auto upd = [&](int u, int type) {
        auto it1 = g[depth[u]].ub({tin[u], u});
        auto it2 = g[depth[u]].lb({tin[u], u});
        int till = 0;
        if (it1 != g[depth[u]].end()) {
            auto [_, v] = *it1;
            int lca = t.lca(u, v);
            if (depth[lca] > depth[till]) till = lca;
        }
        if (it2 != g[depth[u]].begin()) {
            auto [_, v] = *prev(it2);
            int lca = t.lca(u, v);
            if (depth[lca] > depth[till]) till = lca;
        }
        if (till != 0) st.update(tin[till], -type);
        if (up[u][0]) st.update(tin[up[u][0]], type);
        // debug(u, till, type);
    };

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u;
            cin >> u;
            // debug(marked);
            cout << st.query(tin[u], tin[u] + sub[u] - 1) << "\n";
        }
        else {
            int u;
            cin >> u;
            auto it1 = g[depth[u]].ub({tin[u], u});
            auto it2 = g[depth[u]].lb({tin[u], u});
            if (it1 != g[depth[u]].end()) {
                upd(it1->s, -1);
            }
            if (it2 != g[depth[u]].begin()) {
                upd(prev(it2)->s, -1);
            }
            if (marked[u]) {
                g[depth[u]].erase({tin[u], u});
                upd(u, -1);
            }
            else {
                upd(u, 1);
                g[depth[u]].insert({tin[u], u});
            }
            marked[u] = !marked[u];
            it1 = g[depth[u]].ub({tin[u], u});
            it2 = g[depth[u]].lb({tin[u], u});
            if (it1 != g[depth[u]].end()) {
                upd(it1->s, 1);
            }
            if (it2 != g[depth[u]].begin()) {
                upd(prev(it2)->s, 1);
            }
        }
    }
}
 
signed main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int cs = 1;
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        testcase();
    }
}
