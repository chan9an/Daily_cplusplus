#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define INF 1e+18

vector<int> bfs(int v, int n, vector<vector<int>>& g) {
    queue<int> q;
    q.push(v);
    vector<int> dist(n + 1, INF);
    dist[v] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < g[u].size(); ++i) {
            int neighbor = g[u][i];
            if (dist[neighbor] == INF) {
                dist[neighbor] = dist[u] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}

void dfs(int v,vector<vector<int>>&g,vector<int>&par,int p){
	for(auto child:g[v]){
		if(child==p){
			continue;
		}
		par[child]=v;
		dfs(child,g,par,v);
	}
}



void solve()
{
	int n;
	cin>>n;
	vector<vector<int>>g(n+1);

	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vector<vector<int>>dist(n+1);

	for(int i=1;i<=n;i++){
		dist[i]=bfs(i,n,g);
	}

	int u,v;
	int max_dist=-INF;

	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i==j)continue;
			if(max_dist<dist[i][j]){
				max_dist=dist[i][j];
				u=i;
				v=j;
			}
		}
	}

	vector<int>par(n+1);
	dfs(u,g,par,-1);

	vector<int>path;
	int t=v;
	path.push_back(t);

	while(par[t]!=u){
		path.push_back(par[t]);
		t=par[t];
	}
	path.push_back(u);
  
	vector<int>ans(n+1,-1);

	for(int i=0;i<path.size();i++){
		if(i>=path.size()/2)
		ans[path[i]]=0;
		else ans[path[i]]=1;
	}

	int s=0;

	for(int i=1;i<=n;i++){
		if(ans[i]==-1){
			if((s&1) == 0){
				ans[i]=1;
			}else{
				ans[i]=0;
			}
			s^=1;
		}
	}

	for(int i=1;i<=n;i++){
		if(ans[i]==1)cout<<"R";
		else cout<<"B";
	}
	cout<<endl;

}


signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t;
	cin>>t;

	while(t--)solve();
}
