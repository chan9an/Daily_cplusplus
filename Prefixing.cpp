#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int,int> count;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        vector<int> b;
        int m = *max_element(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            if(!count[a[i]])
            {
                b.push_back(a[i]);
            }
            else
            {
                b.push_back(m);
            }
            count[a[i]]++;
        }
        for(int i=0;i<b.size();i++)
        {
            cout << b[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
