#include <bits/stdc++.h>
using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
#define ln "\n"
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define f(a) for(int i = 0; i<a; ++i)
#define deb(a) cerr<<a<<endl;
#define fi first
#define se second
#define inf 5e5

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;
typedef vector<str> vestr;
typedef vector<int> vei;
typedef vector<vector<int>> veve;
typedef unordered_map<int,int> umap;

void solve(){
    int n, d; //array size and max diference
	cin >> n >> d;
	vector<int>b(n), c(n), a(n);
	queue<int>imp;//will store important elements here
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	if (b[0] != c[0])
	{
		cout << "NO" << ln;
		return;
	}
	for (int i = 1; i < n; i++)
	{
		if (b[i] < b[i - 1] || c[i] > c[i - 1])
		{
			cout << "NO" << ln;
			return;
		}
		if (b[i] != b[i - 1] && c[i] != c[i - 1])
		{
			cout << "NO" << ln;
			return;
		}
		if (b[i] != b[i - 1])
		{
			imp.push(b[i]);
		}
		if (c[i] != c[i - 1])
		{
			imp.push(c[i]);
		}
	}
	a[0] = b[0];
	int cr = a[0];//current value
	int mx = cr, mn = cr;
	for (int i = 1; i < n; i++)
	{
		while (!imp.empty() && cr == imp.front())
		{
			imp.pop();
		}
		if (imp.empty())
		{
			a[i] = a[i - 1];
		}
		//else
		{
			int nxt = imp.front();
			if (nxt >= cr)
			{
				nxt = min(nxt, b[i]); //maintaing the limit
				int req = nxt - cr;//reqired change
				req = min(req, d);//as we can change at most d
				cr += req;
				a[i] = cr;
			}
			else
			{
				nxt = max(nxt, c[i]);
				int req = cr - nxt;
				req = min(req, d);
				cr -= req;
				a[i] = cr;
			}
		}
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
		//cheking if it is maintaining well
		if (mx != b[i] || mn != c[i])
		{
			cout << "NO" << ln;
			return;
		}
	}
	cout << "YES" << endl;
	for (auto it : a) cout << it << ' ';
	cout << ln;
}   

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
   // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}
