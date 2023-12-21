nt minCandy(int N, vector<int> &ratings) {
        // code here
        vector<int> left(N, 1);
        vector<int> right(N, 1);

        // Traverse from left to right
        for (int i = 1; i < N; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // Traverse from right to left
        for (int i = N - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        int totalCandies = 0;
        for (int i = 0; i < N; i++) {
            totalCandies += max(left[i], right[i]);
        }

        return totalCandies;
    }
