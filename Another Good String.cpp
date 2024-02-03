#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int ans,count,i,t,n,u;
	char c,cc;
	string s;
	cin>>t;
	while(t--){
	    cin>>n>>u;
	    cin>>s;
	    ans=count=0;
	    cc=s[0];
	    for(i=0;i<n;i++){
	        if(s[i]==cc){
	            count++;
	            if(count>ans) ans=count;
	        }
	        else{
	            count=1;
	            cc=s[i];
	        }
	    }
	    cout<<ans<<" ";
	    for(i=0;i<u;i++){
	        cin>>c;
	        if(cc==c){
	            count++;
	            if(count>ans) ans=count;
	        }
	        else{
	            cc=c;
	            count=1;
	        }
	        cout<<ans<<" ";
	    }
	    cout<<endl;
	}
}
