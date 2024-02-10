#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m,k,l,r;
	    cin>>n>>m>>k>>l>>r;
	    
	    int ans = INT_MAX;
	    while(n--){
	        int c,p;
	        cin>>c>>p;
	       // m[p] = c;
	       int temp = m;
	    while(temp--){
	        if(c<k-1){
	           c++; 
	        }
	        else if(c>k+1){
	            c--;
	        }
	        else if( c>=k-1 && c<=k+1){
	            c = k;
	        }
	       //  cout<<c<<" "<<k-1;
	    }
	            if(c>=l && c<=r){
	       // cout<<c<<" ";
	                ans = min(ans,p);
	            }
	        
	    }
	    if(ans==INT_MAX){
	        cout<<-1<<endl;
	    }
	    else{
	        
	    cout<<ans<<endl;
	    }
	
	    
	}

}
