#include <bits/stdc++.h>
using namespace std;

void solve(){
   
    
    int l,r;cin>>l>>r;
    int n=r-l+1;
    if(n==1){
        cout<<-1;
        return ;
    }
    vector<int>v;
    int i=l;
    while(i<=r){
        v.push_back(i++);
    }
    
    // for(int i=0;i<n;i++)cout<<v[i]<<" * ";cout<<endl;
    
    for(int i=0;i+1<n;i+=2){
        
        swap(v[i],v[i+1]);
    }
    
    if(n>2 && n%2){
        swap(v[n-1],v[n-2]);
    }
    int flag=1;
    int k=l;
    for(int i=0;i<n;i++){
        if(__gcd(v[i],k)!=1){
            cout<<-1;
            return ;
        }
        k++;
    }
    // cout<<flag<<endl;
    for(int i=0;i<n;i++)cout<<v[i]<<" ";
    
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
}
