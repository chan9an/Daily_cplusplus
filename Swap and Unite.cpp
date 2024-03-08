#include <bits/stdc++.h>

using namespace std;

void ans()
{
    string s;
    cin >> s;
    int n = s.size();
    int minSwaps = 1e9;
    unordered_map < char, int > mp;
    for (auto it: s) mp[it]++;
    for (auto it: mp)
    {
        char c = it.first;
        int tf = it.second;
        vector<int> prefix(n);
        int f = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c) f++;
            prefix[i] = f;
        }
        int si = 0, ei = 0;
        while (ei < n)
        {
            int size = ei - si + 1;
            if (size < tf) ei++;
            else
            {
                int f;
                if(si==0) f = prefix[ei];
                else f=prefix[ei]-prefix[si-1];
                // cout<<f<<" ";
                int swaps = tf - f;
                minSwaps = min(swaps, minSwaps);
                si++;
                ei++;
            }
        }
    }
    cout << minSwaps << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ans();
    }
    return 0;
}
