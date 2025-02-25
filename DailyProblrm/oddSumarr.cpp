#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long countOdd = 0, countEven = 1; // Start with 1 to handle odd prefix sum cases
        long long prefixSum = 0, result = 0;

        for (int num : arr) {
            prefixSum += num;

            if (prefixSum % 2 == 0) {
                result = (result + countOdd) % MOD;
                countEven++;
            } else {
                result = (result + countEven) % MOD;
                countOdd++;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};
    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};

    cout << sol.numOfSubarrays(arr1) << endl; // Output: 4
    cout << sol.numOfSubarrays(arr2) << endl; // Output: 0
    cout << sol.numOfSubarrays(arr3) << endl; // Output: 16

    return 0;
}
