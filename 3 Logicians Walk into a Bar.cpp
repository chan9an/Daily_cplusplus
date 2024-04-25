# include <iostream>
# include <queue>
# include <stack>
# include <vector>
# include <deque>
# include <utility>
# include <algorithm>
# include <set>
# include <map>
# include <unordered_set>
# include <unordered_map>
# include <math.h>
# include <cmath>
# include <iomanip>
# include <climits>
using namespace std;

# define ll long long
# define pll pair<long long, long long>
# define vll vector<long long>
# define omll ordered_map<long long, long long>
# define umll unordered_map<long long, long long>
# define umcl unordered_map<char, long long>
# define mod 1000000007

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t = 0;
	cin >> t;
	while (t--) {
	    ll n = 0;
	    cin >> n;
	    string input = "";
	    cin >> input;
	        
	    ll count_1 = 0;
	    bool no = false;
	    for (ll i = 0; i < n; i++) {
	        count_1 += (input[i] == '0' ? 0 : 1);
	        if (i == n - 1 and input[i] == '1' and count_1 == n)
	            cout << "YES" << endl;
	        else if (input[i] == '0' and !no) {
	            cout << "NO" << endl;
	            no = true;
	        }
	        else if (no)
	            cout << "NO" << endl;
	        else
	            cout << "IDK" << endl;
	    }
	        
	}
}
