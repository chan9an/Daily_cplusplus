#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> permutation(N + 1);     // +1 to make indexing 1-based
    for (int i = 1; i <= N; ++i)  cin >> permutation[i];
    

    vector<bool> visited(N + 1, false);
    int cycleCount = 0;
    for (int i = 1; i <= N; ++i) 
    {
        if (!visited[i]) 
        {
            cycleCount++;
            int current = i;

            while (!visited[current]) 
            {
                visited[current] = true;
                current = permutation[current];
            }
        }
    }

    cout<<cycleCount<< endl;

    visited.assign(N + 1, false);
    for (int i = 1; i <= N; ++i) 
    {
        if (!visited[i]) 
        {
            int current = i;
            cout << current << " ";

            while (!visited[current]) 
            {
                visited[current] = true;
                current = permutation[current];
                std::cout << current << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
