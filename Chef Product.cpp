#include <bits/stdc++.h>
using namespace std;


void solve()
{
     long long n;
     cin>>n;
     if(n==2){
        cout << 0 << endl;
        return;
     }
     if(n%2)
     cout  << ((((long long)(sqrtl(n)))+1)/2)<< endl;
     else{
        cout  << (((long long)(sqrtl(n))))/2 << endl;
     }

}

int main() {
	// your code goes here
	
	int T;
	cin>> T;
	
	while ( T ) {

	    solve();
	    
	    T--;
	}

}
