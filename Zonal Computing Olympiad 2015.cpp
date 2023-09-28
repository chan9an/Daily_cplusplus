#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second){
        // added this if condition just to be safe but i think that it will still work without this if condition
        return p1.first <= p2.first;
    }
    return p1.second < p2.second; // sorting the pairs second element in ascending order
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i].first>>v[i].second;
    }
    // cnt stores the minimum COUNT of the nums we need to cover the intervals
    // stored 1 in cnt cuz if theres only 1 interval we only need 1 num to cover the interval
    int cnt = 1;
    // in cmp im sorting the pair's SECOND element in ASCENDING order
    // lets say "v" is : {{3,5}, {4,8}, {6,7}} after sorting "v" will look like this : {{3,5}, {6,7}, {4,8}}
    // u can see that the pairs SECOND elements are sorted in ascending order
    sort(v.begin(), v.end(), cmp);
    
/*  u might ask why I sorted the vector like that and why i didnt sort it normally(sorted from pairs first elem in ascending order)
    then let me give u an example:
    
    IF I SORTED NORMALLY (sorted from pairs first elem in ascending order)
    "v" is : {{4,8}, {5,6}, {7,8}}
    PICTORIAL:
         4     8
         •—————•
          5 6
          •—•
             7 8
             •—•
    now it will check that is 5 > 8, its not so it will not go inside the condition, cnt will be 1
    now i = 2 so, it will check is 7 > 8, its not so it will not go inside the condition, cnt will be 1
    after that the loop will be over so the cnt will be 1 and thats WRONG
----------------------------------------------------------------------------------------------------------------------------------------------------------
    IF I SORTED V PAIR'S SECOND ELEMENT IN ASCENDING ORDER (solution)
    "v" is : {{5,6}, {4,8}, {7,8}}
    PICTORIAL:
          5 6
          •—•
         4     8
         •—————•
             7 8
             •—•
    now it will check that is 4 > 6, its not so it will not go inside the condition, cnt will be 1
    now i = 2 so, it will check is 7 > 6, it is so it WILL go INSIDE the condition, cnt will be 2
    after that the loop will be over so the cnt will be 2 and its correct, when u sort pair's SECOND element in ASCENDING order u can find out which
    intervals have common elements and which intervals dont
    */
    int prevEnd = v[0].second;// stores the PREV second elem in the pair
    for(int i = 1; i < n; i++){ // i = 1 cuz already stored 1 in cnt so we HAVE to skip the first iteration
        int currStart = v[i].first;
        if(currStart > prevEnd){ // checking if they dont have any elems in common
            cnt++;
            prevEnd = v[i].second;
        }
        // if they have elems in common then no need to increase cnt
    }
    cout<<cnt;
    return 0;
}
