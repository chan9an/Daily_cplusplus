
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
 #define int long long
const int MOD = 1e9 + 7;


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

//void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long  double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//Functions Start here

int  power(int  A, int  B)
{
    if (B == 0)
        return 1;
 
    int  res = (power(A, B / 2)%MOD);
 
    if (B % 2)
        return (res * res * A)%MOD;
    else
        return (res * res)%MOD;
}


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void SieveOfEratosthenes(int n)
{
   
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
}
    
//-----------------------TEMPLATE ENDS-----------------------
signed main(){
      ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
 #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    
  int t,s;
  cin>>t>>s;
  while(t--){
      
      int n;
      cin>>n;
      vector<int> vs(n);
      for(int i=0;i<n;i++)cin>>vs[i];
      
            
      sort(vs.begin(),vs.end());
      if(n==1){
          cout<<vs[0]<<endl;
          continue;
      }
      if(n==2){
          if(s==0)cout<<vs[1]<<endl;
          else cout<<vs[1]<<endl;
          continue;
      }
debug("for n "); debug(n);
      int sum =0;
      if(s==0){

          int nn = n/2;
          if(n%2!=0)nn++;
          debug(nn);
          if(n%2==0)
          for(int i=1;i<nn+1;i++){

              sum+= vs[i];
              debug(sum);
          }
          else
            for(int i=0;i<nn;i++){

              sum+= vs[i];
              
          }

      
          cout<<sum<<endl;


      }
      
      
      else{
          
          int s = n-1;   
             int range =1;
            vector<int> sumar(n+1,0);

            for(int i=1;i<=n;i++){
                sumar[i] = sumar[i-1] + vs[i-1]; 
            }

debug(sumar);
          while(s>=0){
              int ssum =0;
                debug(range);
                ssum = sumar[s+range] - sumar[s];
              // for(int i=0;i<range;i++){  
              //     // if(s-i <0)break;
              //     ssum+= vs[s+i];
              // }
              debug(ssum); debug(sum);
              sum = max(sum,ssum);
              s = s - 2;
              range++;
          }
          cout<<sum<<endl;
          
          
      }
      
      
  }



}


