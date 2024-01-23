#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    long long int t;
	cin>>t;
	while(t--){
	   long long int n;
	   bool ch=false;
	    cin>>n;
	    string s;
	    cin>>s;
	    int i, j;
	    for( i=0;i<n-1;i++){
	        if(s[i]>s[i+1]){
	            j=i;
	            ch=true;
	            break;
	        }
	       // else if(s[i]<s[i+1]){
	       //     j=i+1;
	       //     break;
	       // }
	    }
	   // if(i=n-1) j=n-1;
	   if(ch==true){
	    for(int k=0;k<n;k++){
	        if(j!=k){
	            cout<<s[k];
	        }
	    }}
	    else{
	        for(int k=0;k<n-1;k++){
	       
	            cout<<s[k];
	    
	    
	}
	

}
	    cout<<endl;
	}}
