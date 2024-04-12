#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int test_cases;
    cin >> test_cases;
    
    while (test_cases--) {
        int length, pairs;
        cin >> length >> pairs;
        
        int arr1[pairs], arr2[pairs];
        for (int i = 0; i < pairs; i++)
            cin >> arr1[i];
        for (int i = 0; i < pairs; i++)
            cin >> arr2[i];

        if (length % 2 == 0) {
            vector<int> freq(length + 2, 0);
            for (int i = 0; i < pairs; i++) {
                if (arr1[i] < arr2[i]) {
                    arr2[i] = min(arr2[i], arr1[i] + length / 2);
                } else {
                    int calculated = arr1[i] + (length / 2);
                    arr2[i] = min(arr2[i] + length, calculated);
                    arr2[i] = (arr2[i] % length != 0) ? arr2[i] % length : length;
                }
                if (arr1[i] < arr2[i]) {
                    freq[arr1[i]]++;
                    freq[arr2[i]]--;
                } else {
                    freq[arr1[i]]++;
                    freq[1]++;
                    freq[arr2[i]]--;
                }
            }
            int max_val = 0;
            for (int i = 1; i < length + 2; i++) {
                freq[i] += freq[i - 1];
            }
            for (int i = 1; i <= length / 2; i++) {
                max_val = max(max_val, freq[i] + freq[i + length / 2]);
            }
            cout << max_val << endl;
        } else {
            length = 2 * length;
            vector<int> freq(length + 2, 0);
            for (int i = 0; i < pairs; i++) {
                arr1[i] = 2 * arr1[i] - 1;
                arr2[i] = 2 * arr2[i] - 1;
                if (arr1[i] < arr2[i]) {
                    arr2[i] = min(arr2[i], arr1[i] + length / 2);
                } else {
                    int calculated = arr1[i] + (length / 2);
                    arr2[i] = min(arr2[i] + length, calculated);
                    arr2[i] = arr2[i] % length;
                    if (arr2[i] == 0) {
                        arr2[i] = length;
                    }
                }
                if (arr1[i] < arr2[i]) {
                    freq[arr1[i]]++;
                    freq[arr2[i]]--;
                } else {
                    freq[arr1[i]]++;
                    freq[1]++;
                    freq[arr2[i]]--;
                }
            }
            int max_val = 0;
            for (int i = 1; i < length + 2; i++) {
                freq[i] += freq[i - 1];
            }
            for (int i = 1; i <= length / 2; i++) {
                max_val = max(max_val, freq[i] + freq[i + length / 2]);
            }
            cout << max_val << endl;
        }
    }
    return 0;
}
