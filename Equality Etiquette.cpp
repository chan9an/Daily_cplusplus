#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;

        if (a == b) {
            cout << "0" << endl;
            continue;
        }

        ll diff = abs(b - a);
        ll ans = -1;

        ll val = diff * 2;
        val = sqrt(val);

        for (ll i = val; i <= val + 5; i++) {
            ll cur = i * (i + 1) / 2;
            ll extra = cur - diff;

            if (extra < 0) {
                continue;
            }

            if (extra % 2 != 0) {
                continue;
            } else {
                ans = i;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
