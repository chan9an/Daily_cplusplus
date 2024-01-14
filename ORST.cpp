#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int A[n];
        int B[m];

        for (int i = 0; i < n; i++)
            cin >> A[i];
        
        for (int i = 0; i < m; i++)
            cin >> B[i];

        sort(B, B + m);
        sort(A + (n - B[m - 1]), A + n);

        for (int i = 0; i < n; i++)
            cout << A[i] << " ";
        
        cout << endl;
    }

    return 0;
}
