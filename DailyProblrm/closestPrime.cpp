class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
                 const int MAX = 1e6;
            vector<bool> isPrime(MAX + 1, true);
            isPrime[0] = isPrime[1] = false;
    
            // Sieve of Eratosthenes to find all primes up to MAX
            for (int i = 2; i * i <= MAX; i++) {
                if (isPrime[i]) {
                    for (int j = i * i; j <= MAX; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
    
            vector<int> primes;
            for (int i = left; i <= right; i++) {
                if (isPrime[i]) {
                    primes.push_back(i);
                }
            }
    
            // If less than two primes exist, return [-1, -1]
            if (primes.size() < 2) return {-1, -1};
    
            // Find the closest prime pair
            int minDiff = INT_MAX;
            vector<int> ans = {-1, -1};
            for (size_t i = 1; i < primes.size(); i++) {
                int diff = primes[i] - primes[i - 1];
                if (diff < minDiff) {
                    minDiff = diff;
                    ans = {primes[i - 1], primes[i]};
                }
            }
    
            return ans;
        }
    };