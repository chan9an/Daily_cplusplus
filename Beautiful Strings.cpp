#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <climits>
// LLONG_MAX
using ll =long long;

int main() {
	ll t;
	
	cin>>t;
	
	while(t--){
	    ll n;
	    
	    cin>>n;
	    
	    string s;
	    
	    cin>>s;
	    
	    map<char,ll> m;
	    
	    for(int i=0;i<n;i++){
	        if(m.find(s[i]) != m.end()){
	            m[s[i]]++;
	        }
	        else{
	            m[s[i]]=1;
	        }
	    }
	    
	    ll ans=1;
	    
	    for(auto x:m){
	        ans= ans*(x.second+1)%1000000007;
	    }
	    
	    cout<<ans-1<<"\n";
	}
	return 0;
}
