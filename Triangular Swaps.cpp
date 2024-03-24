
#include <bits/stdc++.h>
using namespace std;
void distStrings(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=n-2;
    int chk=0;
for(int i=0;i<s.size()-2;i++){
       if( i<n-3 && s[i]==s[i+1] && s[i+1]!=s[i+2] && s[i+1]==s[i+3]){
           ans--;
       }
     
       if( s[i]==s[i+1] && s[i+1]==s[i+2] ){
           ans--;
           chk=1;
           
       }
}
cout<<ans+chk<<endl;

}

int main() {
	// your code goes hereint main() {
    int t;
    cin>>t;
    while(t--){
    distStrings();
    }

    return 0;
}

