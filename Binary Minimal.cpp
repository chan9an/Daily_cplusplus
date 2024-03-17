#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    string s;
	    cin >> s;
	    vector<int> ind;
	    int cnt = 0;
	    for(int i =0; i<n; i++){
	        if(s[i] == '1')
	        {
	            cnt++;
	        }
	    }
	    if(cnt > k){
	        for(int i=0; i<n; i++)
	        {
	            if(s[i] == '1' && k>0)
	            {
	                s[i] ='0';
	                k--;
	            }
	        }
	        cout << s << endl;
	    }
	    else
	    {
	        for(int i=0; i <(n-k); i++)
	        {
	            cout << '0';
	        }
	        cout << endl;
	    }
	}
	return 0;

}
