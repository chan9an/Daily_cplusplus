#include <bits/stdc++.h>
#define int long long
#define uint unsigned long long
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL)
#define vi vector<int>
#define vvi vector<vi >
#define vc vector<char>
#define vvc vector<vc >
#define mii map<int , int>
#define pii pair<int , int>
#define vb vector<bool>
#define vvb vector<vb >
#define pb push_back
#define pp pop_back
#define ff first
#define ss second
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 

using namespace std;
int MOD=998244353;      // Hardcoded, directly change from here for functions!

const int MX_SZ=1e5+5;
int par[MX_SZ];

void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

constexpr int N = 200005; // No. of vertices
constexpr int L = 20; // ceil(logN / log2) + 1

int powe(int x, int y){
	int ans=1;
	while(y>0){
		if(y&1){
			ans = (ans*x)%MOD;
		}
		y >>= 1;
		x = (x*x)%MOD;
	}
	return ans%MOD;
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
        
    int ans = 0;
    for(int i=1;i<n;i++){
        ans = (ans + powe(abs(a[i] - a[0]) , 7) * powe(2 , n-i-1)) % MOD;   
    }
    
    cout << ans << endl;
}

int32_t main()
{
	FAST;

    int T;
    cin >> T;
    for (int i=1;i<=T;i++)
    {
        // cout << "Case #" << i << ": " << endl;
        solve();
    }
    return 0;
}
