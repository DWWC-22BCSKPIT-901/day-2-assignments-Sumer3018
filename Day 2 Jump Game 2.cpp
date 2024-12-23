#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums) {
    int jumps = 0, farthest = 0, currentEnd = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        farthest = max(farthest, i + nums[i]);
        if (i == currentEnd) {
            ++jumps;
            currentEnd = farthest;
        }
    }
    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    int minJumps = jump(nums);

    cout << "Minimum Jumps: " << minJumps << endl;
    return 0;
}
