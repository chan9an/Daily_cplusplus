#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

 
typedef long double ld;
typedef long long ll;
#define mod 1000000007
#define mod1 998244353
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>;
//#define ordered_set tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
 
const int N = 200;
 
 
 
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
bool isPrime(ll n){if(n <= 1)return false;if(n <= 3)return true;if(n%2 == 0 || n%3 == 0)return false;for(ll i=5; i*i<=n; i=i+6)if(n%i == 0 || n%(i+2) == 0)return false;return true;}
ll nextPrime(ll N){if(N<=1)return 2;ll prime = N;bool found = false;while(!found){prime++;if(isPrime(prime))found=true;}return prime;}
//ll fact(ll n){if(n==1) return 1;return  n* fact(n-1);}
ll cl(ll n,ll d){return (n+d-1)/d;} 
ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);}
ll lcm(ll a,ll b){return (a*b)/(gcd(a,b));}
 
 
typedef long double ld;
//typedef long long ll;
 
ll Pow(ll x, ll n) {
  long long ans = 1;
  long long xx=x;
  while (n) {
    if (n & 1)
      ans=(ans*xx);
    xx=(xx*xx);
   
    n >>= 1;
  }
  return ans;
}
 
 
 
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
void nl(ll x){
 cout<<x<<"\n";
}
 
void nl(ll x , ll y){
  cout<<x<<" "<<y<<"\n";
}
 
void yes(){
  cout<<"YES\n";
}
 
void no(){
  cout<<"NO\n";
}
 
void nva(vector<ll>v,ll i,ll n){
 for(ll j=i;j<i+n;j++){
  cout<<v[j]<<" ";
 }
 cout<<"\n";
}
 
void nv(vector<ll>v){
  for(ll x : v){
    cout<<x<<" ";
  }
  cout<<"\n";
}
 
void na(ll arr[],ll i,ll n){
   for(ll j=i;j<i+n;j++){
  cout<<arr[j]<<" ";
 }
 cout<<"\n";
}
 
void sp(){
  cout<<" ";
}
//odd , even , brute force ko dekho
//gcd , prime facorization kabhi bhi lag skta h dhyaan do lcm ko bhi dekhlo
//x1+x2+...x2m=n solutions are (n+2m-1)!/(2m)!(n-1)!
//ho skta h dsu lage
//ho skta h constraint chote ho kuch mil sake
//multiple or single multiset priority queue dhyaan rakh
//binary search , apna wala brute o(n) wala
//dp loop wali memozisation 
//ll dp[1005][1005];








void solve(){
  ll n,m,i,j,k;
  cin>>n>>m;
  ll a[n][m];
  for(i=0;i<n;i++){
    for(j=0;j<m;j++)cin>>a[i][j];
  }
  vector<ll>fin(31);
  vector<vector<ll>>r(n,vector<ll>(31,0)),c(m,vector<ll>(31,0));
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        for(k=0;k<30;k++){
           if((a[i][j]&(1<<k))){
               r[i][k]++;
           }
        }
    }
    for(j=0;j<31;j++){
      fin[j]+=r[i][j];
    }
  }
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        for(k=0;k<30;k++){
           if((a[j][i]&(1<<k))){
               c[i][k]++;
           }
        }
    }
    debug(c[i],i);
  }
  debug(fin);
  ll ans = 0;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      vector<ll>tmp=fin;
      ll anss = 0;
      for(k=0;k<30;k++){
        tmp[k]-=r[i][k];
        tmp[k]-=c[j][k];
        if((a[i][j]&(1<<k))){
          tmp[k]++;
        }
        if((a[i][j]&(1<<k))){
           ll fre = (n*m)-(n+m-1)-tmp[k];
           ll val = Pow(2,k);
           debug(fre,val,'1');
           anss=anss+(fre*val); 
        }
        else{
          ll fre = tmp[k];
          ll val = Pow(2,k);
          debug(fre,val,'0');
          anss=anss+(fre*val);
        }
      }
      debug(anss,a[i][j],tmp);
      ans=max(ans,anss);
    }
  }
  nl(ans);
}

 
  
int main()
{
     fastio;
  #ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
 
freopen("output.txt", "w", stdout);
 
freopen("error.txt", "w", stderr);
#endif 
 
     ll t;
    cin>>t;
    
    //t=1;
    
     while(t--)
     {
         
         solve();
      
     }
     
    return 0;
}
