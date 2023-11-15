#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int start, end, mid;
    
    start = 0;
    end = nums.size() - 1;

    while (start <= end) {
        mid = start + (end - start) / 2;
        
        if (target < nums[mid])
            start = mid + 1;
        else
            end = mid - 1;
    } return start;
}

int main() {
	int N, wealth; 
    vector<int> sortedWealth;
    vector<int> ranks;
    int index;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> wealth;
        
        index = searchInsert(sortedWealth, wealth);
        sortedWealth.insert(sortedWealth.begin() + index, wealth);
        ranks.push_back(index + 1);
    }
    
    for (int rank: ranks)
        cout << rank << endl;

	return 0;
}
