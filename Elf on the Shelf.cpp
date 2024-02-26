#include<bits/stdc++.h>
 
 
#include<ext/pb_ds/assoc_container.hpp> // Common file
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order(k): iterator to the kth element (0- based indexing)
// order_of_key(k) : number of items that are strictly smaller than item k 
// priority_queue <int, vector<int>, greater<int> > pq;
//for multiset just use less_equal
 
 
 
#define endl "\n"
// #define ll unsigned long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
using namespace chrono;
 
int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,-1,1};
 
const int N=2e5+10;
#define int long long int
#define pii pair<int,int>
#define all(arr) arr.begin(),arr.end()
#define fr first
#define sc second
#define pb push_back
const int mod=998244353;
// #define ull unsigned long long int
// const int mod=1e14+9;
const int INF=1e17;

int binExp(int a, int b, int mod){
	int ans=1;
	while(b>0){
		if(b&1ll)ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1ll;
	}
	return ans;
}


void solve(){
		int n; cin>>n;
		vector<double>arr(n);
		for(int i=0; i<n; i++)
			cin>>arr[i];
	
		int toys=0;
		
		auto f=[&](double mx)->void{
			int r=0;
			for(int l=0; l<n;){
				while(r<n && arr[r]-arr[l]<=2.0*mx){
					r++;
				}
				toys++;
				l=r;
			}
			return;
		};
		
		//for calculating min of maximum of all segment distance
		//dp[i] be minimised distance for toy allocation if 
		//first i elves are considered
		vector<double>dp(n+1,INF);
		dp[0]=0;
		for(int i=2; i<=n; i++){
			if(i>=2)
				dp[i]= min(dp[i],max(dp[i-2], arr[i-1]- (arr[i-1]+arr[i-2])/2.0));
			if(i>=3)
				dp[i]= min(dp[i],max(dp[i-3], arr[i-1]- (arr[i-1]+arr[i-3])/2.0));
		}
		// for(int i=0; i<=n; i++)cout<<i<<" "<<dp[i]<<endl;
		
		double ans= dp[n];
		f(ans);
		
		cout<<fixed<<setprecision(7);
		cout<<ans<<" "<<toys<<endl;
		return;
}


 
signed main(){
	#ifndef ONLINE_JUDGE
  		freopen("sigma.txt","r",stdin);
  		freopen("sigmaAC45.txt","w",stdout);
  	#endif 
  		
  	fastio();
    auto start1 = high_resolution_clock::now();
    int t=1;
    cin>>t;
    
  
    // precompute();
    int ct=1;
    while(t--){
    	// cout<<"Case #"<<ct++<<": ";
      solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cout << "Time: " << duration . count() / 1000 <<"ms"<<endl;
    #endif
  
  	return 0;
}
