/*
There are C cakes in a row, numbered from 1 to C. There are N children, each of whom have selected a consecutive set of cakes to eat. That is, Child i has decided to eat all the cakes from Si to Ei, end points inclusive. If there is a cake which appears in some two childrens' set, then they will fight because both of them want to eat that cake, and you don't want that to happen.

You will be given an integer K which will be either 0 or 1. If K is 0, then you should find out if some two children will fight. Print "Good" if no one fights, and "Bad" if someone fights.

If K is 1, then you can persuade at most one child to change his decision to some other set of cakes. But the number of cakes that he eats must be the same. That is, if Child i had initially decided that he wants to eat the cakes from Si to Ei, then you could persuade the child to instead eat the cakes from X to Y instead, for any valid X and Y (ie. 1 ≤ X ≤ Y ≤ C), provided that the number of cakes is the same (ie. Ei - Si + 1 = Y - X + 1). If after persuading at most 1 Child to change his decision, no fights happen, then print "Good". But if no matter what you do, someone will fight, then print "Bad".

Input
The first line of the input contains an integer T denoting the number of test cases. The description of each test case follows.

The first line of each test case contains three integers C, N and K denoting the number of cakes, number of children and K, respectively.

The i-th of the next N lines contains two space separated integers Si and Ei which denotes the initial decision of Child i. That is, Child i wants to eat from cake Si to cake Ei.

Output
For each test case, output a single line containing "Good" or "Bad".


*/


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
pair <int, int> ar[N];
int main(){
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int c, n, k;
        cin >> c >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> ar[i].first >> ar[i].second;
        }
        sort (ar + 1, ar + n + 1);
        if (!k) {
            bool f = 1;
            for (int i = 2; i <= n; i++) {
                if (ar[i].first <= ar[i - 1].second) {
                    f = 0;
                    break;
                }
            }
            if (f)
                cout << "Good\n";
            else
                cout << "Bad\n";
        }
        else {
            int max_range = ar[1].first - 1;
            int maxv = ar[1].second;
            for (int i = 2; i <= n; i++) {
                max_range = max (ar[i].first - 1 - ar[i - 1].second, max_range);
                maxv = max (ar[i].second, maxv);
            }
            max_range = max (max_range, c - maxv);
            
            bool f = 1, ff = 1;
            for (int i = 2; i <= n; i++) {
                if (ar[i].first <= ar[i - 1].second) {
                    if (f) {
                        int a, b, c, d;
                        if (ar[i].second >= ar[i - 1].second) {
                            a = ar[i].first;
                            b = ar[i].second;
                            c = ar[i - 1].first;
                            d = ar[i - 1].second;
                        }
                        else {
                            a = ar[i - 1].first;
                            b = ar[i - 1].second;
                            c = ar[i].first;
                            d = ar[i].second;
                        }
                        if (b - a + 1 <= max_range) {
                            f = 0;
                            if (b == ar[i].second)
                                ar[i].second = ar[i - 1].second;
                        }
                        else if (d - c + 1 <= max_range) {
                            f = 0;
                            if (d == ar[i].second)
                                ar[i].second = ar[i - 1].second;
                        }
                        else {
                            f = ff = 0;
                            break;
                        }
                    }
                    else {
                        ff = 0;
                        break;
                    }
                }
            }
            if (ff)
                cout << "Good\n";
            else
                cout << "Bad\n";
        }
    }
}
