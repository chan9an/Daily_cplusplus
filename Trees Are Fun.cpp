#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define pi pair<int, int>
#define pii pair<int, pi>
#define fi first
#define se second
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k, A[500005], cur[500005];
vector <int> adj[500005], bruh[500005];
int par[500005], col[500005];
int getr(int x){return par[x] == x ? x : par[x] = getr(par[x]);}
void merge(int a, int b){par[getr(b)] = getr(a);}

unordered_map <int, vector <int> > dfs(int x, int p, int d){
	cur[x] = 1;
	unordered_map <int, vector <int> > mp;
	mp[d].push_back(x);
	for(auto i : adj[x]){
		if(i == p)continue;
		unordered_map <int, vector <int> > tmp = dfs(i, x, d + 1);
		if(cur[x] < cur[i])swap(mp, tmp), swap(cur[x], cur[i]);
		//x is the lca --> y + j - 2 * d = k --> y = 2  * d + k - j
		for(auto &[j, kk] : tmp){
			if(kk.empty())continue;
			int cry = 0;
			for(auto a : mp[2 * d + k - j]){
				if(!cry){for(auto b : kk){
					merge(a, b);
					bruh[a].push_back(b); bruh[b].push_back(a);
				} cry = 1;}
				else merge(a, kk[0]), bruh[a].push_back(kk[0]), bruh[kk[0]].push_back(a);
			}
			if(cry)while(kk.size() >= 2)kk.pop_back();
		}
		for(auto [j, kk] : tmp){
			if(kk.empty())continue;
			cur[x] += (int)kk.size();
			for(auto a : kk)mp[j].push_back(a);
		}
	}
	return mp;
}
vector <int> stuf[500005];
int vis[500005];
void proc(int x, int c){
	if(vis[x])return;
	vis[x] = 1;
	col[x] = c;
	for(auto i : bruh[x])proc(i, c ^ 1);
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++)cin >> A[i], adj[i].clear(), stuf[i].clear(), bruh[i].clear(), col[i] = vis[i] = 0;
	for(int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)par[i] = i;
	dfs(1, -1, 1);
	long long ans = 0;
	for(int i = 1; i <= n; i++)stuf[getr(i)].push_back(i);
	for(int i = 1; i <= n; i++){
		if(stuf[i].empty())continue;
		proc(stuf[i][0], 0);
		long long tmp = 0;
		for(auto j : stuf[i]){
			if(col[j])tmp -= A[j];
			else tmp += A[j];
		}
		ans += abs(tmp);
	}
	cout << ans << '\n';
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int tc1=1;tc1<=tc;tc1++){
		// cout << "Case #" << tc1 << ": ";
		solve();
	}
}
