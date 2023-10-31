//https://www.codechef.com/INOIPRAC/problems/INOI2001?tab=statement
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF (int)1e18
#define endl '\n'
const int mod = 1000 * 1000 * 1000 + 7;
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100005;
vector<int> adj[N];
vector<bool> visited(N);
int mx = -1;
int mn = 1e18;

int ct = 0;
void type(int u ){
    visited[u] = true;
    ct++;
    mx = max(u,mx); mn = min(mn,u);
    for(auto &i : adj[u]){
        if (!visited[i]){
            type(i );
        }
    }
}

int visited2[N] = {0};

int ans = 0;
void dfs(int u , int depth){
    ans += depth;
    visited2[u] = true;
    for(auto &i : adj[u]){
        if (!visited2[i])
            dfs(i, depth+1);
    }
}

void Solve() {
    int n  , m; cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int u , v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int odd = 0 ,  even = 0;
    for(int i = 1 ; i<= n ; i++){
        if (visited[i]) continue;
        type(i);
      //  cout<<ct<<" "<<mn<<" "<<mx<<endl;
        if (ct%2==0){
            dfs(mn , 1);
            even += ans;
        }
        else{
            dfs(mx,1);
            odd += ans;
        }
        ans = 0;
        mx = -1;
        mn = 1e18;
        ct = 0;
    }
    cout<<even<<" "<<odd<<endl;
    for(int i = 1; i<= n ; i++){
        adj[i].clear();
        visited[i] = false;
        visited2[i] = false;
    }
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
