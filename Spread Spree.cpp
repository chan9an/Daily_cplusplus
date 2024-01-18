#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	 while(t--){
	     int n, m;
	     cin  >> n >> m;
	     if( n > m){
	         int temp =n;
	         n =m;
	         m = temp;
	     }
	     if( m % 2 == 1){
	         long k = m/2;
	         long r = max(( long)1, n-k);
	         long  b = min ( ( long)n, k+1);
	          r--;
	         long long s1 = (b*(b+1))/2;
	         long long s2 = (r*(r+1))/2;
	         cout << (((k+1)%(998244353))*((s1-s2)%(998244353)))%(998244353) << endl;
	     }
	     else{
	       //  int k = m/2;
	         long k = m/2;
	         long k1 = k, k2 = k+1;
	         long r = max(( long)1, n-k);
	         long  b = min ( ( long)n, k+1);
	          r--;
	         long long s1 = (b*(b+1))/2;
	         long long s2 = (r*(r+1))/2;
	       //  cout << ((k1+k2)*(s1-s2))%998244353<<endl;
	         cout << (((k1+k2)%(998244353))*((s1-s2)%(998244353)))%(998244353) << endl;
	     }
	 }

}
