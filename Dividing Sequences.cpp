
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// 2 3 6 4 7 8 90 48
// 3 2 1 2 0 1 0  0
// maxi=3
//res=4

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
       int n;cin>>n; 
       int a[n];
       int seq_count[n]={0};
       int result=0;
       for(int i=0;i<n;i++){
           cin>>a[i];
       }
       for(int i=n-2;i>=0;i--){
           int maxi=0;
           for(int j=n-1;j>i;j--){
               if(a[j]%a[i]==0){
                  maxi=max(maxi,seq_count[j]+1);
               }
           }
           seq_count[i]=maxi;
           result=max(result,maxi+1);
       }
       cout<<result;
    // your code goes here
    return 0;
}
