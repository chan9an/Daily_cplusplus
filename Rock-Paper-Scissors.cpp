#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
 while (t--) {
        int n;
        cin >> n;
        int lol = 0;
        string inputStr;
        cin >> inputStr;
        vector<char>result(n,'p');
        int wins=n/2+1;
    for (int i = 0; i < n; i++) {
            if (inputStr[i] == 'R') {
                wins -=1;
            }}
         for (int i = n-1; i>=0; --i) {
            if (wins>0 && (inputStr[i]=='P'||inputStr[i]=='S')) {
               result[i]=(inputStr[i]=='P') ?'S':'R';
               wins -=1; } }
for(char c:result){
        cout<<c; }
    cout<<endl;}
    return 0;
}
