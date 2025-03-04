class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while (n > 0) {
                if (n % 3 == 2) return false; // If any ternary digit is '2', it's invalid
                n /= 3;
            }
            return true;
        }
    };