#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

int maxHappyGroups(int batchSize, vector<int>& groups) {
    vector<int> remainders(batchSize, 0);

    // Calculate remainders
    for (int group : groups) {
        remainders[group % batchSize]++;
    }

    // Groups perfectly divisible by batchSize are happy
    int result = remainders[0];

    // Pair remainders to form happy groups
    for (int i = 1, j = batchSize - 1; i < j; ++i, --j) {
        int pairs = min(remainders[i], remainders[j]);
        result += pairs;
        remainders[i] -= pairs;
        remainders[j] -= pairs;
    }

    // Handle the middle remainder (for even batch sizes)
    if (batchSize % 2 == 0) {
        result += remainders[batchSize / 2] / 2;
        remainders[batchSize / 2] %= 2;
    }

    // Use memoization for the DFS to maximize happy groups
    unordered_map<string, int> memo;

    function<int(vector<int>&)> dfs = [&](vector<int>& rem) {
        string state;
        for (int r : rem) state += to_string(r) + ",";
        if (memo.count(state)) return memo[state];

        int maxHappy = 0;
        for (int i = 0; i < batchSize; ++i) {
            if (rem[i] > 0) {
                rem[i]--;
                int extraHappy = (i == 0 ? 1 : 0);
                maxHappy = max(maxHappy, dfs(rem) + extraHappy);
                rem[i]++;
            }
        }
        return memo[state] = maxHappy;
    };

    return result + dfs(remainders);
}

int main() {
    int batchSize = 4;
    vector<int> groups = {1,3,2,5,2,2,1,6};
    cout << "Maximum Happy Groups: " << maxHappyGroups(batchSize, groups) << endl;

    return 0;
}
