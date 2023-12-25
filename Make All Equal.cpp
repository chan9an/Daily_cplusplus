#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll>v(n);
    for(ll i = 0 ; i< n ; i++){
    cin>>v[i];
    }
    ll  maxi =  *max_element(v.begin(), v.end());
    ll  mini =  *min_element(v.begin(), v.end());
    ll count = 0 ;
    for(int i = 0 ; i<n ; i++){
       count += (maxi -v[i]);
    }
    ll ans = max(maxi-mini, (count +  (m-1))/m);
    cout<<ans<<endl;
}


int  main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
