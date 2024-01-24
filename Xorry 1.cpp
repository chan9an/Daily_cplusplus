// Rohan Agrawal
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int t;
	cin>>t;
	while(t--){
	    int r;
	    cin>>r;
	   
	       int v = 1;
	       int count = 0;
	       while(r>=v){
	           v = v<<1;
	           count++;
	       }
	       int b = pow(2,count-1);
	       cout<<r-b<<" "<<b<<endl;
	   
	}

}
