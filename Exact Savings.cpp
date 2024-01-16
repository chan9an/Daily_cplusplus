#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define f(i,s,e) for (int (i)=(s);(i)<(e);++(i))
#define rep(i,n) f(i,0,n)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll helper(ll indx, ll chck, vector<ll>&arr, ll modu, vector<vector<ll>>&dp, ll x){

    if(modu==chck){
        return 0;
    }

    if(indx>=sz(arr)){
        return 1e14;
    }


    if(dp[indx][modu]!=-1){
        return dp[indx][modu];
    }


    ll take = arr[indx]+helper(indx+1,chck,arr,(modu+arr[indx])%x, dp,x);
    ll not_take = helper(indx+1,chck,arr,modu,dp,x);

    return dp[indx][modu]= min(take,not_take);

}

void solve(){

    ll n,x,z;
    cin>>n>>x>>z;

    vector<ll>arr(n);

    rep(i,n){
        cin>>arr[i];
    }

    if(z%x==0){
        cout<<z/x <<'\n';
        return;
    }


    ll tm_ext = (z)/x ;
    ll temp = z%x;
    ll left = x-temp;

    debug(left);

    vector<vector<ll>>dp(n,vector<ll>(x+1,-1));


    ll ans=helper(0,left,arr,0,dp,x);

    if(ans==1e14){
        cout<<"-1" <<'\n';
    }
    else{
        ll pp = tm_ext+ (ans+temp)/x ;
        cout<<pp <<'\n';
    }

    
}   


int main() {
    
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

}
