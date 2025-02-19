class Solution {
    public String gcdOfStrings(String str1, String str2) {
           int gcdLength = gcd(str1.length(), str2.length());

        // Get the potential GCD string
        String candidate = str1.substring(0, gcdLength);

        // Check if the candidate can construct both str1 and str2
        if (canConstruct(str1, candidate) && canConstruct(str2, candidate)) {
            return candidate;
        }

        return ""; // If no common divisor string found
    }

    // Helper function to calculate GCD
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Helper function to check if a string can be constructed by repeating a substring
    private boolean canConstruct(String str, String sub) {
        if (str.length() % sub.length() != 0) return false;
        StringBuilder repeated = new StringBuilder();
        for (int i = 0; i < str.length() / sub.length(); i++) {
            repeated.append(sub);
        }
        return repeated.toString().equals(str);
    
        
    }
}