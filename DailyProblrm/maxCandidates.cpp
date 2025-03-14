class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            long long left = 1, right = *max_element(candies.begin(), candies.end());
            int result = 0;
            
            auto canDistribute = [&](long long mid) {
                long long count = 0;
                for (int c : candies) {
                    count += c / mid;
                }
                return count >= k;
            };
            
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                if (canDistribute(mid)) {
                    result = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            return result;
        }
    };
    