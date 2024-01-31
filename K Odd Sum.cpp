#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
      if(k&1){
        for(int i=k+2;i<=n;i++){
          if (i&1)
          {
            cout<<i<<" ";
          }
          
        }
        for (int i = 1; i <=k+1; i++)
        {
          cout<<i<<" ";
        }
          for(int i=k+2;i<=n;i++){
          if (i%2==0)
          {
            cout<<i<<" ";
          }
          
        }
        
      }
      else{
         
        for (int i = 1; i <=k; i++)
        {
          cout<<i<<" ";
        }
          for(int i=k+2;i<=n;i++){
          if (i%2==0)
          {
            cout<<i<<" ";
          }
          
        }
      for(int i=k+1;i<=n;i++){
          if (i&1)
          {
            cout<<i<<" ";
          }
          
        }
      }
	    cout<<endl;
	}

}
