#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	
	int t;cin>>t;
	while(t--){
	    int n;string p,c; cin>>n>>p>>c;
	    
	    
	    for(int i=0;i<n;i++){
	        int s=p[i]-'A';
	        int e=c[i]-'A';
	        
	        if(s>e) e+=26;
	        
	        cout<<((e-s)%3)*9+(e-s-(e-s)%3)/3<<" ";
	    }
	    cout<<endl;
	    
	}

}
