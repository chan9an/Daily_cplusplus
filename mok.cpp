#include <bits/stdc++.h>

#define FOR(i,a,b) for(ll i = (a);i < (b);i ++)
#define ROF(i,a,b) for(ll i = (a);i >= (b);i --)
#define trav(a, b) for(auto& a : (b))
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

#define pb push_back
#define mk make_pair
#define mt make_tuple
#define f first
#define s second

using namespace std;

typedef long long ll;

int n;
vector<vector<int>> a[2];

vector<int> ops;

bool check(const vector<vector<int>>& arr){
	FOR(i,0,n){
		bool ps = false;
		FOR(j,0,n){
			bool pos = true;
			for(int it = 0, k = j;it < n;k  = (k + 1) % n, it ++){
				if(arr[i][k] != a[1][i][it]){
					pos = false;
				}
			}
			if(pos){
				for(int rep = 0;rep < j;rep ++){
					ops.pb(-(i + 1));
				}
				ps = true;
				break;
			}
		}
		if(!ps){
			ops.clear();
			return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin >> n;
	FOR(i,0,2){
		a[i].assign(n, vector<int>(n));
	}
	FOR(i,0,2){
		FOR(j,0,n){
			FOR(k,0,n){
				cin >> a[i][j][k];
			}
		}
	}

	FOR(i,0,n){
		vector<vector<int>> nw = a[0];
		int h = nw[n - 1][i];
		FOR(j,0,n){
			int tmp = nw[j][i];
			nw[j][i] = h;
			h = tmp;
		}
		ops.pb(-i - 1);
		if(check(nw)){
			cout << "YES\n";
			cout << sz(ops) << ' ';
			trav(e, ops){
				cout << e << ' ';
			}
			cout << '\n';
			return 0;
		}
		nw = a[0];
		h = nw[0][i];
		ROF(j,n - 1,0){
			int tmp = nw[j][i];
			nw[j][i] = h;
			h = tmp;
		}
		ops.pb(i + 1);
		if(check(nw)){
			cout << "YES\n";
			cout << sz(ops) << ' ';
			trav(e, ops){
				cout << e << ' ';
			}
			cout << '\n';
			return 0;
		}
	}


	cout << "NO\n";

	return 0;
}
