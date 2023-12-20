#include <bits/stdc++.h>
#define size siz
using namespace std;

typedef long long ll;

ll size[3000], a[3000], in[3000], out[3000], timer;
vector<int> adj[3000];

void dfs(int x, int pr)
{
	in[x] = timer ++;
	size[x] = a[x];
	for(auto e : adj[x]){
		if (e != pr){
			dfs(e, x);
			size[x] += size[e];
		}
	}
	out[x] = timer - 1;
}

bool isAn(int x, int y)
{
	if(in[x] <= in[y] && in[y] <= out[x])return true;
	return false;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}

	for(int i = 0;i < n - 1;i ++){
		int x, y;
		cin >> x >> y;
		x --;y --;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(0, -1);

	ll ans = LONG_LONG_MAX;

	for(int i = 1;i < n;i ++){
		for(int j = i + 1;j < n;j ++){
			int x = i, y = j;
			if(isAn(i, j)){
				ans = min(ans, max(max(size[0] - size[x], size[x] - size[y]), size[y]));
			} else if(isAn(j, i)){
				ans = min(ans, max(max(size[0] - size[y], size[y] - size[x]), size[x]));
			} else {
				ans = min(ans, max(max(size[0] - size[x] - size[y], size[x]), size[y]));
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
