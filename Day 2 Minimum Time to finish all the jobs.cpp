#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm> // For sort
using namespace std;

bool canDistributeHelper(vector<int>& jobs, int k, int maxWork, vector<int>& workers, int idx) {
    if (idx == jobs.size()) return true;
    for (int i = 0; i < k; ++i) {
        if (workers[i] + jobs[idx] <= maxWork) {
            workers[i] += jobs[idx];
            if (canDistributeHelper(jobs, k, maxWork, workers, idx + 1)) return true;
            workers[i] -= jobs[idx];
        }
        if (workers[i] == 0) break;
    }
    return false;
}

bool canDistribute(vector<int>& jobs, int k, int maxWork) {
    vector<int> workers(k, 0);
    return canDistributeHelper(jobs, k, maxWork, workers, 0);
}

int minimumTime(vector<int>& jobs, int k) {
    sort(jobs.rbegin(), jobs.rend()); // Sort jobs in descending order
    int left = jobs[0], right = accumulate(jobs.begin(), jobs.end(), 0), result = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canDistribute(jobs, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> jobs = {1, 2, 4, 7, 8};
    int k = 2;
    cout << "Minimum Time to Finish All Jobs: " << minimumTime(jobs, k) << endl;
    return 0;
}
