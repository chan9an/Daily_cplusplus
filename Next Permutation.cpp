#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n,t;cin>>n>>t;
	while(t--){
	    vector<int> v;
	    for(int i=0;i<n;i++){
	        int a;cin>>a;
	        v.push_back(a);
	    }
	    next_permutation(v.begin(),v.end());
	    for(auto i:v){
	        cout<<i<<" ";
	    }
	        cout<<"\n";
	    }
	return 0;
}
