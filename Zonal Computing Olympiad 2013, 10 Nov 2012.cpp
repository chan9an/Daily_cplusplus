/*
Zonal Computing Olympiad 2013, 10 Nov 2012
N teams participate in a league cricket tournament on Mars, where each pair of distinct teams plays each other exactly once. Thus, there are a total of (N × (N-1))/2 matches. An expert has assigned a strength to each team, a positive integer. Strangely, the Martian crowds love one-sided matches and the advertising revenue earned from a match is the absolute value of the difference between the strengths of the two matches. Given the strengths of the N teams, find the total advertising revenue earned from all the matches.


For example, suppose N is 4 and the team strengths for teams 1, 2, 3, and 4 are 3, 10, 3, and 5 respectively. Then the advertising revenues from the 6 matches are as follows:


Thus the total advertising revenue is 23.


Input format
Line 1 : A single integer, N.

Line 2 : N space-separated integers, the strengths of the N teams.


Output format
A single integer, the total advertising revenue from the tournament.


Test data
In all subtasks, the strength of each team is an integer between 1 and 1,000 inclusive.
*/



#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
/*  v = {3, 4, 6}
    cuz of sorting we know that 3 will lose with 4,6
    4 will lose with 6 etc..  */
    long long ans = 0;
    for(int i = 0; i < n; i++){
/*     v = {3, 4, 6}
        _________________________
       | team1 | team2 | revenue |
       |—————————————————————————|
       |   3   |   4   | 4-3 = 1 |
       |   3   |   6   | 6-3 = 3 |
       |   4   |   6   | 6-4 = 2 |
        ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
       logic:
       in the revenue we're doing 4-3, 6-3, 6-4 so why dont we just add 4,6,6 to the ans FIRST and then subtract 3,3,4 from ans
       if u focus, u will notice that this method will also give us the correct answer
*/
        ans += v[i]*i; // "i" gives us how many times v[i] will win
    }
    for(int i = 0; i < n; i++){
        
        ans -= v[i] * (n-(i + 1)); 
    }
    cout<<ans;
    return 0;
}
