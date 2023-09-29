#include <bits/stdc++.h>



using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    unordered_set<int> s(n); // did set cuz in the for loop im doing find function and in sets it gives the answer in O(1)
    for(int i = 0; i < n; i++){
        cin>>v[i];
        s.insert(v[i]);
    }
    // sorted cuz we dont want the diff to be negative
    sort(v.begin(), v.end());
    int maxCnt = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int diff = v[j]-v[i];
            int cnt = 2; // cnt is 2 cuz v[j] and v[i] are also bamboos
            int nextElem = v[j]+diff;
            while(s.find(nextElem) != s.end()){
                cnt++;
                nextElem = nextElem+diff;
            }
            maxCnt = max(maxCnt, cnt);
        }
    }
    cout<<maxCnt;
    return 0;
}
