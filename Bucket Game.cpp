#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i =0;i<n;i++) cin>>arr[i];
        int ap=0;
        int bp=0;
        int c1=0;
        int c2=0;
        int sum=0;
        for(auto i : arr){
            if(i==1){
                c1++;
            }else{
                sum+=(i-2);
                c2++;
            }
        }
        string turn = "alice";
        if(c1>0){
            if(c1&1){
                ap+=((c1+1)/2);
                bp+=(c1/2);
                turn = "bob";
            }else{
                ap+=(c1/2);
                bp+=(c1/2);
                turn = "alice";
            }
        }
        if(sum&1){
           if(turn == "alice"){
               turn = "bob";
           }else{
               turn = "alice";
           }
        }
        if(turn == "alice") bp+=(c2);
        else ap+=(c2);
        if(ap>bp){
            cout<<"Alice"<<endl;
        }else if(bp>ap){
            cout<<"Bob"<<endl;
        }else{
            cout<<"Draw"<<endl;
        }
        
     
    }
}
