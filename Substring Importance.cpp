//https://www.codechef.com/ZCOPRAC/problems/STRIMPOR?tab=statement

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    speedup
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        char s[n];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<int> start(n);
        vector<int> end(n);
        vector<int> x(3), z(3);
        for (int i = 0; i < n; i++){
            if (s[i] == 'X'){
                x[i%3]++;
            }else if (s[i] == 'Z'){
                end[i] = x[(i+1)%3];
            }
        }
        for (int i = n-1; i >= 0; i--){
            if (s[i] == 'Z'){
                z[i%3]++;
            }else if (s[i] == 'X'){
                start[i] = z[(i+2)%3];
            }
        }
        int cur = 0, ans = 0;
        for (int i = 0; i < k; i++){
            cur += start[i];
        }
        ans = cur;
        for (int i = k; i < n; i++) {
            cur += start[i];
            cur -= end[i-k];
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}
