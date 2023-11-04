#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 1e9+7
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a)*(b))/(gcd(a,b))
#define RE(i,n) for(int i = 1;i <= n;i++)
#define REP(i,n) for(int i = 0;i < n;i++)
#define REPD(i,n) for(int i = n-1;i > -1;i--)
#define RED(i,n) for(int i = n;i > 0;i--)
#define FOR(i,a,b) for(int i = a;i <= b;i++)
#define FORD(i,a,b) for(int i = a;i >= b;i--)
#define debug(a) cout << a << endl;
#define debug2(a,b) cout << a << " " << b << endl;
#define debug3(a,b,c) cout << a << " " << b << " " << c << endl;
#define f first
#define s second
#define all(a) a.begin,a.end()
#define pii pair<int,int> 
#define vi vector<int>

int power(int a,int n,int m = MOD){
	if(n == 0)return 1;
	if(n == 1)return a;
	int res= power(a,n/2,m)*power(a,n/2,m);
	res %= m;
	if(n%2)res *= a;
	return res%m;
}

const int N = 5001;
int a[N];//public
int b[N];//unimp
int point[N];// include
int tmp[N];
int dp[N][N];
int n,m;
int ind[N];

void ini(){
	 REP(i,N){
	 	REP(j,N){
	 		dp[i][j] = INF;
	 	}
	 }
}

bool comp(int a1,int b1){
	 return point[a1] < point[b1];
}

void solve(){
	 ini();
     cin >> n >> m;
     swap(n,m);
     RE(i,m)cin >> b[i];
     ind[0] = 0;
     RE(i,n){cin >> a[i];ind[i] = i;}
     RE(i,n){cin >> point[i];}
     sort(ind,ind+n+1,comp);
     RE(i,n){
     	tmp[i] = a[ind[i]];
     }
     RE(i,n){
     	a[i] = tmp[i];
     }
     sort(point,point+n+1);
     RE(i,n-1){
        if(point[i] == point[i+1]){
            cout << -1 << endl;
            return;
        }
     }
     dp[0][0] = 1;
     dp[1][0] = max(point[1]+1,a[1]+1);
     dp[0][1] = b[1]+1;
     REP(i,n+1){
     	REP(j,m+1){
     		if(i+j < 2){continue;}
     		int st = dp[i-1][j];
     		int cost = INF;

            if(st > point[i])cost = INF;
     		else if(st+a[i] <= point[i])cost = point[i]+1;
     		else cost = st+a[i];

     		if(i == 0)dp[0][j] = dp[0][j-1]+b[j];
     		else if(j == 0)dp[i][0] = cost;
            else dp[i][j] = min(dp[i][j],min(dp[i][j-1]+b[j],cost));
     	}
     }
     if(dp[n][m] == INF)cout << -1 << endl;
     else cout << dp[n][m]-1 << endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;t = 1;cin >> t;
    while(t--)solve();
	return 0;
}
