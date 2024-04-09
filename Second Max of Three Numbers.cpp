#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vector<int> numbers={a,b,c};
        sort(numbers.begin(),numbers.end());
        cout<<numbers[1]<<endl;
    }
    return 0;
	// your code goes here

}
