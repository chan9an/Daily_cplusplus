#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() 
{
	// your code goes here
    /**int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        
        if(n%2==0)
        {
            n/=2;
            cout<<((n+1)*n);
        }
        else
        {
            long long int x=n;
            n/=2;
            cout<<(n*(n+1))+(n+1)<<endl;
        }
    }
    **/
    
   ll t;
   cin>>t;
   while(t--)
   {
	   ll n ;
	   cin >> n;
	   if(n%2==0){
	       n/=2;
	       cout<<(n*(n+1))<<endl;
	   }else{
	       ll x = n;
	       n/=2;
	       cout<<(n*(n+1))+(n+1)<<endl;
	   }
	   
	    
   }
   return 0;
 }
    
