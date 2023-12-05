#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> traffic(N + 1);
    for (int i = 1; i <= N; ++i) {
        std::cin >> traffic[i];
    }

    std::vector<std::vector<int>> graph(N + 1);

    for (int i = 1; i < N; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(2, 0));

    std::function<void(int, int)> dfs = [&](int node, int parent) {
        dp[node][0] = 0;
        dp[node][1] = traffic[node];

        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node);
                dp[node][0] += std::max(dp[neighbor][0], dp[neighbor][1]);
                dp[node][1] += dp[neighbor][0];
            }
        }
    };

    dfs(1, 0);

    long long ans = std::max(dp[1][0], dp[1][1]);
    std::cout << ans << "\n";

    return 0;
}
