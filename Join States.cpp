#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
	    int n,m;cin>>n>>m;
	    int arr[n];
	    for(int i=0;i<n;i++)cin>>arr[i];
	    int s=0,count=0;
	    for(int i=0;i<n;i++){
	        s+=arr[i];
	        if(s>=m){
	            count++;
	            s=0;
	        }
	    }
	    cout<<count<<'\n';
	}

}
