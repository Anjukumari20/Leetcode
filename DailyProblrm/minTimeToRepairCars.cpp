class Solution {
    public:
        long long repairCars(std::vector<int>& ranks, int cars) {
            long long left = 1, right = 1LL * ranks[0] * cars * cars;
            
            auto canRepair = [&](long long time) {
                long long totalCars = 0;
                for (int rank : ranks) {
                    totalCars += static_cast<long long>(std::sqrt(time / rank));
                    if (totalCars >= cars) return true;
                }
                return totalCars >= cars;
            };
            
            while (left < right) {
                long long mid = left + (right - left) / 2;
                if (canRepair(mid)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            return left;
        }
    };