#include <iostream>
#include <vector>
#include <cstring>

#define inf 1'000'000'000'000'000'000
#define int long long

using namespace std;

int memo[5005][5005];
int raz[5005][5005];
vector<int> graf[5005];
int a[5005][2];

void zrz(int i, int u, int p) //dela
{
	if (p+1)
		raz[i][u] = raz[i][p]+1;
	for (int v : graf[u])
		if (v != p)
			zrz(i, v, u);
}

int dfs(int n, int m, int ix, int tpr, int tdr, int um)
{
	if (ix == m)
		return 0;
	if (memo[um][ix]!=-1) //memo dela
		return memo[um][ix];
	int zac = a[ix][0], kon = a[ix][1];
	
	int razdalja = (raz[tpr][zac] + raz[zac][kon])*2 - (raz[tpr][zac]+raz[zac][kon]-raz[tpr][kon])/2;
	
	int rez = dfs(n, m, ix+1, kon, tdr, tdr) + razdalja;
	if (tdr == n)
		tdr = zac;
	razdalja = (raz[tdr][zac] + raz[zac][kon])*2 - (raz[tdr][zac]+raz[zac][kon]-raz[tdr][kon])/2;
	
	rez = min(rez, dfs(n, m, ix+1, tpr, kon, tpr)+razdalja);
	return memo[um][ix] = rez;
}

int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(memo, -1, sizeof(memo));
		int n, m;
		cin >> n >> m;
		for (int i = 0; i <= n; i++)
			graf[i].clear();
		for (int i = 0; i < n-1; i++)
		{
			int u, v;
			cin >> u >> v;
			u--;v--;
			graf[u].push_back(v);
			graf[v].push_back(u);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> a[i][0] >> a[i][1];
			a[i][0]--;a[i][1]--;
		}
		for (int i = 0; i < n; i++)
		{
			raz[i][i] = 0;
			zrz(i, i, -1);
		}
		if (m >= 2 && n!=1)
			cout << dfs(n, m, 0, a[0][0], n, a[0][0]) << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}
