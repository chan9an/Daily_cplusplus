#include<bits/stdc++.h>
using namespace std;
int main()
     int arr[]= {5, 1, 2, 5, 1, 7};
     set<int> d;
     int n  = sizeof(arr)/sizeof(arr[0]);
     for(int i = 0;i <n;i++){
        d.insert(arr[i]);
     }
     int p = d.size();
     cout<<d.size()<<endl;
     cout<<d.crbegin()<<endl; 
     for(auto k : d){
        cout<<k<<" ";
     }
