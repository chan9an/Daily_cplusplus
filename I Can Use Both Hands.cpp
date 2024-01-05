#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int tc;
    cin >> tc;
    for(int i=0;i<tc;i++) {
        int l,r,m;
        cin >> l >> r >> m;
        int ans=m/l+m/r;
        if(m%l) {
            ans++;
        }
        cout << ans << endl;
    }
	return 0;
}
