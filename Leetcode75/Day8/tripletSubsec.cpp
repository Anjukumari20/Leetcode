#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int num : nums) {
            if (num <= first) {
                first = num; // Smallest element so far
            } else if (num <= second) {
                second = num; // Second smallest element
            } else {
                return true; // Found a triplet
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {5, 4, 3, 2, 1};
    vector<int> nums3 = {2, 1, 5, 0, 4, 6};

    cout << boolalpha;
    cout << "Test Case 1: " << sol.increasingTriplet(nums1) << endl; // Output: true
    cout << "Test Case 2: " << sol.increasingTriplet(nums2) << endl; // Output: false
    cout << "Test Case 3: " << sol.increasingTriplet(nums3) << endl; // Output: true

    return 0;
}
