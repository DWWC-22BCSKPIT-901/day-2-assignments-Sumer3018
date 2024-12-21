#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int k = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}

int main() {
    vector<int> nums = {1, 1, 2};
    int newLength = removeDuplicates(nums);

    cout << "New Length: " << newLength << endl;
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}
